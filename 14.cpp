#include <iostream>
#include <map>
#include <queue>

using namespace std;

/*
小易总是感觉饥饿，所以作为章鱼的小易经常出去寻找贝壳吃。最开始小易在一个初始位置x_0。
对于小易所处的当前位置x，他只能通过神秘的力量移动到 4 * x + 3或者8 * x + 7。因为使用
神秘力量要耗费太多体力，所以它只能使用神秘力量最多100,000次。贝壳总生长在能被1,000,000,007
整除的位置(比如：位置0，位置1,000,000,007，位置2,000,000,014等)。小易需要你帮忙计算最
少需要使用多少次神秘力量就能吃到贝壳。
*/

/*
输入描述:
输入一个初始位置x_0,范围在1到1,000,000,006

输出描述:
输出小易最少需要使用神秘力量的次数，如果使用次数使用完还没找到贝壳，则输出-1
*/

/*思路：
宽度搜索求最短路径

利用哈希表存储已访问的点，使用队列存储待访问的点
其中每个哈希表的元素中存储着已访问点，所走过的路径长度*/


int bfs(int start)
{
    long result = 0;
    map<long long, long> node;  //已访问点的map
    queue<long long> q;         //队列
    q.push(start);
    node[start] = 0;
    
    long long x[2], tmp;
    while (!q.empty())
    {
        /*第一种走法*/
        tmp = q.front();
        x[0] = 4*tmp+3;
        x[1] = 8*tmp+7;
        if (node[tmp] > 100000)         //超过限制返回
            return -1;
        for (int i = 0; i < 2; i++)
        {
            if (x[i]%1000000007 == 0)
            {
                node[x[i]] = node[tmp]+1;
                /*第一次找到终点，即是最短路径*/
                result = node[x[i]];
                return result;
            }
            else
            {
                /*未找到，且未访问过*/
                if (node.find(x[i]) == node.end())
                {
                    node[x[i]] = node[tmp]+1;
                    q.push(x[i]);
                }
            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    long long x_0;
    scanf("%lld", &x_0);
    long result = 0;
    
    result = bfs(x_0);
    if (result < 100000)
        cout << result;
    else
        cout << "-1";
    system("pause");
    
    return 0;
}