/*
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。

输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)
输出描述:
输出保留下来的结果。
*/

/*
思路：
从左到右开始找到第一个小于自己右边的
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    int n;
    
    cin >> str >> n;
    while (n--)
    {
        int i;
        int slen = str.size();
        for (i = 0; i < slen-1; i++)
        {
            /*找到第一个小于自己右边相邻数的数*/
            if (str[i] < str[i+1])
            {
                //使用string的erase方法，删除下标为i的数
                str.erase(str.begin()+i);
                break;
            }
        }
        //当i为数组最后一个数时，删除最后一个数
        if (i == slen-1)
            str.erase(str.end()-1);
    }
    cout << str << endl;
    system("pause");
    return 0;
}