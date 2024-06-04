clear all;
%������κ������ΪC2���������������������������ڶ��׵���������
%���������ӿ�
%ѧ�ţ�2023201210
syms k;
alpha = pi / 4; %������ƽ�����������ڳ�ʼλ�õ�������ˮƽ����ļн�
c = 4200; %�������������ʺ���֮��ĳ�����
x = 0.3:0.1:0.7; %�������ʵĺ�����
k1 = zeros(size(x));
k2 = k1;
lamda0_1 = 1529;
interval = 0.6;
lamda_1 = [1529.808, 1529.807, 1529.813, 1529.812, 1529.814, 1529.809];
lamda0_2 = 1540;
lamda_2 = [1541.095, 1541.092, 1541.090, 1541.093, 1541.094, 1541.091];
test1_point_k = c * (lamda_1 - lamda0_1) / lamda0_1;
test2_point_k = c * (lamda_2 - lamda0_2) / lamda0_2;
n = interval * cos(alpha);
xlength = length(x);

%ʹ�ò�ֵ��������������
for index = 1:xlength
    i = fix(x(index) / n);
    k1(index) = solve((k - test1_point_k(i + 1)) / (x(index) - i * n) == (test1_point_k(i + 2) - test1_point_k(i + 1)) / n);
    k2(index) = solve((k - test2_point_k(i + 1)) / (x(index) - i * n) == (test2_point_k(i + 2) - test2_point_k(i + 1)) / n);
end
%�������ʼ��㹫ʽk(x)=y"/(1+y'2)(3/2),���y
dsolve('D2y')
