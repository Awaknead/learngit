//列表函数
#include<stdio.h>
#include "menu_head.h"
void chioce(void)
{
    int sum=0;
    int max,min;
    printf("Please chioose one of the following:\n");
    printf("1) copy files          2) move files\n");
    printf("3) remove files        4) quit\n");
    printf("Enter the number of your choice:\n");
    while((scanf("%d",&sum))!=1)
    {
        printf("Please enter 1~4 valid values:\n");
        while(getchar()!='\n')
              continue;
        continue;
    }
    don:switch(sum)
    {
        case 1:printf("Input upper limit:\n");
               max=range();
               printf("Input lower limit:\n");
               min=range();
               sum=limit(max,min);
               if(sum==-1)
                  goto don;
               break;
        case 2:printf("Input upper limit:\n");
               max=range();
               printf("Input lower limit:\n");
               min=range();
               sum=limit(max,min);
               if(sum==-1)
                  goto don;
               break;
        case 3:printf("Input upper limit:\n");
               max=range();
               printf("Input lower limit:\n");
               min=range();
               sum=limit(max,min);
               if(sum==-1)
                  goto don;
               break;
        case 4:printf("quit.\n");
               sum=-2;
               break;
        default:printf("Done.\n");
               break;
    }
    if(sum==-1)
       printf("Intermediate value input error.\n");
    else if(sum == -2)
       printf("Exit program.\n");
    else
       printf("The median vlaue is %d",sum);
}