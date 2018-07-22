#include <iostream>
#include <vector>

using namespace std;

/*
小明同学学习了不同的进制之后，拿起了一些数字做起了游戏。小明同学知道，在日常生
活中我们最常用的是十进制数，而在计算机中，二进制数也很常用。现在对于一个数字x，
小明同学定义出了两个函数f(x)和g(x)。 f(x)表示把x这个数用十进制写出后各个数位上
的数字之和。如f(123)=1+2+3=6。 g(x)表示把x这个数用二进制写出后各个数位上的数字
之和。如123的二进制表示为1111011，那么，g(123)=1+1+1+1+0+1+1=6。 小明同学发现对
于一些正整数x满足f(x)=g(x)，他把这种数称为幸运数，现在他想知道，大于0且小于等于n的幸运数有多少个？
*/


/*
输入描述:
每组数据输入一个数n(n<=100000)

输出描述:
每组数据输出一行，小于等于n的幸运数个数。
*/

/*
思路：
按照题目暴力解决
*/
int func(int n, int m)
{
    int res = 0;
    /*确定首位*/
    int ji = 1;
    while (1)
    {
        if (n/ji < m && n/ji > 0)
        {
            break;
        }
        ji *= m;
    }
    for (int j = ji; ji >= 1; ji /= m)
    {
        res += n/ji;
        n = n%ji;
    }
    
    return res;
}

int main()
{
    int n;
    int res = 1;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (func(i, 10) == func(i, 2))
        {
            cout << i << endl;
            res++;
        }
    }
    cout << res <<endl;
    system("pause");
    return 0;
}