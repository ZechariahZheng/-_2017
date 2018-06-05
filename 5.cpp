#include <iostream>
#include <stdio.h>

using namespace std;

/*
n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得
最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹
果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
*/

/*
思路：
1、算出平均值
2、统计出每个大于平均值的数的大于值，将大于值除以2,即是转移的次数，如果不能整除则输出-1
*/
int n;          //测试用例的个数
int a[105];

int main()
{
    int sum = 0;
    int ave = 0;
    int result = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum%n != 0)
        result = -1;
    /*0、计算平均值*/
    ave = sum/n;
    if (result == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > ave)
            {
                /*大于平均值*/
                if ((a[i]-ave)%2 == 0)          //能被2整除
                    result += (a[i]-ave)/2;
                else                            //不能被2整除
                {
                    result = -1;
                    break;
                }
            }
            else if (a[i] < ave)
            {
                /*小于平均值*/
                if ((ave-a[i])%2 != 0)
                {
                    result = -1;
                    break;
                }
            }
        }
    }
	printf("%d", result);
	system("pause");
    return 0;
}