#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
请设计一个算法能够完成两个用字符串存储的整数进行相加操作，对非法的输入则返回error

输入描述:
输入为一行，包含两个字符串，字符串的长度在[1,100]。

输出描述:
输出为一行。合法情况输出相加结果，非法情况输出error
*/

/*
思路：字符串挨个字符相加，判断相加是否超过10
*/

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i]>='0' && a[i]<='9')
            continue;
        else;
        {
            cout << "error" << endl;
            system("pause");
            return 0;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i]>='0' && b[i]<='9')
            continue;
        else;
        {
            cout << "error" << endl;
            system("pause");
            return 0;
        }
    }
    string ret;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i>=0 && j>=0)
    {
        int sum = (a[i]-'0')+(b[j]-'0')+carry;
        carry = sum/10;
        sum = sum%10;
        ret += to_string(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = (a[i]-'0')+carry;
        carry = sum/10;
        sum = sum%10;
        ret = ret + to_string(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = (b[j]-'0')+carry;
        carry = sum/10;
        sum = sum%10;
        ret = ret+to_string(sum);
        j--;
    }
    if (carry)
        ret = ret+to_string(carry);
    reverse(ret.begin(), ret.end());
    system("pause");
    return 0;
}