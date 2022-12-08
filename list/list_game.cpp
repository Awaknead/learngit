// #include<math.h>
// #include<time.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>
// #include<string.h>
// #include<windows.h>
#include "list_function.h"

//分隔符函数
void separator (void)
{
    int i;
    for(i=0;i<SEP;i++)
       putchar('*');
    putchar('\n');
}
// 居中函数
void center (int i)
{
    int sum;
    int x;
    //（边框总长-字符数）/2  获得居中值
    sum=(SEP-i)/2;
    //输出空格
    for(x=0;x<sum;x++)
       putchar(' ');
}


// 棋盘初始化
void initboard(char arr[ROW][COL],int row,int col)
{
    int i;
    int j;
    //嵌套
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            // 数组全部初始化空格
            arr[i][j] = ' ';
        }
    }
}

// 打印棋盘
void disboard(char arr[ROW][COL],int row,int col)
{
    // 行计数值
    int i;
    // 列计数值
    int j;
    // 打印行
    for(i=0;i<row;i++)
    {
        // 打印列
        for(j=0;j<col;j++)
        {
            printf(" %c ",arr[i][j]);
            // 最后一列没有丨所以if(j<col-1)
            if(j<col-1)
               printf("|");
        }
        printf("\n");
        if(i<row-1)
        {
           // 最后一行不打印分割 if(i<row-1)
           // 打印分割
           for(j=0;j<col;j++)
           {
                printf("---");
                if(j<col-1)
                   printf("|");
           } 
           printf("\n");
        }
        
    }
}
// 玩家下子
void playermove(char arr[ROW][COL],int row,int col)
{
    int x=0;  //行
    int y=0;  //列
    printf("player first:\n");
    while(1)
    {
        printf("please enter the coordinates of the main child:>");
        scanf("%d%d",&x,&y);
        // 判断玩家用户输入的是否有溢出
        // 玩家用户不知道数组[0]开始的
        // 他们知道1-3所以x>=1,y>=1
        if((x>=1 && x<=row) && (y>=1 && y<=col))
        {
            // 判断数组中是否已经输入值
            if(arr[x-1][y-1] == ' ')
            {
                arr[x-1][y-1] ='*';
                break;
            }
            else
            // 输入坐标占用
              printf("cooedinate occupation.\n");
        }
        else
        //    输入坐标错误
           printf("input coordinate error.\n");
    }

}

// 电脑下棋
void computermove(char arr[ROW][COL],int row,int col)
{
    int x;
    int y;
    //伪随机值
    srand((unsigned)time(NULL));
    while(1)
    {
        // 生成伪随机值
        x=rand()%row;
        y=rand()%col;
        // 判断坐标是否被占用
        if(arr[x][y] == ' ')
        {
            // 打印‘#’
            arr[x][y] = '#';
            break;
        }
    }
}

// 胜利者
int winner(char arr[ROW][COL],int row,int col)
{
    if(arr[row][col] == '*')
    {
        printf("player wins.\n");
        return 0;
    }
    else if(arr[row][col] == '#')
        {
            printf("computer wins.\n");
            return 0;
        }
    return 1;
}   

// 检测是否有空格
int testing(char arr[ROW][COL],int row,int col)
{
    int i;
    int j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(arr[i][j] == ' ')
            return 1;
        }
    }
    printf("lt's a draw.\n");
    return 0;
}

// 胜利条件
int wins(char arr[ROW][COL],int row,int col)
{
    if(arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] != ' ')
       return winner(arr,0,0);
    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] != ' ')
            return winner(arr,1,0);
    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] != ' ')
            return winner(arr,2,0);
    else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] != ' ')
            return winner(arr,0,0);
    else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] != ' ')
            return winner(arr,0,1);
    else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] != ' ')
            return winner(arr,0,2);
    else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != ' ')
            return winner(arr,0,0);
    else if (arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2] && arr[2][0] != ' ')
            return winner(arr,2,0);
    else if (testing(arr,ROW,COL) != 1)
            return 0;
    else
        return 1;

}

// 游戏内容函数game
void game (void)
{
    int i;
    // 数组-存放走出棋盘信息
    char arr[ROW][COL]={0}; //全部空格
    // 棋盘初始化
    initboard(arr,ROW,COL);
    // 打印棋盘
    disboard(arr,ROW,COL);
    do
    {
        // 玩家下棋
        playermove(arr,ROW,COL);
        system("cls");
        disboard(arr,ROW,COL);// 打印棋盘
        if((i=wins(arr,ROW,COL)) == 0)//判断胜利者
           break;
        // 电脑下棋 
        computermove(arr,ROW,COL);
        system("cls");
        disboard(arr,ROW,COL);
        if((i=wins(arr,ROW,COL)) == 0)
           break;
    }while(i);
}

// 目录函数
void list (void)
{
    //分端口输入值
    int i;
    do
    {
        separator();//分隔符
        center(strlen(LIST));
        printf("%s\n",LIST);
        center(strlen(ONE));
        printf("%s\n",ONE);
        center(strlen(TWO));
        printf("%s\n",TWO);
        // 添加选项值
        // center(strlen(***));
        // printf("%s\n",***);
        separator();
        scanf("%d",&i);
        switch(i)
        {
            //play 接口
            case 1:
                system("cls");
                game();
                break;
            //quit 接口
            case 0:
                system("cls");
                printf("Game over.\n");
                break;
            default:
                printf("lnput error.(input 1/0)\n");
                break;
        }
        // system("cls");

    }while(i);
}
