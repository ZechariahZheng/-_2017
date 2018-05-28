#include <iostream>
#include <algorithm>

using namespace std;

/*
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，
使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗

输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，
接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。

输出描述:
输出一行表示最大的乘积。

输入：
3
7 4 7
2 50

输出：
49
*/

/*
思路：动态规划问题
MaxVal[i][j]: 表示最后一个同学选择了第i个同学，且选择了已经选了j个同学的最大乘积
MinVal[i][j]: 表示最后一个同学选择了第i个同学，且选择了已经选了j个同学的最小乘积

状态转移方程:
MaxVal[i][j] = max(MaxVal[i][j], max(MaxVal[x][j-1]*a[i], MinVal[x][j-1]*a[i]))
MinVal[i][j] = min(MinVal[i][j], min(MaxVal[x][j-1]*a[i], MinVal[x][j-1]*a[i]))
*/
long long MaxVal[50][10];
long long MinVal[50][10];

int main()
{
    int n;      //输入同学的数量
    int k, d;   //k--选取同学的数量，d间隔
    long long res = 0;
    
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k >> d;
    /*赋值*/
    for (int i = 0; i < n; i++)
        MaxVal[i][0] = MinVal[i][0] = a[i];
    
    /*动态规划*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            for (int q = i-1; q >= max(i-d, 0); q--)
            {
                MaxVal[i][j] = max(MaxVal[i][j], max(MaxVal[q][j-1]*a[i], MinVal[q][j-1]*a[i]));
                MinVal[i][j] = min(MinVal[i][j], min(MaxVal[q][j-1]*a[i], MinVal[q][j-1]*a[i]));
            }
        }
        res = max(res, max(MaxVal[i][k-1], MinVal[i][k-1]));
    }
    cout << res;
    free(a);
    system("pause");
    return 0;
}