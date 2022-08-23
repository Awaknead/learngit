//自定义函数头文件-->>函数声明-->>供主程序调用
#define DIS 0.95                 //长住客户折扣点
#define AST 50                   //星号长度
#define ASTER '*'                //打印‘*’
#define QUIT 5                   //选项结束值‘quit’
#define HOTEL1 180.00            //A hotel房费
#define HOTEL2 225.00            //B hotel房费
#define HOTEL3 255.00            //C hotel房费
#define HOTEL4 355.00            //D hotel房费

int hotel(void);                 //酒店菜单函数

int fate(void);                  //入住天数函数

void asterisk(void);             //分隔符函数

void total(int days,int price);//客户房费总价