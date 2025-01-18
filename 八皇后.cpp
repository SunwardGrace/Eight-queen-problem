#include "iostream"
using namespace std;
#define NUM 8		//NUM控制皇后数量 
int mark = 1,sum = 0,col = 0;
int chessboard[NUM][NUM];
void show()     //打印该解法的棋盘
{
    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            if(chessboard[i][j])
                cout<<"Q ";
            else
                cout<<"+ ";
        }
        cout<<endl;
    }
}
void get_pos()      //打印该解法放置黑皇后的所有坐标
{
    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            if(chessboard[i][j])
                cout<<"("<<i<<","<<j<<")";
        }
    }
    cout<<endl;
}
int find_min(int n)     //找出p为1的是第几位，以此来更新棋盘状态
{
    int num = 0;
    while((1&n)==0)
    {
        num++;
        n=n>>1;
    }
    return num;
}
void test(int row = 0,int ld = 0,int rd = 0)
{
    if(row == mark)     //每行都填满了则解法加1，返回上一层递推寻找其他解法
    {
        sum++;
        cout<<"第"<<sum<<"种解法:"<<endl;
        get_pos();
        show();
        return;

    }
    int pos = mark&(~(row|ld|rd));      //pos为1的位表示该列能放置黑皇后的位，最低(右)位表示棋盘中的第0行
    while(pos)
    {
        int p = pos&(-pos);     //p表示的就是当前能放黑皇后的序号最小的行(利用了原码与其补码进行按位与运算的结果只有原码中从低位到高位第一位为1的位置为1，其余为0的特性) 
        pos -= p;       //使用过后就清除该位，防止回溯时再次使用
        int temp = find_min(p);     //temp接收返回的p为1的位置(从低位往高位数，为方便棋盘状态更新，最低位为0号位)
        chessboard[temp][col] = 1;
        col++;      //因为该解法是一列一列放置黑皇后的，故放置后col++，为下一次放置的列数
        test(row+p,(ld+p)<<1,(rd+p)>>1);
        col--;      //回溯说明此时无解或者已经找到了一种解法了，故开始回退找其他解法
        chessboard[temp][col] = 0;
    }
}

int main()
{
    mark = (mark << NUM)-1;
    test(0,0,0);        //三个参数都为0说明当前状态的棋盘每行都未放置黑皇后，故在左右对角线上也无影响
    cout << endl;
    cout << "总解法数：" << sum << endl;
}
