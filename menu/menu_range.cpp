//范围上下限函数
#include<stdio.h>
#include "menu_head.h"
int range (void)
{
    int sum;
    while(getchar()!='\n')
           continue;
    while((scanf("%d",&sum))!=1)
    {
        printf("Enter an integer value:\n");
        continue;
    }
    return sum;
}