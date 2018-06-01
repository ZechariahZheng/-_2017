#include <iostream>
#include <algorithm>
#include <queue>
#inlcude <limits.h>

using namespace std;

/*给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，要求每一步都不可以超过地牢的边界，也不能到达障碍上。
地牢的出口可能在任意某个可以通行的位置上。牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。*/

/*求源节点到所有节点的最短路径(BFS)，找到距离最远的可通行点*/

/*BFS：使用一个队列保存现在的所有可能*/

int n,m;                //地图的长和宽
char map[55][55];        //地图的状态
int num;                //移动步长的总数
int way[55][2];         //每次可以移动的步长
int dis[55][55];        //到达每个点的路径长度

struct Point {
    int x;
    int y;
    Point() {}
    Point(int _x, int _y):x(_x), y(_y){}
    Point next(int index)                       //下一个点
    {
        return Point(x+way[index][0], y+way[index][1]);
    }
    bool IsOk()                                //这个点是否可以走
    {
        return x>=0&&y>=0&&x<n&&y<m&&map[x][y]=='.';
    }
};

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
    }
    Point start;        //起点
    scanf("%d%d", &start.x, &start.y);
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d%d", &way[i][0], &way[i][1]);
    }
    fill(dis[0], dis[54]+55, INT_MAX);
    dis[start.x][start.y] = 0;
    
    /*进行BFS遍历所有的节点，并保存下最大的路径数*/
    queue<Point> q;
    Point tmp;
    Point next;
    q.push(start);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        /*尝试所有的走法*/
        for (int i = 0; i < num; i++)
        {
            next = tmp.next(i);
            if (next.IsOk())
            {
                if (dis[next.x][next.y] > dis[tmp.x][tmp.y]+1)
                {
                    dis[next.x][next.y] = dis[tmp.x][tmp.y]+1;
                    q.push(next);
                }
            }
        }
    }
    
    /*找出最大值*/
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.')
                result = max(result, dis[i][j]);
        }
    }
    printf("%d\n", result==INT_MAX?-1:result);
    system("pause");
    return 0;
}