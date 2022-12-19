#include "mine_file.h"

// 初始化数组
void initboard(char board[ROWS][COLS],int rows,int cols,char set)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            board[i][j]=set;
        }
    }
}
// 打印雷盘、排雷盘(并有序号)
void displayboard(char board[ROWS][COLS],int row,int col)
{
    int i,j;
    // 打印序号(行)
    for(i=0;i<=row;i++)
       printf("%d ",i);
    printf("\n");
    // 打印棋盘
    for(i=1;i<=row;i++)
    {
        // 打印序号(列)
        printf("%d ",i);
        for(j=1;j<=col;j++)
           printf("%c ",board[i][j]);
        printf("\n");
    }
}
// 布置雷
void setmine(char board[ROWS][COLS],int row,int col)
{
    srand((unsigned)time(NULL));
    int count=SET_MINE;
    int x=0;
    int y=0;
    while(count)
    {
        // 随机在棋盘上布置雷
        x=rand()%row+1;//随机值1-9  %row; 随机值0-8
        y=rand()%col+1;
        if(board[x][y] == '0')
        {
            board[x][y]='1';
            count--;
        }
    }
}
// 坐标周围雷的个数，返回个数
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
    //'0'-'0' = 0;
    //'1'-'0' = 1;
    // 坐标周围8个坐标内有几个雷
    return mine[x-1][y-1]+
            mine[x][y-1]+
            mine[x+1][y-1]+
            mine[x+1][y]+
            mine[x+1][y+1]+
            mine[x][y+1]+
            mine[x-1][y+1]+
            mine[x-1][y]-8*'0';
}
// 递归-辐射坐标圈
void diguishow(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int row,int col)
{
    if(show[x][y] == ' ');
    //    return ;
    else if(get_mine_count(mine,x,y) != 0)
        show[x][y] = get_mine_count(mine,x,y)+'0';
        // return ;
    else
    {
        show[x][y] = ' ';
        diguishow(mine,show,x-1,y-1,ROW,COL);
        diguishow(mine,show,x,y-1,ROW,COL);
        diguishow(mine,show,x+1,y-1,ROW,COL);
        diguishow(mine,show,x+1,y,ROW,COL);
        diguishow(mine,show,x+1,y+1,ROW,COL);
        diguishow(mine,show,x,y+1,ROW,COL);
        diguishow(mine,show,x-1,y+1,ROW,COL);
        diguishow(mine,show,x-1,y,ROW,COL);
    }

}
// 排雷
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x=0;
    int y=0;
    int count=0;
    int win=0;
    do
    {
        // 用户输入坐标
        printf("please enter coordinate .>");
        scanf("%d%d",&x,&y);
        //坐标合格
        if(x >= 1 && x<=row && y >= 1 && y<=col)
        {
            // 踩到雷，退出游戏
            if(mine[x][y] == '1')
            {
                printf("l'm sorry,your stepped on thunder.\n");
                displayboard(mine,ROW,COL);
                break;
            }
            // 没踩到雷，显示该坐标周围雷的个数
            else
            {
                diguishow(mine,show,x,y,ROW,COL);//辐射坐标圈
                displayboard(show,ROW,COL);//排雷图
                //displayboard(mine,ROW,COL);//布雷图
            }
        }
        else //坐标非法
            printf("lllegal coordinate,re-return.\n ");
        //判断没翻的数还有多少个返回while循环
        win=0;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(show[i][j] == '*')
                  win++;
            }
        }
        printf("\n---%d---\n",win);
    }while(win > SET_MINE);//没翻的大于雷的数量

    if(win == SET_MINE)//判断while循环等于雷的数量
    {
        printf("congratulations on winning.\n");
        displayboard(mine,row,col);
    }
}

