#include<math.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

// 测试目录常量
#define SEP 40 //分隔符长度
#define LIST "mine clearance game" //输入需要的标题
#define ONE "1.play"            //输入接口选项
#define TWO "0.quit"            
// #define ***(接口名) "输入接口选项" 
// ---------------------------------

// 测试参数
#define ROW 9 //工作区行
#define COL 9 //工作区列
#define ROWS ROW+2 //游戏框架行
#define COLS COL+2 //游戏框架列
#define SET_MINE 80 //设置雷的个数


// 目录函数
void list (void);
// 居中函数
void center (int i);
//分隔符函数
void separator (void);
// 游戏框架
void game(void);
// 初始化数组
void initboard(char board[ROWS][COLS],int rows,int cols,char set);
// 打印雷盘、排雷盘
void displayboard(char board[ROWS][COLS],int row,int col);
// 布置雷
void setmine(char board[ROWS][COLS],int row,int col);
// 排雷
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
// 坐标周围雷的个数，返回个数
int get_mine_count(char mine[ROWS][COLS],int x,int y);