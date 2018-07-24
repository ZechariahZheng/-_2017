#include <iostream>
#include <vector>

using namespace std;

/*
有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。
请设计一个算法，计算小团有多少种走法。给定两个正整数int x,int y，请返回小团的走法数目。
*/

/*
输入描述:
输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。

输出描述:
输出包括一行，为走法的数目。
*/

/*
思路：深度搜索
*/
int dfs(int x, int y, int end_x, int end_y, int cnt)
{
    if (x==end_x && y==end_y)
    {
        cnt++;
        return cnt;
    }
    for (int i = 0; i < 2; i++)
    {
        int next_x, next_y;
        if (i == 0)         //向下走
        {
            next_x = x+1;
            next_y = y;
        }
        else
        {
            next_x = x;
            next_y = y+1;
        }
        if (next_x<=end_x && next_y<=end_y)         //只要不出边界，则进dfs
        {
            cnt = dfs(next_x, next_y, end_x, end_y, cnt);
        }
    }
    return cnt;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << dfs(0, 0, x, y, 0) << endl;
    system("pause");
    
    return 0;
}