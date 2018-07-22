#include <iostream>

using namespace std;

/*
尽管是一个CS专业的学生，小B的数学基础很好并对数值计算有着特别的兴趣，喜欢用计算机程序来解决数学问题，
现在，她正在玩一个数值变换的游戏。她发现计算机中经常用不同的进制表示一个数，如十进制数123表达为16进
制时只包含两位数7、11（B），用八进制表示为三位数1、7、3，按不同进制表达时，各个位数的和也不同，如上
述例子中十六进制和八进制中各位数的和分别是18和11,。 小B感兴趣的是，一个数A如果按2到A-1进制表达时，各
个位数之和的均值是多少？她希望你能帮她解决这个问题？ 所有的计算均基于十进制进行，结果也用十进制表示为不可约简的分数形式。
*/

/*
输入描述:
输入中有多组测试数据，每组测试数据为一个整数A(1 ≤ A ≤ 5000).

输出描述:
对每组测试数据，在单独的行中以X/Y的形式输出结果。
*/

/*
思路：
按题意求出各个进制时的各位和值，并求出两个数的最大公约数
*/

//求n进制时，各个位之和(其中m表示进制，n表示需要表达的数字)
int func(int n, int m)
{
    int res = 0;
    /*确定首位*/
    int ji = m;
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

/*
求最大公约数（最大公倍数=两数之积除以最大公约数）
1、更损相减法
反覆把兩數的較大者減去較小者，直至兩數相等，這數就是最大公因數。
*/
int func1(int n, int m)
{
    if (n > m)
    {
        n = n + m;
        m = n - m;
        n = n - m;
    }
    while (m > n)
    {
        m -= n;
        if (n > m)
        {
            n = n + m;
            m = n - m;
            n = n - m;
        }
    }
    return m;
}

int main()
{
    int n;
    int res = 0;
    
    cin >> n;
    int j = 0;
    for (int i = 2; i < n; i++)
    {
        res += func(n, i);
        j++;
    }
    int val = func1(res, j);
    cout << res/val << "/" << j/val << endl;
    system("pause");
    
    return 0;
}