#include <iostream>
#include <vector>

using namespace std;

/*
使用动态规划
用两个二维数组分别记录，两座山峰顺时针方向和逆时针方向，中间山峰的最大高度
然后遍历一次山峰对，求出满足条件的对数；既是两座山峰间山峰的最大高度同时小于等于它们，这里是一个环，因此要考虑逆时针和顺时针方向，
只要有一个条件满足就可以
*/

int main()
{
    int n;
    
    while (cin >> n)
    {
        int heights[n];
        vector<vector<int> >dpClock(n, vector<int>(n, 0));      //顺时针方向，两座山峰间的最大高度
        vector<vector<int> >dpReClock(n, vector<int>(n, 0));    //逆时针方向，两座山峰间的最大高度
        int res = 0;
        
        for (int i = 0; i < n; i++)         //自己和自己中间是没有的，所以是0
        {
            cin >> heights[i];
            dpClock[i][i] = 0;
            dpReClock[i][i] = 0;
        }
        
        for (int i = 0; i < n; i++)         //相邻两座山峰中间也是没有山峰的，最大高度是0
        {
            dpClock[i][(i+1)%n] = 0;
            dpReClock[i][(i-1+n)%n] = 0;
        }
        
        for (int k = 2; k < n; k++)         //长度为k+1的山峰链，从3开始
        {
            for (int i = 0; i < n; i++)     //山峰链：顺时针:[i, i+k] 逆时针：[i-k, i]
            {
                /*
                    (i, i+k)间的最高山峰高度，分为两种情况
                    1、如果(i, i+k-1)间的最高山峰低于新增加的第i+k-1座山峰，那么更新最大高度为新增加的i+k-1座山峰的高度
                    2、否则，依然是(i, i+k-1)间的最大高度
                    同时因为是环，所以要做特殊处理，越界时直接mod
                */
                dpClock[i][(i+k)%n] = heights[(i+k-1)%n] > dpClock[i][(i+k-1)%n] ? heights[(i+k-1)%n] : dpClock[i][(i+k-1)%n];
                dpReClock[i][(i-k+n)%n] = heights[(i-k+1+n)%n] > dpClock[i][(i-k+1)%n] ? heights[(i-k+1+n)%n] : dpClock[i][(i-k+1)%n];
            }
        }
        
        for (int i = 0; i < n; k++)
        {
            for (int k = 0; k < n; k++)
            {
                /*
                    排除自己看见自己的情况
                    如果两座山峰间，无论逆时针还是顺时针，中间所有山峰的高度都不大于它们中任意一个，那么计数+1
                */
                if (i!=k && 
                    ((dpClock[i][k]<=heights[i]&&dpClock[i][k]<=heights[k]) || (dpReClock[i][k]<=heights[i]&&dpReClock[i][k]<=heights[k]))
                    )
                    res++;
            }
        }
        cout << res/2 << endl;          //注意这里求的是对数
    }
    
    return 0;
}