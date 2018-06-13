#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
*/

/*
输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)

输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
*/

/*
思路：
利用宽度搜索，步长变为约数
*/

//求约数
vector<int> func(int n)
{
    vector<int> result;
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
            result.push_back(i);
    }
    return result;
}

//宽搜
int bfs(int start, int aim)
{
    queue<int> q;           //临时队列
    vector<int> qall;       //队列
    int result = 0;
    int pre, next;
    vector<int> len;
    map<int, int> all;      //保存到达每个点时所需的次数
    all[start] = 0;
    q.push(start);
    qall.push_back(start);
    
    while (!q.empty())
    {
        pre = q.front();
        /*获得步长*/
        len = func(pre);
        for (int i = 0; i < len.size(); i++)
        {
            next = pre+len[i];
            if (next == aim)
            {
                /*到达终点*/
                result = all[pre]+1;
                return result;
            }
            else
            {
                /*未到达终点*/
                if (find(qall.begin(), qall.end(), next) == qall.end())
                {
                    q.push(next);
                    qall.push_back(next);
                    all[next] = all[pre]+1;
                }
            }
        }
        q.pop();
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m);
    system("pause");
    
    return 0;
}