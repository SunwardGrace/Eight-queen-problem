#include "iostream"
using namespace std;
#define NUM 8		//NUM���ƻʺ����� 
int mark = 1,sum = 0,col = 0;
int chessboard[NUM][NUM];
void show()     //��ӡ�ýⷨ������
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
void get_pos()      //��ӡ�ýⷨ���úڻʺ����������
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
int find_min(int n)     //�ҳ�pΪ1���ǵڼ�λ���Դ�����������״̬
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
    if(row == mark)     //ÿ�ж���������ⷨ��1��������һ�����Ѱ�������ⷨ
    {
        sum++;
        cout<<"��"<<sum<<"�ֽⷨ:"<<endl;
        get_pos();
        show();
        return;

    }
    int pos = mark&(~(row|ld|rd));      //posΪ1��λ��ʾ�����ܷ��úڻʺ��λ�����(��)λ��ʾ�����еĵ�0��
    while(pos)
    {
        int p = pos&(-pos);     //p��ʾ�ľ��ǵ�ǰ�ܷźڻʺ�������С����(������ԭ�����䲹����а�λ������Ľ��ֻ��ԭ���дӵ�λ����λ��һλΪ1��λ��Ϊ1������Ϊ0������) 
        pos -= p;       //ʹ�ù���������λ����ֹ����ʱ�ٴ�ʹ��
        int temp = find_min(p);     //temp���շ��ص�pΪ1��λ��(�ӵ�λ����λ����Ϊ��������״̬���£����λΪ0��λ)
        chessboard[temp][col] = 1;
        col++;      //��Ϊ�ýⷨ��һ��һ�з��úڻʺ�ģ��ʷ��ú�col++��Ϊ��һ�η��õ�����
        test(row+p,(ld+p)<<1,(rd+p)>>1);
        col--;      //����˵����ʱ�޽�����Ѿ��ҵ���һ�ֽⷨ�ˣ��ʿ�ʼ�����������ⷨ
        chessboard[temp][col] = 0;
    }
}

int main()
{
    mark = (mark << NUM)-1;
    test(0,0,0);        //����������Ϊ0˵����ǰ״̬������ÿ�ж�δ���úڻʺ󣬹������ҶԽ�����Ҳ��Ӱ��
    cout << endl;
    cout << "�ܽⷨ����" << sum << endl;
}
