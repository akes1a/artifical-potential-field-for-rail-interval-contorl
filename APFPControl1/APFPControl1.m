clear all
clc
%% 导入数据
dataPrediction=load('ypredLLDD5.txt');
dataTrue=load("13.txt");
load RBD.mat
%% km/h转换为m/s
dataTrueList=kmh2ms(dataTrue);
dataPreList=kmh2ms(dataPrediction');
%% 由速度求取里程
dataTrueMileage=velocity2mileage(dataTrueList);
dataPreMileage =velocity2mileage(dataPreList);
figure(1);
plot(dataPreMileage);
hold on
plot(dataTrueMileage);
hold on 
legend('Actual Value','Predited Result');
ylabel('Mileage(m)');
xlabel('Qty(0.1s)')

%% 提取特征(如果不进行协同控制，仅缩小时间间隔)
dataTrueAcceleration=diff(dataTrueList);
dataPreAcceleration=diff(dataPreList);
dataFollower=[zeros(1,80) dataTrueList zeros(1,200)];% 跟随车的轨迹是真实车的轨迹在时域上的平移
dataLeader=[dataPreList];% 领航车的轨迹是预测的轨迹
dataFollowerMileage=velocity2mileage(dataFollower);
dataLeaderMileage=velocity2mileage(dataLeader);
figure(2)
plot(dataFollowerMileage);
hold on
plot(dataLeaderMileage);
legend('TureTrajectoryAdd20s','PredictionTrajectory');
ErrorMileage=dataLeaderMileage-dataFollowerMileage(1:length(dataLeaderMileage));

%% 组编时刻
EoAList=[];
RBDList=[];
% for i=51:length(dataLeader)
%     [EoA,RBD]=calculateEoARBD(dataLeader(i),dataFollower(i));
%     EoAList=[EoAList EoA];
%     RBDList=[RBDList RBD];
% end
% figure(3)
% plot([51:length(dataLeader)],RBDList);
% hold on
% plot(ErrorMileage);
% legend('RBD','Following distance');
% xlabel('Qty(0.1s)');
% ylabel('Following distance, RBD');
% ylim([0 inf])
% xlim([0 5100])
% for i=51:length(dataLeader)
%     if ErrorMileage(i)>RBDList(i-50)
%         i;
%         break
%     end
% end
% 

%% 主程序
VelocityIni=0;
VelocityIniList=[0];
AA=sort(dataTrueAcceleration);
maxACC=AA(length(dataTrueAcceleration)-10);
minACC=AA(10);
UtanhList=[];
ErrorrbdList=[];
HeadwayList=[20];
Headway=0;
U=0;
Utanh=0;
oldtemp=0;
templist=[];
for i=1:length(dataLeader)-1
    Signtemp=1;
    [Errorrbd,temp]=calculateEoARBD(dataLeader(i),VelocityIni,z);
    temp=(4*oldtemp+temp)/5;
    oldtemp=temp;
    
    if i>80
        if Headway-temp<Errorrbd
            Signtemp=-1;
        end
        Uatt=(Headway+15)^2;
        Urep=-500*(Headway+15)^-0.5+eps;
        U=Uatt+Urep;
        U=U/250;
        if U<0
            Utanh=tanh(0.4*log(-U));
        else
            Utanh=tanh(0.4*log(U));
        end
        Utanh=real(Utanh);
        if Utanh<0
            Utanh=-Utanh;
        end
    
        if Signtemp==1
            acc=Utanh*maxACC;
            VelocityTemp=VelocityIni+acc;
            if VelocityTemp<dataLeader(i)+1.4
                VelocityIni=VelocityTemp;
            else
                VelocityIni=dataLeader(i)+1.4;
            end
        end
        if Signtemp==-1
            acc=Utanh*minACC;
            VelocityTemp=VelocityIni+acc;
            VelocityIni=VelocityTemp;
        end
        if VelocityIni<0
            VelocityIni=0;
        end
    end
    UtanhList=[UtanhList Utanh];
    VelocityIniList=[VelocityIniList VelocityIni];
    ErrorrbdList=[ErrorrbdList Errorrbd];
    if i==1
        LeaderMileage=velocity2mileage(dataLeader(1));
        FollowerMileage=velocity2mileage(VelocityIniList(1));
    else
        LeaderMileage=velocity2mileage(dataLeader(1:i));
        FollowerMileage=velocity2mileage(VelocityIniList(1:i));
    end
    Headway=LeaderMileage(length(LeaderMileage))-FollowerMileage(length(FollowerMileage));
    HeadwayList=[HeadwayList Headway];
end
% figure(101);
% plot(UtanhList);

figure(4)
VelocityAPFMileage=velocity2mileage(VelocityIniList);
savedataAPFVC1=dataLeaderMileage-VelocityAPFMileage(1:4978);
plot(dataLeaderMileage-VelocityAPFMileage); 
hold on
plot(ErrorrbdList);
legend('Following distance','RBD');
xlabel('Time(s)')
ylabel('Following distance and RBD(m)')
xlim([0 inf])
title("Headway and RBD between Follower and Leader")
xticklabels({'0','50','100','150','200','250','300','350','400','450'})

figure(5)
VelocityAPFMileage=velocity2mileage(VelocityIniList);
plot(VelocityAPFMileage)
hold on
plot(dataLeaderMileage); 
legend('Follower1','Leader')

figure(6)
savedataAPFVC2=VelocityIniList(1:4978);
plot(VelocityIniList*3.6,'r');
hold on
plot(dataLeader*3.6,'b')
legend('Follower','Leader')
xlabel('Time(s)')
ylabel('Velocity(km/h)')
xticklabels({'0','50','100','150','200','250','300','350','400','450'})
xlim([0 inf])
ylim([0 inf])


save('APFVC.mat','savedataAPFVC1','ErrorrbdList','savedataAPFVC2','dataLeader')

% save('APFLeader_Follower.mat','VelocityIniList',);

% result_table1=table(VelocityIniList');
% writetable(result_table1, 'Follower2V.csv');

% aaaa=VelocityAPFMileage-2*92.08;
% result_table1=table(aaaa');
% writetable(result_table1, 'Follower2M.csv');

% fid = fopen('APFFollower2P.txt','wt');
% fprintf(fid,'%g\n',VelocityIniList);
% fclose(fid);


% figure(13);
% subplot(1,2,1)
% Lista=dataLeaderMileage-VelocityAPFMileage;
% Lista=Lista(179:length(Lista));
% boxplot(Lista);
% title("Headway");
% ylim([80 200]);
% ylabel("m");
% grid on
% subplot(1,2,2)
% boxplot(ErrorrbdList(179:5050));
% title("RBD");
% ylim([80 200]);
% ylabel("m");
% grid on


%% km/h转换为m/s
function [dataList]=kmh2ms(data)
    data=data/3.6;
    dataList=[];
    for i=1:length(data)
        dataList=[dataList data(i)];
    end

end

%% 由速度求取里程
function [Mileage]=velocity2mileage(data)
    MileageTemp=0;
    Mileage=[];
    for i=1:length(data)
       MileageTemp=MileageTemp+0.1*data(i);
       Mileage=[Mileage MileageTemp];
    end
end

%% 计算EoAandRBD
function [RBD,Error]=calculateEoARBD(dataLeader,dataFollower,RBDA)
%3200   10400
    indexL = floor(10*dataLeader+1); 
    indexF = floor(10*dataFollower+1);
    if indexL<1
       indexL=1; 
    end
    if indexF<1
       indexF=1; 
    end
    RBD = RBDA(indexL,indexF)+max(10,0.003/dataLeader);
    Error=15;
    if indexL<50
        Error=60;
    end
end