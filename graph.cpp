/**
 * @file graph.cpp
 * @author jia (1075524832@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*************************************************************************************************/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.hpp"
#include "yy.hpp"

/*************************************************************************************************/

/*************************************************************************************************/

/*************************************************************************************************/

void MgGraph_Init(mggraph &G)
{
    int arcnum;
    people Jia,Li,Huang,He,Fan,F,Guan;

    for(int i=0;i<MAXSIZE;i++)//初始化所有顶点
    {
        memset(G.Vex[i].name,'\0',sizeof(G.Vex->name));
        G.Vex->IsTeacher=false;
        G.Vex->Group=-1;
    }
    for (int i = 0; i <MAXSIZE*(MAXSIZE-1)/2; i++)//清除所有边
    {
        G.Edge[i]=0;
    }
    
    strcpy(Fan.name,"Fan Hong");
    printf("%s",Fan.name);
    Fan.IsTeacher=true;    
    Fan.Group=ALL;
    strcpy(F.name,"Fan Ligeng");
    F.IsTeacher=true;
    F.Group=SOFTWARE;
    
    strcpy(Jia.name,"Jia Zikang");
    Jia.IsTeacher=false;
    Jia.Group=SOFTWARE;
    strcpy(Huang.name,"Huang Feiyu");
    Huang.IsTeacher=false;
    Huang.Group=SOFTWARE;
    strcpy(Li.name,"Li Wangjia");
    Li.IsTeacher=false;
    Li.Group=SOFTWARE;
    strcpy(Guan.name,"Guan Zilei");
    Guan.IsTeacher=false;
    Guan.Group=HARDWARE;
    strcpy(He.name,"He Yuying");
    He.IsTeacher=false;
    He.Group=HARDWARE;

    G.Vex[0]=Fan;
    G.Vex[1]=F;
    G.Vex[2]=Jia;
    G.Vex[3]=Huang;
    G.Vex[4]=He;
    G.Vex[5]=Li;
    G.Vex[6]=Guan;


    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <i+1; j++)
        {
            if(i==j||G.Vex[i].IsTeacher&&G.Vex[j].IsTeacher)//同一个端点不存在边，教师之间没有直接联系
                G.Edge[i*(i+1)/2+j]=0;
    
            else
            {
                if(G.Vex[i].Group==G.Vex[j].Group)//同组成员存在边
                {
                    G.Edge[i*(i+1)/2+j]=1;
                    arcnum++;
                }
                else if (G.Vex[i].Group==ALL||G.Vex[j].Group==ALL)//ALL组与所有成员存在边
                {
                    G.Edge[i*(i+1)/2+j]=1;
                    arcnum++;
                }

                else
                    G.Edge[i*(i+1)/2+j]=0;
            }
        }
        
        
    }
    G.arcnum=arcnum;
    G.vexnum=7;


    

    
    


    
}


/*************************************************************************************************/

/*************************************************************************************************/

int main()
{
    mggraph G;
    MgGraph_Init(G);
    return 0;
}