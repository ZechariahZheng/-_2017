#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 有m批客人，每批客人有两个参数:b人数，
c预计消费金额。 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大
*/

/*
输入描述:
输入包括m+2行。 第一行两个整数n(1 <= n <= 50000),m(1 <= m <= 50000) 第二行为n个参数a,即每个桌子
可容纳的最大人数,以空格分隔,范围均在32位int范围内。 接下来m行，每行两个参数b,c。分别表示第i批客
人的人数和预计消费金额,以空格分隔,范围均在32位int范围内。

输出描述:
输出一个整数,表示最大的总预计消费金额
*/

/*
思路：
1、超出桌子最大人数的批次直接pass
2、从剩余的批次中选出出价的n个，且每个批次要放的下，且每次让其坐入最合适的位置中
*/

bool func(vector<int>a, vector<int>b)
{
    if (a[1] > b[1])
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    int ren, money;
    vector<vector<int> > all;
    int aMax = -1;
    int res = 0;
    int atmp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> atmp;
        a.push_back(atmp);
        if (atmp > aMax)
            aMax = atmp;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> ren >> money;
        vector<int> tmp;
        tmp.push_back(ren);
        tmp.push_back(money);
        if (ren <= aMax)
            all.push_back(tmp);
    }
    /*排序应该按现金的多少来进行*/
    sort(all.begin(), all.end(), func);
    m = 0;
    for (int i = 0; i < all.size(); i++)
    {
        /*批次做的下*/
        if (all[i][0] <= aMax)
        {
            /*找出能做下的最匹配的桌子*/
            float nice = 0;
            for (int j = 0; j < a.size(); j++)
            {
                float tmp = ((float) all[i][0])/a[j];
                if (nice<tmp && tmp<=1 && tmp>0)
                    nice = ((float) all[i][0])/a[j];
            }
            /*删除该桌子*/
            float nictTmp = 0;
            for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
            {
                nictTmp = ((float) all[i][0]) / *it;
                if (nice == nictTmp)
                {
                    //cout << "table is: " << *it << endl;
                    *it = -1;
                    break;
                }
            }

            /*重新找出最大的桌子*/
            aMax = 0;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] > aMax)
                {
                    aMax = a[j];
                }
            }
            res += all[i][1];
            //cout << "ren is: " << all[i][0] << " money is: " << all[i][1] << endl;
            m++;
            if (m == n)
                break;
        }
    }
    cout << res;
    system("pause");
    return 0;
}