#include <iostream>
#include <memory.h>

using namespace std;

/*
牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以看成是一个矩形，
每个位置有一个价值。分割田地的方法是横竖各切三刀，分成 16 份，作为领导干部，牛牛总是会选择
其中总价值最小的一份田地， 作为牛牛最好的朋友，你希望牛牛取得的田地的价值和尽可能大，
你知道这个值最大可以是多少吗？

输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 75），表示
田地的大小，接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示每块位置的价值。

输出描述:
输出一行表示牛牛所能取得的最大的价值。*/

/*思路：二分+枚举
二分范围：0至所有田地价值和
可行性判断（关键）：假定二分值为mid。暴力枚举竖切的位置（三重循环），然后看横切能切多少刀。
枚举横切时，当这部分的4个矩形（新的一横与上面一横之间被竖着的边界以及竖切三刀形成的四个矩形）的价值都大于等于mid，
说明这一刀切得合理，从这个位置开始继续往下枚举横切。如果最终横切的刀数大于等于4，那么说明这个值mid是合理的，否则不合理。
通过这样的不断压缩区间，最终必然能够得到答案。*/

int n,m;                //矩阵的长和宽
int a[80][80];          //矩阵的数值大小
int sum[80][80];        //sum[i][j]: 从左上角(1, 1)到(i,j)的方块总和
char tmp[80];

int area1, area2, area3, area4;

/*获得(x2, y2)到(x1, y1)对角线形成的方块大小
x1,x2: 横
y2,y2：竖*/
int getArea(int x1, int y1, int x2, int y2)
{
    return (sum[x2][y2]+sum[x1][y1]-sum[x1][y2]-sum[x2][y1]);
}

bool Judge(int mid)
{
    /*暴力枚举竖切的位置*/
    for (int i = 1; i <= m-3; i++)
    {
        for (int j = i+1; j <= m-2; j++)
        {
            for (int k = j+1; k <= m-1; k++)
            {
                /*枚举所有竖切，所有的新的一横与上面一横之间被竖着的边界以及竖切三刀形成的四个矩形，是否都大于mid*/
                int preX = 0;       //先前一横的位置
                int cnt = 0;        //
                for (int x = 1; x <= n; x++)
                {
                    area1 = getArea(preX, 0, x, i);             //先前一横与边界，和第一个竖切及x位置横切围成的
                    area2 = getArea(preX, i, x, j);
                    area3 = getArea(preX, j, x, k);
                    area4 = getArea(preX, k, x, m);
                    if (area1>=mid && area2>=mid && area3>=mid && area4>=mid)
                    {
                        preX = x;
                        cnt += 1;
                    }
                }
                if (cnt >= 4)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)        //获得输入矩阵的大小
    {
        for (int i = 1; i <= n; i++)     //获得输入矩阵的值
        {
            scanf("%s",tmp+1);
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = tmp[j]-'0';
            }
        }
        /*计算所有sum的大小*/
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
            }
        }
        /*二分*/
        int mid;            //中值
        int low, high;      //上限和下限
        int result = 0;         //结果
        high = sum[n][m];
        low = 0;
        while (low <= high)
        {
            mid = (low+high)/2;
            /*判断mid值是否划分合理*/
            if (Judge(mid))
            {
                low = mid+1;
                result = mid;
            }
            else
            {
                high = mid-1;
            }
        }
        cout << result << endl;
    }
    return 0;
}