function [S,V,OutputParameters]=APFTCSS(S0,V0,InputParameters)
    data = coder.load('RBD1000.mat', 'z');
    z = data.z;
    OutputParameters = 0;
%% 主程序
    Leader=V0(1);
    VelocityIniF1=V0(2);
    VelocityIniF2=V0(3);
    maxACC=0.14;
    minACC=-0.14;
    HeadwayLF1=S0(1)-S0(2);
    HeadwayLF2=S0(2)-S0(3);
    U=0;
    Utanh=0;
    % Leader and Follower1
    oldtemp=0;
    Signtemp=1;
    [ErrorrbdLF1,tempLF1]=calculateEoARBD(Leader,VelocityIniF1,z);
    tempLF1=(4*oldtemp+tempLF1)/5;
    if HeadwayLF1-tempLF1<ErrorrbdLF1
        Signtemp=-1;
    end
    Uatt=(HeadwayLF1+15)^2;
    Urep=-500*(HeadwayLF1+15)^-0.5+eps;
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
        VelocityTempF1=VelocityIniF1+acc;
        VelocityIniF1=VelocityTempF1;
    end
    if Signtemp==-1
        acc=Utanh*minACC;
        VelocityTempF1=VelocityIniF1+acc;
        VelocityIniF1=VelocityTempF1;
    end
    if VelocityIniF1<0
        VelocityIniF1=0;
    end
    % Follower1 and Follower2
    oldtemp=0;
    Signtemp=1;
    [ErrorrbdLF2,tempLF2]=calculateEoARBD(VelocityIniF1,VelocityIniF2,z);
    tempLF2=(4*oldtemp+tempLF2)/5;
    if HeadwayLF2-tempLF2<ErrorrbdLF2
        Signtemp=-1;
    end
    Uatt=(HeadwayLF2+15)^2;
    Urep=-500*(HeadwayLF2+15)^-0.5+eps;
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
        VelocityTempF2=VelocityIniF2+acc;
        VelocityIniF2=VelocityTempF2;
    end
    if Signtemp==-1
        acc=Utanh*minACC;
        VelocityTempF2=VelocityIniF2+acc;
        VelocityIniF2=VelocityTempF2;
    end
    if VelocityIniF2<0
        VelocityIniF2=0;
    end
    S=[0,S0(2)+VelocityIniF1*0.1,S0(3)+VelocityIniF2*0.1]';
    V=[0,VelocityIniF1,VelocityIniF2]';


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
    RBD = RBDA(indexL,indexF)+max(10);
    Error=15;
    if indexL<50
        Error=60;
    end
end

end