#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/*
战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。
首都位于一个四面环山的盆地中，周围的n个小山构成一个环，作为预警措施，小B计划在每个小山上
设置一个观察哨，日夜不停的瞭望周围发生的情况。 一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，
若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，则岗哨可以观察到另一个山峰上
的烽烟是否点燃。由于小山处于环上，任意两个小山之间存在两个不同的连接通路。满足上述不遮挡的条
件下，一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。对于任意相邻的岗哨，一端的
岗哨一定可以发现一端点燃的烽烟。 小B设计的这种保卫方案的一个重要特性是能够观测到对方烽烟的岗
哨对的数量，她希望你能够帮她解决这个问题。
*/

/*
输入描述:
输入中有多组测试数据，每一组测试数据的第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，
第二行为n个整数，依次表示为小山的高度h（1<=h<=10^9）.

输出描述:
对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。
*/

/*
思路：取两座山峰作为两端，当两端的最小值大于中间山峰中的最大值时，这两座山峰是可以相互瞭望到的
*/

int main()
{
    int n;
    cin >> n;
    vector<long long> array(n);
    long long result = 0;
    
    for (int i = 0; i < n; i++)
        cin >> array[i];
    result = n;
    for (int i = 0; i < n; i++)
    {
        long long a = array[i];
        /*选取另一个数*/
        for (int j = i+2; j-i!=n-1&&j<n; j++)
        {
            long long b = array[j];
            long long MinNum = min(a, b);
            long long MaxNum = INT_MIN;
            for (int k = i+1; k < j; k++)
            {
                if (MaxNum < array[k])
                    MaxNum = array[k];
            }
            if (MaxNum!=INT_MIN && MaxNum<=MinNum)
                result++;
            else
            {
                MaxNum = INT_MIN;
                for (int k = j+1; k < n; k++)
                {
                    if (MaxNum < array[k])
                        MaxNum = array[k];
                }
                for (int k = 0; i>=1&&k<=i-1; k++)
                {
                    if (MaxNum < array[k])
                        MaxNum = array[k];
                }
                if (MaxNum!=INT_MIN && MaxNum<=MinNum)
                    result++;
            }
        }
    }
    cout << result << endl;
    system("pause");
    return 0;
}