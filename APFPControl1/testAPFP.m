
load('Pilot1.mat');
S0(1,1) = Pilot1(1,1);V0(1,1) = Pilot1(1,2);
S0(2,1) = -200;V0(2,1) = 0;
S0(3,1) = -400;V0(3,1) = 0;  
InputParameters = 0;

for i = 1:length(Pilot1)
    tic; % 开始计时
    %if S0(1,1)<=300
    %    V0(2,1) = Pilot1(i+1,2);
     %   V0(3,1)=Pilot1(i+1,2);
      %  S0(2,1)=Pilot1(i+1,1)-200;
       % S0(3,1)=Pilot1(i+1,1)-400;
    %else
        [S,V,OutputParameters] = APFTCSS(S0,V0,InputParameters);  
        %更新跟随车1和跟随车2的位移和速度
        S0(2,1) = S(2,1);V0(2,1) = V(2,1);
        S0(3,1) = S(3,1);V0(3,1) = V(3,1);
        x2= S0(2,1);
        x3= S0(3,1);
    %end
    elapsedTime = toc; % 结束计时并获取经过的时间

    % 打印或记录每次调用的执行时间
    fprintf('Iteration %d: Execution time = %.6f seconds\n', i, elapsedTime);
    

     %提取下一时刻领航车的位移和速度
     %S0(1,1) = Pilot1(i+1,1);V0(1,1) = Pilot1(i+1,2);
     
     
     
     
     %
     figure(1);
     plot(S0(1,1),V0(1,1),'b.');
     hold on;
     plot(S0(2,1),V0(2,1),'g.');
     hold on;
     plot(S0(3,1),V0(3,1),'black.');
     title('位移-速度'); % 添加标题
     hold on;

     figure(2);
     plot(i,S0(1,1) - S0(2,1),'b.');
     hold on;
     plot(i,S0(2,1) - S0(3,1),'g.');
     title('追踪间隔'); % 添加标题
     hold on;

     figure(3);
     plot(i,V0(1,1) - V0(2,1),'b.');
     hold on;
     plot(i,V0(2,1) - V0(3,1),'g.');
     title('速度差'); % 添加标题
     hold on;

     figure(4);
     plot(S0(1,1),i,'b.');
     hold on;
     plot(S0(2,1),i,'g.');
     hold on;
     plot(S0(3,1),i,'black.');
     title('位移-时间'); % 添加标题
     hold on;




     S0(1,1) = Pilot1(i+1,1);V0(1,1) = Pilot1(i+1,2); 
     
end