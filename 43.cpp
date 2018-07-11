#include <iostream>
#include <vector>

using namespace std;

/*
给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）

输入描述:
输入包括一个整数n,(3 ≤ n < 1000)

输出描述:
输出对数
*/

/*
思路：不是背包问题，两两对数和的问题
*/

/*判断一个数是否是质数*/
bool f0(int n)
{
    bool flag = true;
    for (int j = 2; j <= (n/2+1); j++)
    {
        if (n%j == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
/*
求出n以内的所有质数
质数从1开始，2为边界
*/
void f1(vector<int> &a, int n)
{
    bool flag = false;
    for (int i = 1; i <= n; i+=2)
    {
        flag = f0(i);       
        if (flag)
        {
            a.push_back(i);
        }
    }
}

int main()
{
    int n, res;
    vector<int> all;
    
    
    cin >> n;
    res = 0;
    f1(all, n);
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = i+1; j < all.size(); j++)
        {
            if (all[i]+all[j] == n)
            {
                res++;
            }
        }
    }
    /*如果中位数是奇数*/
    if (n%2==0 && f0(n/2))
        res++;
    cout << res;
    system("pause");
    return 0;
}