//  Created by www.runoob.com on 15/11/9.
//  Copyright Â© 2015å¹? èœé¸Ÿæ•™ç¨‹. All rights reserved.
//
 
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int ID;
    int math;
    int English;
    int C;
    int avargrade;
    char name[20];
}Stu;
int main()
{
    FILE*fp=NULL;
    fp=fopen("C:\\Users\\shattering\\Desktop\\x2.txt","w+");
    Stu stu[5];
    int i,avargrade=1;
    printf("ÊäÈë:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d %s %d %d %d",&(stu[i].ID),stu[i].name,&(stu[i].math),&(stu[i].English),&(stu[i].C));
        stu[i].avargrade=(stu[i].math+stu[i].English+stu[i].C)/3;
    }
    
    if((fp=fopen("stud","w"))==NULL)
    {
        printf("error :cannot open file!\n");
        exit(0);
    }
    for(i=0;i<5;i++)
        fprintf(fp,"%d %s %d %d %d %d\n",stu[i].ID,stu[i].name,stu[i].math,stu[i].English,
                stu[i].C,stu[i].avargrade);
    
    fclose(fp);
    // system("pause");
    return 0;
}