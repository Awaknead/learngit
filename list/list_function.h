#include<math.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

// 测试目录常量
#define SEP 40 //分隔符长度
#define LIST "Tic-tac-toe game" //输入需要的标题
#define ONE "1.play"            //输入接口选项
#define TWO "0.quit"            
// #define ***(接口名) "输入接口选项" 
// ---------------------------------
// 数组(矩阵)
#define ROW 3 //行
#define COL 3  //列


// 目录函数
void list (void);
// 居中函数
void center (int i);
//分隔符函数
void separator (void);
// 游戏内容函数game
void game (void);
// 棋盘初始化
void initboard(char arr[ROW][COL],int row,int col);
// 打印棋盘
void disboard(char arr[ROW][COL],int row,int col);
// 玩家下棋
void playermove(char arr[ROW][COL],int row,int col);
// 电脑下棋
void computermove(char arr[ROW][COL],int row,int col);
// 胜利条件
int wins(char arr[ROW][COL],int row,int col);
// 胜利者
int winner(char arr[ROW][COL],int row,int col);
// 检测是否有空格
int testing(char arr[ROW][COL],int row,int col);   