#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
void b(int* a, int* c)
{
	int temp;
	temp = *a;
	*a =* c;
	*c = temp;
}
void  select(int a[], int leng)
{
	for (int i = 0; i < leng - 1; i++) 
	{
		int min = i;
		for (int j = i + 1; j < leng; j++) 
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i) 
		{
			b(&a[min], &a[i]);
		}
	}  

}
void insert(int arr[], int leng)
{
	int i, j, temp;
	for (i = 1; i < leng; i++) {
		temp = arr[i];
		for (j = i-1; j >=0 && arr[j] > temp; j--)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
}
void shell(int arr[], int leng) 
{
	int i, j, temp, gap;
	for (gap = leng >> 1; gap > 0; gap = gap >> 1)
	{
		for (i = gap; i<leng; i++)
		{
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) 
			{
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}
double average(int n,...){
	va_list valist;
	int i;
	double sum=0.0,ave=0.0;
	va_start(valist,n);
	for(i=0;i<n;i++){
		sum+=va_arg(valist,double);
	}
	va_end(valist);
	ave=sum/n;
	
	return ave;

}
int feb(int n)
{
	int sum;
	if(n==1)
	return 0;
	else if(n==2)
	return 1;
	else 
	{
		return (feb(n-1)+feb(n-2));					
	}
	 
}
void shell_sort(int arr[], int len) {
	int gap, i, j;
	int temp;
	for (gap = len >> 1; gap > 0; gap = gap >> 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}
typedef struct student
{
 int ID;
 char name[10];
 double  score1;   
 double  score2;
 double  score3;
}stu;
int main()
{
	int a[5] = { 1,3,5,2,4 };
	select(a, 5);
	for(int i=0;i<5;i++){
		printf("a[%d]=%d\n", i, a[i]);

    }
	int b[5] = { 1,3,5,2,4 };
	insert(b, 5);
	for (int i = 0; i < 5; i++) 
		printf("b[%d]=%d\n", i, b[i]);
	int c[5] = { 1,3,5,2,4 };
	shell_sort(c, 5);
	for (int i = 0; i < 5; i++) 
		printf("c[%d]=%d\n", i,c[i]);
    long double sd=32.0;
    printf("%d\n",sizeof(stu));
    stu a_stu;
	for(int i=1;i<=10;i++){
	printf("%d ",feb(i));}
	printf("\n");
	stu students[5];
	stu *ptr= students;
    FILE *file=NULL; 
	file=fopen("C:\\Users\\shattering\\Desktop\\xj.txt","w+");
	printf("请输入5个同学的信息：学生号，姓名，3门成绩:\n");
    for(int i=0;i<5;i++)
	{
		ptr=&students[i];
	 scanf_s("%d %s %f %f %f",&(ptr->ID),ptr->name,&(ptr->score1),&(ptr->score2),&(ptr->score3));
	 
	}
	
	
	for(int i=0;i<5;i++)
	{
		fprintf(file,"%d %s %.2f %.2f %.2f %.2f\n",students[i].ID,students[i].name,students[i].score1,students[i].score2,students[i].score3,average(3,students[i].score1,students[i].score2,students[i].score3));

	};
	for(int i=0;i<5;i++)
	{
		printf("%d %s %.3f %.2f %.2f %.2f\n",students[i].ID,students[i].name,students[i].score1,students[i].score2,students[i].score3,average(3,students[i].score1,students[i].score2,students[i].score3));

	};
	 fclose(file);  



	return 0;
}