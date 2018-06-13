#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。
*/

/*
输入描述:
输入为一个整数，即为圆半径的平方,范围在32位int范围内。

输出描述:
输出为一个整数，即为优雅的点的个数
*/

/*
思路：
遍历一个象限即可
*/
int main()
{
    int n;
    int r;
    int result = 0;
    cin >> n;
    r = (int)sqrt((double)n);
    if (sqrt((double)n) > r)
    {
        for (int i = 0; i <= r; i++)
        {
            double j = sqrt((double)n-i*i);
            if (j <= (int)j)                 //整数
                result++;
        }
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            double j = sqrt((double)n-i*i);
            if (j <= (int)j)                 //整数
                result++;
        }
    }
    result *= 4;
    cout << result;
    system("pause");
    return 0;
}