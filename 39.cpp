#include <iostream>
#include <string>

using namespace std;

/*
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
*/

/*
输入描述:
每个测试输入包含2个字符串

输出描述:
输出删除后的字符串
*/

/*
思路：字符串的拼接
将字符串挨个字符打印，如果在字符串2中则不打印
*/
int main()
{
    string str1, str2;
    bool ExistFlag = false;
    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str1.size(); i++)
    {
        ExistFlag = false;
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                ExistFlag = true;
                break;
            }
        }
        if (!ExistFlag)
            cout << str1[i];
    }
    system("pause");
    return 0;
}