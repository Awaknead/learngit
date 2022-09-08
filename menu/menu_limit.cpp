//读取中值函数
#include<stdio.h>
#include "menu_head.h"
int limit (int max ,int min)
{
    int medion;
    printf("Enter intermediate value:\n");
    while((scanf("%d",&medion))!=1)
         return -1;
    if(medion > min && medion < max)
       return medion;
    else if(medion < min || medion > max)
        {
            printf("Out of range please enter a value wuthin the range:\n");
           chioce(); 
        }
           
    return -1;
}