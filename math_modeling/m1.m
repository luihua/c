clear all;
%������κ������ΪC2���������������������������ڶ��׵���������
%���������ӿ�
%ѧ�ţ�2023201210
syms k;
% syms y(t);
alpha = pi / 4; %������ƽ�����������ڳ�ʼλ�õ�������ˮƽ����ļн�
c = 4200; %�������������ʺ���֮��ĳ�����
x = 0.3:0.1:0.7; %�������ʵĺ�����
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
xlabel('������nm��');
ylabel('����');
title('����һ�����������ʹ�ϵ')
grid on;

lamda_1_curv_fit=polyfit(lamda_1,test1_point_k,1);

%��ֵ����������ʽ
curve_1_testx_fit=spline(testx,test1_point_k);
curve_2_testx_fit=spline(testx,test2_point_k);

xx = linspace(min(testx), max(testx), 100);

%ͨ����϶���ʽ�������
yy = ppval(curve_1_testx_fit, xx);
yy2= ppval(curve_2_testx_fit,xx);
x_k=ppval(curve_1_testx_fit, x);
x_k2=ppval(curve_2_testx_fit, x);

%����ԭʼ�����ϵ�
figure;
plot(testx, test1_point_k, 'ro', 'MarkerFaceColor', 'r'); % ԭʼ���ݵ�1
hold on;
plot(x,x_k,'-s','MarkerFaceColor', 'r');
plot(xx, yy, 'r--'); % ��ֵ����1

plot(testx, test2_point_k, 'ro', 'MarkerFaceColor', 'b') % ԭʼ���ݵ�1
plot(x,x_k2,'-s','MarkerFaceColor', 'b');

plot(xx, yy2, 'b-'); % ��ֵ����2

legend('ʵ�����ʣ�����1','��ֵ���ʣ�����1','������߲���1','ʵ�����ʣ�����2','��ֵ���ʣ�����2','������߲���2');
xlabel('x');
ylabel('curvature');
title('Spline Interpolation Curve Fitting of curve-x');
grid on;
hold off;


%��ʼ���Ƕȼ���������
num_points = length(xx);
y_x1 = zeros(1, num_points);
y_y1=y_x1;
y_x2=y_x1;
y_y2=y_x1;
theta = zeros(1,num_points);
theta(1)=alpha;
theta2=theta;


% �ǶȻ��������Ӧ�ĺ�������
for i = 2:num_points
    dx = xx(i) - xx(i-1);
    theta(i) = theta(i-1) + yy(i) * dx;
    theta2(i) = theta2(i-1) + yy2(i) * dx;
    y_x1(i) = y_x1(i-1) + cos(theta(i)) * dx;
    y_y1(i) = y_y1(i-1) + sin(theta(i)) * dx;
    y_x2(i) = y_x2(i-1) + cos(theta2(i)) * dx;
    y_y2(i) = y_y2(i-1) + sin(theta2(i)) * dx;
end


%�����ؽ�����
figure;
plot(y_x1, y_y1, 'r--'); 
hold on;
plot(y_x2, y_y2, 'b-'); 
legend('����1', '����2');
xlabel('X');
ylabel('Y');
title('�ؽ�����');
grid on;
