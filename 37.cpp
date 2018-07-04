#include <iostream>
#include <vector>

using namespace std;

/*
输入n个整数，输出出现次数大于等于数组长度一半的数。

输入描述:
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。

输出描述：
输出出现次数大于等于n/2的数。
*/

/*
思路：
统计出不同的数字，且每个数字出现的个数
*/

int main()
{
    vector<int> input;
    vector<int> DifNum, ShowTime;
    int tmp;
    while (cin>>tmp)
        input.push_back(tmp);
    bool ExistFlag = false;
    for (int i = 0; i < input.size(); i++)
    {
        ExistFlag = false;
        for (int j = 0; j < DifNum.size(); j++)
        {
            if (input[i] == DifNum[j])
            {
                ExistFlag = true;
                ShowTime[j]++;
                break;
            }
        }
        if (ExistFlag == false)
        {
            DifNum.push_back(input[i]);
            ShowTime.push_back(1);
        }
    }
    int n = input.size();
    for (int i = 0; i < ShowTime.size(); i++)
    {
        if (ShowTime[i] > (n/2))
        {
            cout << DifNum[i];
            break;
        }
    }
    system("pause");
    return 0;
}