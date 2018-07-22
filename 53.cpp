#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
现在有一个数组，其值为从1到10000的连续增长的数字。出于某次偶然操作，
导致这个数组中丢失了某三个元素，同时顺序被打乱，现在需要你用最快的
方法找出丢失的这三个元素，并且将这三个元素根据从小到大重新拼接为一
个新数字，计算其除以7的余数。 例：丢失的元素为336，10，8435，得到的新数字为103368435，除以七的余数为2。
*/

/*
输入描述:
输入数据为一行，包含9997个数字，空格隔开。

输出描述:
输出为一行，包含一个数字。
*/

/*
思路：
挨个遍历整个数组，寻找3个元素
*/
int a[10001] = {0};

int main()
{
    int tmp;
    for (int i = 0; i < 9997; i++)
    {
        cin >> tmp;
        a[tmp] = 1;
    }
    string res = " ", s;
    long long sum;
    for (int j = 0; j < 10000; j++)
    {
        if (a[j] == 0)
        {
            stringstream ss;
            ss << j;
            ss >> s;
            res += s;
        }
    }
    stringstream ss;
    ss << res;
    ss >> sum;
    cout << sum%7 << endl;
    system("pause");
    
    return 0;
}