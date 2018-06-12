#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，
从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把这2n张牌分成两
堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接
着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放
下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。
接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分
成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。
把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 
现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
*/

/*
输入描述:
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，
接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。

输出描述:
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
*/

/*思路：
使用栈来解决*/

int main()
{
    int m;      //测试的组数
    cin >> m;
    vector<vector<int> > result;
    stack<int> left, right;
    vector<int> resultTmp;
    int tmp;
    int n, k;
    for (int i = 0; i < m; i++)
    {
        cin >> n >> k;
        /*清空左右栈*/
        stack<int> leftTmp, rightTmp;
        swap(left, leftTmp);
        swap(right, rightTmp);
        for (int j = 0; j < 2*n; j++)
        {
            scanf("%d", &tmp);
            if (j < n)
                left.push(tmp);
            else
                right.push(tmp);
        }
        for (int j = 0; j < k; j++)
        {
            int leftsize = left.size();
            int rightsize = right.size();
            resultTmp.clear();
            for (int q = 0; q < rightsize; q++)
            {
                tmp = right.top();
                resultTmp.push_back(tmp);
                right.pop();
                tmp = left.top();
                resultTmp.push_back(tmp);
                left.pop();
            }
            reverse(resultTmp.begin(), resultTmp.end());
            for (int q = 0; q < resultTmp.size(); q++)
            {
                if (q < (resultTmp.size()+1)/2)
                    left.push(resultTmp[q]);
                else
                    right.push(resultTmp[q]);
            }
        }
        result.push_back(resultTmp);
        resultTmp.clear();
    }
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size()-1)
                cout << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}