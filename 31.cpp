#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,
小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出
口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水
平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,向下移
动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。现在需
要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
*/

/*
输入描述:
输入包括n+1行:
第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
接下来的n行:
每行m个0或者1,以空格分隔

输出描述:
如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输
出"Can not escape!"。 测试数据保证答案唯一
*/

/*
思路：
宽搜+限制条件
宽搜记录路径：只要保留上一个父节点的信息即可
*/

/*
参数：
a:表示地图
p:剩余的体力值
*/
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dp[] = {-3, 0, -1, -1};
struct Node {
    int x;
    int y;
    int flag;           //是否可以访问标志位
    int PreX;
    int PreY;
    int p;              //每个节点的体力值
    Node(int a, int b, int c, int d, int e, int f):x(a),y(b),flag(c),PreX(d),PreY(e),p(f)
    {}
};

/*回溯*/
void Output(Node &end, vector<vector<Node> > &map)
{
    stack<Node> s;
    while (!(end.x==0 && end.y==0))
    {
        Node tmp = end;
        s.push(tmp);
        end = map[end.PreX][end.PreY];
    }
    s.push(map[0][0]);
    while (s.size() > 1)
    {
        Node tmp = s.top();
        printf("[%d,%d],", tmp.x, tmp.y);
        s.pop();
    }
    Node tmp = s.top();
    printf("[%d,%d]",tmp.x, tmp.y);
}

/*宽搜*/
bool bfs(vector<vector<Node> > &map, int n, int m, int p)
{
    queue<Node> q;
    map[0][0].p = p;
    q.push(map[0][0]);           //输入起点

    while (!q.empty())
    {
        Node tmp = q.front();
        map[tmp.x][tmp.y].flag = 0;           //标记为走过的
        //cout << "loc is: " << tmp.x << " " << tmp.y << " " << "p is: " << tmp.p << endl;

        for (int i = 0; i < 4; i++)
        {
            int x = tmp.x + dx[i];
            int y = tmp.y + dy[i];
            if (x<=n-1 && x>=0 && y>=0 && y<=m-1)
                map[x][y].p = tmp.p + dp[i];
            /*确定该位置是否可以访问*/
            if (x<=n-1 && x>=0 && y>=0 && y<=m-1 && map[x][y].flag==1 && map[x][y].p>=0)
            {
                map[x][y].PreX = tmp.x;
                map[x][y].PreY = tmp.y;
                map[x][y].flag = 0;
                q.push(map[x][y]);
                /*判断是否为目标位置*/
                if (map[x][y].x==0 && map[x][y].y==m-1)
                {
                    Output(map[x][y], map);
                    return true;
                }
            }
            
        }
        q.pop();
    }
    return false;
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<Node> > map;          //地图信息 
    for (int i = 0; i < n; i++)
    {
        vector<Node> tmpV;
        for (int j = 0; j < m; j++)
        {
            int flag;
            cin >> flag;
            Node tmp(i, j, flag, -1, -1, -1);
            tmpV.push_back(tmp);
        }
        map.push_back(tmpV);
    }
    /*宽搜*/
    if (!bfs(map, n, m, p))
        cout << "Can not escape!" << endl;
    system("pause");
    return 0;
}