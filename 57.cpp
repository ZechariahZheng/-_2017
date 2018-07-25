#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
Please create a function to extract the filename extension from the given path,return the extracted filename extension 
or null if none.Please create a function to extract the filename extension from the given path,return the extracted filename extension or null if none.
*/

/*
输入描述:
输入数据为一个文件路径

输出描述:
对于每个测试实例，要求输出对应的filename extension
*/

/*
思路：获取字符串的"."之后的字符，采用倒叙
*/

int main()
{
    string str;
    cin >> str;
    string res;
    bool flag = false;
    for (int i = str.size()-1; i > 0; i--)
    {
        if (str[i] == '.')
        {
            flag = true;
            break;
        }
        else
        {
            char what[2] = {str[i], '\0'};
            string tmp(what);
            res += tmp;
        }
    }
    if (flag)
    {
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    else
        cout << "none" << endl;
    system("pause");
    return 0;
}