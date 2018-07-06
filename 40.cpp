#include <iostream>
#include <vector>

using namespace std;

/*
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来

输入描述:
每个测试输入包含2个整数,n和m

输出描述:
按每个组合的字典序排列输出,每行输出一种组合
*/

/*
思路：牛客网答案（dfs）
*/

void f(int n, int m, vector<int> &v, int begin)
{
    /*如果m为0，说明相加找到了*/
    if (m == 0)
    {
        for (int i = 0; i < v.size(); i++)
            i==0 ? cout << v[i] : cout << " " << v[i];
        cout << endl;
    }
    for (int i = begin; i<=n&&i<=m; i++)
    {
        v.push_back(i);
        f(n, m-i, v, i+1);
        v.pop_back();
    }
}

/*
这种方法：是背包问题
问题其实本质上就是0/1背包问题，对于每一个n，我们采用贪婪策略，先考察是否取n，
如果取n，那么子问题就变成了find(n-1,m-n)，而如果舍弃n，子问题则为find(n-1,m)。
至此，我们利用DP思想找到了递归式（很多时候，所谓动态规划，贪婪只是一念之差）。

那么，如何制定解的判定策略？我们知道，递归需要边界条件，而针对背包问题，边界条件只有两种，
如果n<1或者m<1，那么便相当于“溢出”，无法combo出m，而另一种可能就是在剩余的n个里恰好满足m==n，
即此时 背包刚好填充满，输出一组解单元。除此之外，再无其他。
*/

/*
注：背包问题的方法求解使用二维数组的动态规划，求每种方法则使用递归方法
*/
void f2(int n, int m, int *flag)
{
    if (n<1 || m<1)
        return;
    if (n > m)
        n = m;
    /*即此时背包被填满*/
    if (n == m)
    {
        flag[n-1] = 1;
        for (int i = 0; i < length; i++)
            if (flag[i] == 1)
                cout << i+1;
        cout << endl;
        flag[n-1] = 0;
    }
    flag[n-1] = 1;
    f2(n-1, m-n, flag);
    flag[n-1] = 0;
    f2(n-1, m, flag);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> result;
    f(n, m, result, 1);
    system("pause");
    
    return 0;
}