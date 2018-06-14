#include <iostream>

using namespace std;

/*
对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？
*/

/*
输入描述:
输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开。

输出描述:
输出rev(rev(x) + rev(y))的值
*/

/*
思路求出各个位上的数字然后再按题意重新计算出来
*/
//按位反转
int rev(int n)
{
    int qian, bai, shi, ge;
    int result;
    if (n/1000 >= 1)
    {
        qian = n/1000;
        bai = (n-1000*qian)/100;
        shi = (n-1000*qian-100*bai)/10;
        ge = (n-1000*qian-100*bai-10*shi);
        /*求反*/
        result = 1000*ge+100*shi+10*bai+qian;
    }
    else if (n/100 > 0)
    {
        bai = n/100;
        shi = (n-100*bai)/10;
        ge = (n-100*bai-10*shi);
        
        result = 100*ge+10*shi+bai;
    }
    else if (n/10 > 0)
    {
        shi = n/10;
        ge = n-shi*10;
        
        result = 10*ge+shi;
    }
    else
    {
        result = n;
    }
    return result;
}

int main()
{
    int n, m;
    int revN, revM;
    
    cin >> n >> m;
    revN = rev(n);
    revM = rev(m);
    cout << rev(revN+revM);
    system("pause");
    
    return 0;
}