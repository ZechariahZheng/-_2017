#include <iostream>

using namespace std;

/*
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最
少需要多少步可以变为Fibonacci数。
*/

/*
输入描述:
输入为一个正整数N(1 ≤ N ≤ 1,000,000)

输出描述:
输出一个最小的步数变为Fibonacci数"
*/

/*思路：
求一个数离最近的Fibonacci数的距离

Fibonacci求解：使用动态规划
动态规划：一旦某个给定子问题的解已经算出，则将其记忆化存储，以便下次需要同一个子问题解之时直接查表。
这种做法在重复子问题的数目关于输入的规模呈指数增长时特别有用
*/

//求Fibonacci数
long fib(int n, long target)
{
    long result = 1;
    long tmp_1 = 1;
    long tmp_2 = 0;
    long min = 1000000;
    long tmpmin;
    for (int i = 2; i <=n; i++)
    {
        result = tmp_1+tmp_2;
        if (result < target)
            tmpmin = target-result;
        else
            tmpmin = result-target;
        if (min > tmpmin)
            min = tmpmin;
        tmp_2 = tmp_1;
        tmp_1 = result;
    }
    return min;
}

int main()
{
    long n;
    cin >> n;
    
    cout << fib(40, n);
    system("pause");
    return 0;
}