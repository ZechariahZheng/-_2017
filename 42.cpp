#include <iostream>
#include <memory.h>

using namespace std;

/*
游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，
任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状
态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第
二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成
输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。

输入描述:
输入包括一行,两个整数表示人物ID.

输出描述:
输出是否完成
*/

/*
思路：
用32个unsigned int类型来记录着1024个任务是否已经完成，刚好unsigned int就是32位，32的平方是1024，
所以用每一位去记录一个任务。如果这个任务完成，那么这一位就置1(“或运算”)，检查的时候也只用检查相应位是否为1(“与运算”)。
*/
int main()
{
    int ID1, ID2;
    cin >> ID1 >> ID2;
    if (ID1>1024 || ID1<1 || ID2>1024 || ID2<1)
    {
        cout << -1;
        return 0;
    }
    unsigned int flag[32];
    memset(flag, sizeof(flag), 0);
    int N1 = ID1/32;
    if (N1 >= 1)
        N1 -= 1;
    else
        N1 = 0;
    int WEI1 = ID1%32;
    flag[N1] |= (1<<WEI1);
    int N2 = ID2/32;
    if (N2 >= 1)
        N2 -= 1;
    else
        N2 = 0;
    int WEI2 = ID2%32;
    unsigned int tmp = flag[N2] & (1<<WEI2);
    if (tmp)
        cout << 1;
    else
        cout << 0;
    system("pause");
    return 0;
}