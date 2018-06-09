#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
有一片1000*1000的草地，小易初始站在(1,1)(最左上角的位置)。小易在每一秒会横向
或者纵向移动到相邻的草地上吃草(小易不会走出边界)。大反派超超想去捕捉可爱的小
易，他手里有n个陷阱。第i个陷阱被安置在横坐标为xi ，纵坐标为yi 的位置上，小易
一旦走入一个陷阱，将会被超超捕捉。你为了去解救小易，需要知道小易最少多少秒可
能会走入一个陷阱，从而提前解救小易。
*/

/*
输入描述:
第一行为一个整数n(n ≤ 1000)，表示超超一共拥有n个陷阱。
第二行有n个整数xi，表示第i个陷阱的横坐标
第三行有n个整数yi，表示第i个陷阱的纵坐标
保证坐标都在草地范围内。

输出描述:
输出一个整数,表示小易最少可能多少秒就落入超超的陷阱
*/

/*思路：
尝试宽度搜索求最短路径
宽搜一般采用while循环
*/
char map[1000][1000];
/*bfs采用记录路径*/
struct Node {
    int x, y, pre;
}q[100];            //队列
int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

int BFS(int startX, int startY, int aimX, int aimY)
{
    int front = 0, rear = 1;        //队列的头尾
    int result = 0;                 //最终的结果
    memset(map, 0, sizeof(map));
    q[front].x = startX;
    q[front].y = startY;
    q[front].pre = -1;
    
    
    while (front < rear)
    {
        for (int i = 0; i < 4; i++)
        {
            int x = q[front].x + dir[i][0];
            int y = q[front].y + dir[i][1];
            if (x==aimX && y==aimY)
            {
                /*找到终点*/
                result++;
                while (q[front].x!=startX || q[front].y!=startY)
                {
                    result++;
                    front = q[front].pre;
                }
                return result;
            }
            else
            {
                if (x>=1 && x<=1000 && y>=1 && y<=1000 && map[x][y]==0)
                {
                    map[x][y] = 1;
                    q[rear].x = x;
                    q[rear].y = y;
                    q[rear].pre = front;
                    rear++;
                }
            }
        }
        front++;
    }
    return -1;
}

int main()
{
    int n;
    vector<int> X, Y;
    int tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        X.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        Y.push_back(tmp);
    }
    int minResult = INT_MAX;
    for (int i = 0; i < X.size(); i++)
    {
        int result = BFS(1, 1, X[i], Y[i]);
        if (result < minResult && result > 0)
            minResult = result;
    }
    cout << minResult;
    system("pause");
    return 0;
}