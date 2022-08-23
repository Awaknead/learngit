//主程序  住酒店消费
#include<stdio.h>
#include "swap.h"
int main(void)
{
    int sum;             //酒店选项函数返回值
    int num;             //酒店房费价格
    int nights;          //客户住的天数

    while((sum=hotel())!=QUIT)
    {
        switch(sum)
        {
            case 1:num=HOTEL1;
                break;
            case 2:num=HOTEL2;
                break;
            case 3:num=HOTEL3;
                break;  
            case 4:num=HOTEL4;
                break;
            default:num=0.0;
                break;
        }
        nights=fate();
        printf("The price of the hotel you choose is %d",num);
        total(nights,num);
    }
    printf("Thank you and goodbye.\n");
    return 0;
}