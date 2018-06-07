#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。为了让问题简单，
我们用正整数表示不同颜色的颜料。你知道这幅画需要的n种颜色的颜料，你现在可以去商店
购买一些颜料，但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。
混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以
用作继续混合产生新的颜色,XOR表示异或操作)。本着勤俭节约的精神，你想购买更少的颜料就
满足要求，所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？
*/

/*
输入描述:
第一行为绘制这幅画需要的颜色种数n (1 ≤ n ≤ 50)
第二行为n个数xi(1 ≤ xi ≤ 1,000,000,000)，表示需要的各种颜料.

输出描述:
输出最少需要在商店购买的颜料颜色种数，注意可能购买的颜色不一定会使用在画中，只是为了产生新的颜色。
*/

/*
思路：
利用行列式解决异或问题，利用行列式化简的方法（高斯消元）
求矩阵的秩
1、先将输入的数从大到小排序，在两个两个的数相减过去

高斯消元法：就是每次把要消去位上含有最大的元素的行调到最高的地方*/

/*得到某个数的最高位*/
int getHightBit(long num)
{
    int result = 0;
    while (num)
    {
        num = num >> 1;         //将数右移一位
        result++;
    }
    return result;
}

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    int n;          //输入的数
    vector<long> a;     //输入的数的值
    int result = 0;     //最终结果
    long tmp;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &tmp);
        a.push_back(tmp);
    }
    
    /*求矩阵的秩*/
    vector<long>::iterator it;
    while (a.size() >= 1)
    {
        sort(a.begin(), a.end(), cmp);          //从大到小排序
        /*如果剩余元素全部被消元*/
        if (a[0] == 0)
        {
            result += a.size();
            break;
        }
        
        it = a.begin();
        /*在数组中寻找最高位相同的数，找到后相减*/
        for (++it; it!=a.end(); it++)
        {
            if (getHightBit(*it) == getHightBit(a[0]))
                (*it) = (*it)^a[0];
            else
                break;      //第一个没有找到，剩余的肯定也没有，因为这是从大到小排好序的
        }
        a.erase(a.begin());     //擦除最高位
    }
    result = n - result;
    cout << result;
    system("pause");
    return 0;
}