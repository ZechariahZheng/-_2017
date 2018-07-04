#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
读入一个字符串str，输出字符串str中的连续最长的数字串

输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。

输出描述:
在一行内输出str中里连续最长的数字串。
*/

/*
思路：
只要字符的范围在0~9之间就可以了，将结果保存在一个vector数组中
*/

int main()
{
    string str;
    cin >> str;
    vector<char> res;
    vector<char> tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i]>='0' && str[i]<='9')
            tmp.push_back(str[i]);
        else
            tmp.clear();
        if (tmp.size() > res.size())
            res = tmp;
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    system("pause");
    return 0;
}