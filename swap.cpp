//函数程序-->>函数定义
#include<stdio.h>
#include "swap.h"
//选择酒店菜单函数定义
int hotel (void)
{
    int num;
    int sud;
    asterisk();
    printf("Please select the following hotels:\n");
    printf("1)A hotel                 2)B hotel\n");
    printf("3)C hotel                 4)D hotel\n");
    printf("5)quit\n");
    asterisk();
    while(((sud=scanf("%d",&num)) !=1 ) || (num<1 || num>5))
        {
            if(sud!=1)
              scanf("%*s");
            printf("Please enter the option 1-5 and select the hotel number.\n");
        }
    return num;
}


//星号分割线函数定义
void asterisk(void)
{
    int i;
    for(i=1;i<=AST;i++)
      putchar(ASTER);
    printf("\n");
}


//客户长住天数函数定义
int fate (void)
{
    int day;
    printf("Please enter the number of days you want to stay.\n");
    while((scanf("%d",&day))!=1)
    {
        scanf("%*s");
        printf("Please enter the correct value ,such as(1,40,100)in days.\n");
    }
    return day;
}


//客户住的天数总房费函数定义
void total (int days,int price)
{
    int count;   //计数
    double dis=1.0;  //折扣率
    double total=0.0;//总房价
    for(count=1;count<=days;count++,dis*=DIS)
       total+=(price*dis);
    printf(",and the total cost is %.3f.\n",total);
}

