#include <iostream>
#include <vector>

using namespace std;

/*
题目描述：
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。

输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
*/

/*
思路：
将十进制数转换为n进制数，即除n即可
临时生成的各位的数字保存在数组之中
*/

/*生成的数字保留在数组之中*/
vector<int> func(long m, int n)
{
    vector<int> res;
    int tmp;
    long div = 1;
    int wei = 1;
    
    /*先确定最高位*/
    while (1)
    {
        div = 1;
        tmp = wei;
        while (tmp--)
            div *= n;
        if (m/1<n)
        {
            wei = 0;
            break;
        }
        if (m/div<n && m/div>0)
            break;
        else
            wei++;
    }
    /*确定每个位上的数字，从高到低*/
    for (int i = wei; i >= 1; i--)
    {
        int tmpI = i;
        div = 1;
        while (tmpI--)
            div *= n;
        tmp = m/div;
        m %= div;
        res.push_back(tmp);
    }
    res.push_back(m);
    return res;
}

int main()
{
    long m;
    int n;
    vector<int> res;
    
    cin >> m >> n;
    /*进制转换*/
    if (m > 0)
        res = func(m, n);
    else
    {
        res = func(-m, n);
        cout << "-";
    }
    for (int i = 0; i < res.size(); i++)
    {
        switch(res[i])
        {
            case 10: cout<< "A";
                     break;
            case 11: cout << "B";
                     break;
            case 12: cout << "C";
                     break;
            case 13: cout << "D";
                     break;
            case 14: cout << "E";
                     break;
            case 15: cout << "F";
                     break;
            default: cout << res[i];
                     break;
        }
    }
    system("pause");
    return 0;
}