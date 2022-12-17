// 测试扫雷游戏
#include "mine_file.h"

// 游戏框架
void game (void)
{
    // 建立扫雷数组
    // 1.存放雷数组mine
    char mine[ROWS][COLS]={0};
    // 2.存放排查雷数组show
    char show[ROWS][COLS]={0};
    // 初始化数组
    initboard(mine,ROWS,COLS,'0');
    initboard(show,ROWS,COLS,'*');
    // 打印雷盘、排雷盘(并有序号)
    displayboard(mine,ROW,COL);
    printf("\n");
    displayboard(show,ROW,COL);
    Sleep(1000);
    system("cls");
    // 布置雷
    setmine(mine,ROW,COL);
    displayboard(mine,ROW,COL);
    // 扫雷
    printf("\n");
    findmine(mine,show,ROW,COL);
    // displayboard(show,ROW,COL);
}

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

// 主函数
int main(void)
{

    list();
    // system("cls");
    system("pause");
    return 0;
}