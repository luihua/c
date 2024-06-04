clear all;
%假设变形后的曲线为C2（曲率连续）以上连续，即存在二阶导数且连续
%姓名：贾子康
%学号：2023201210
syms k;
% syms y(t);
alpha = pi / 4; %光纤在平面内受力后在初始位置的切线与水平方向的夹角
c = 4200; %波长与曲线曲率函数之间的常数项
x = 0.3:0.1:0.7; %所求曲率的横坐标
interval = 0.6;

lamda0_1 = 1529;
lamda_1 = [1529.808, 1529.807, 1529.813, 1529.812, 1529.814, 1529.809];

lamda0_2 = 1540;
lamda_2 = [1541.095, 1541.092, 1541.090, 1541.093, 1541.094, 1541.091];

test1_point_k = c * (lamda_1 - lamda0_1) / lamda0_1;%
test2_point_k = c * (lamda_2 - lamda0_2) / lamda0_2;%


xlength = length(x);

testx=(0:interval:3);
figure;
plot(lamda_1,test1_point_k,'ro', 'MarkerFaceColor', 'r');
hold on;
xlabel('波长（nm）');
ylabel('曲率');
title('测试一：波长与曲率关系')
grid on;

lamda_1_curv_fit=polyfit(lamda_1,test1_point_k,1);

%插值法建立多项式
curve_1_testx_fit=spline(testx,test1_point_k);
curve_2_testx_fit=spline(testx,test2_point_k);

xx = linspace(min(testx), max(testx), 100);

%通过拟合多项式描出各点
yy = ppval(curve_1_testx_fit, xx);
yy2= ppval(curve_2_testx_fit,xx);
x_k=ppval(curve_1_testx_fit, x);
x_k2=ppval(curve_2_testx_fit, x);

%画出原始点和拟合点
figure;
plot(testx, test1_point_k, 'ro', 'MarkerFaceColor', 'r'); % 原始数据点1
hold on;
plot(x,x_k,'-s','MarkerFaceColor', 'r');
plot(xx, yy, 'r--'); % 插值曲线1

plot(testx, test2_point_k, 'ro', 'MarkerFaceColor', 'b') % 原始数据点1
plot(x,x_k2,'-s','MarkerFaceColor', 'b');

plot(xx, yy2, 'b-'); % 插值曲线2

legend('实际曲率，测试1','插值曲率，测试1','拟合曲线测试1','实际曲率，测试2','插值曲率，测试2','拟合曲线测试2');
xlabel('x');
ylabel('curvature');
title('Spline Interpolation Curve Fitting of curve-x');
grid on;
hold off;


%初始化角度及横纵坐标
num_points = length(xx);
y_x1 = zeros(1, num_points);
y_y1=y_x1;
y_x2=y_x1;
y_y2=y_x1;
theta = zeros(1,num_points);
theta(1)=alpha;
theta2=theta;


% 角度积分算出对应的横纵坐标
for i = 2:num_points
    dx = xx(i) - xx(i-1);
    theta(i) = theta(i-1) + yy(i) * dx;
    theta2(i) = theta2(i-1) + yy2(i) * dx;
    y_x1(i) = y_x1(i-1) + cos(theta(i)) * dx;
    y_y1(i) = y_y1(i-1) + sin(theta(i)) * dx;
    y_x2(i) = y_x2(i-1) + cos(theta2(i)) * dx;
    y_y2(i) = y_y2(i-1) + sin(theta2(i)) * dx;
end


%画出重建曲线
figure;
plot(y_x1, y_y1, 'r--'); 
hold on;
plot(y_x2, y_y2, 'b-'); 
legend('曲线1', '曲线2');
xlabel('X');
ylabel('Y');
title('重建曲线');
grid on;
