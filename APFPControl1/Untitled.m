%y = Pilot1(x+1,2)-Pilot1(x,2);
%x = 1:1:600;
%y=tanh(0.1*log(abs(-0.15*(x+15).^1.5+3000*(x+15).^-0.5)));
%y=-(x+15).^2+500*(x+15).^-0.5-eps;
%plot(x,y)
load('Pilot1.mat');
for  i=1:length(Pilot2)
 figure(1);
 if i<2500
     plot(i,4.5*(-Pilot2(i,1)+Pilot1(i,1)),'b.');
     hold on;
     title('位移-速度'); % 添加标题
     hold on;
 else
      plot(i,9*(-Pilot2(i,1)+Pilot1(i,1)),'b.');
     hold on;
     title('位移-速度'); % 添加标题
     hold on;
end
end