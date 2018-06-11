#include <iostream>
#include <string>

using namespace std;

/*
小易喜欢的单词具有以下特性：
1.单词每个字母都是大写字母
2.单词没有连续相等的字母
3.单词没有形如“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列，子序列可能不连续。
例如：
小易不喜欢"ABBA"，因为这里有两个连续的'B'
小易不喜欢"THETXH"，因为这里包含子序列"THTH"
小易不喜欢"ABACADA"，因为这里包含子序列"AAAA"
小易喜欢"A","ABA"和"ABCBA"这些单词
给你一个单词，你要回答小易是否会喜欢这个单词。*/

/*
输入描述:
输入为一个字符串，都由大写字母组成，长度小于100

输出描述:
如果小易喜欢输出"Likes",不喜欢输出"Dislikes"
*/

/*
思路：
1、判断字符中有无连续的字符
2、判断没有“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列
第一个字符与剩下的字符组成子序列，在剩余的字符中查找该子序列的存在*/

//判断字符中有无连续的字符
bool func1(string &str)
{
    for (int i = 0; i < str.size()-1; i++)
    {
        if (str[i] == str[i+1])
            return false;
    }
    return true;
}

bool func2(string &str)
{
    char substr[2];
    substr[0] = str[0];
    bool Exist0 = false;
    /*第一个字符串挨个与剩下的字符组成子序列*/
    for (int i = 1; i < str.size(); i++)
    {
        substr[1] = str[i];
        Exist0 = false;
        for (int j = i+1; j < str.size(); j++)
        {
            if (Exist0==false && str[j]==substr[0])
            {
                Exist0 = true;
            }
            else if (Exist0==true && str[j]==substr[1])
            {
                return false;
            }
        }
    }
    /*再比较除第一个字符串剩下的字符*/
    if (str.size() > 1)
    {
        string nextStr = str.substr(1, str.size()-1);
        return func2(nextStr);
    }
    else
        return true;
}

//判断字符串中无

int main()
{
    string str;
    cin >> str;
    if (func1(str) && func2(str))
        cout << "Likes";
    else
        cout << "Dislikes";
    system("pause");
    return 0;
}