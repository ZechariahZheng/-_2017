/*
给定一个英文字符串,请写一段代码找出这个字符串中首先出现三次的那个英文字符(需要区分大小写)。

输入描述:
输入数据一个字符串，包括字母,数字等。

输出描述:
输出首先出现三次的那个英文字符
*/

/*
思路：
按照题意来即可，首先找出不一样的字符放入一个数组，接着将另一个数组存放次数
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    vector<char> DiffChar;
    vector<int> ShowTime;
    
    cin >> str;
    bool Exist = false;
    int i, j;
    for (i = 0; i < str.size(); i++)
    {
        Exist = false;
        for (j = 0; j < DiffChar.size(); j++)
        {
            if (((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
                &&str[i]==DiffChar[j])
            {
                Exist = true;
                break;
            }
        }
        if (Exist)      //存在
        {
            ShowTime[j]++;
            if (ShowTime[j] == 3)
                break;
        }
        else            //不存在
        {
            if ((str[i]>='a'&&str[i]<='z')
                ||(str[i]>='A'&&str[i]<='Z'))
            {
                DiffChar.push_back(str[i]);
                ShowTime.push_back(1);
            }
        }
    }
    cout << DiffChar[j] << endl;
    system("pause");
    return 0;
}