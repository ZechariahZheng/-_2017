#include <iostream>
#include <vector>

using namespace std;

/*
牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，
其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，顺序对
是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
*/

/*
输入描述:
每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），
接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。

输出描述:
输出一行表示合法的排列数目。
*/

/*思路：（穷举法）
列出全部可能的排列方法，统计其合法的数目*/

vector<vector<int> > all;        //全排列的可能


/*全排列算法
(1)n个元素的全排列=（n-1个元素的全排列）+（另一个元素作为前缀）；
(2)出口：如果只有一个元素的全排列，则说明已经排完，则输出数组；
(3)不断将每个元素放作第一个元素，然后将这个元素作为前缀，并将其余元素继续全排列，等到出口，出口出去后还需要还原数组；*/
void permutation(int *a, int k, int m)
{
    int i, j;
    if (k == m)
    {
        /*排完了*/
        vector<int> allTmp;
        for (int i = 0; i <= m; i++)
        {
            allTmp.push_back(a[i]);
        }
        all.push_back(allTmp);
        return;
    }
    else
    {
        for (j = k; j <=m; j++)
        {
            swap(a[j], a[k]);           //for循环将数组中的每个元素放到第一个位置
            permutation(a, k+1, m);     //假设第一位置已确定，那么对剩余的数继续递归
            swap(a[j], a[k]);           //还原回去
        }
    }
}

/*检查是否满足要求，统计顺序对的数量*/
bool func(int *a, int n, long k)
{
    long result = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                result++;
        }
    }
    if (result == k)
        return true;
    return false;
}

int main()
{
    int a[105];     //保存数列输入
    int n;          //总数
    long k;         //数列对的数目
    int b[11];      //看不清的位置
    int c[11];      //缺少的数
    
    scanf("%d%ld", &n, &k);
    /*统计下不清楚的位置*/
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a+i);
        if (a[i] == 0)
        {
            b[j] = i;
            j++;
        }
    }
    /*统计缺少的数*/
    bool ExistFlag = false;
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        ExistFlag = false;
        for (int j = 0; j < n; j++)
        {
            if (i == a[j])
            {
                ExistFlag = true;
                break;
            }
        }
        if (ExistFlag == false)
            c[m++] = i;
    }
    /*穷举所有的排序方法*/
    permutation(c, 0, m-1);
    int result = 0;
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all[i].size(); j++)
        {
            a[b[j]] = all[i][j];
        }
        /*检查是否符合要求*/
        if (func(a, n, k))
            result++;
    }
    cout << result;
    system("pause");
    return 0;
}