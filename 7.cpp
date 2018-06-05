#include <iostream>

using namespace std;

/*牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，藏宝盒上有一个机关，
机关每次会显示两个字符串 s 和 t，根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子
序列。注意，子序列不要求在原字符串中是连续的，例如串 abc，它的子序列就有 
{空串, a, b, c, ab, ac, bc, abc} 8 种。*/

/*输入描述：
每个输入包含一个测试用例。每个测试用例包含两行长度不超过 10 的不包含空格的可见 ASCII 字符串。

输出描述:
输出一行 “Yes” 或者 “No” 表示结果。*/

/*思路：
使用两个数组保存两个字符串s和t，其中t中的字符要在s中出现，且顺序依次递增
遍历s字符串*/

char s[100];
char t[100];

int main()
{
    /*获得输入*/
    scanf("%s%s", s, t);
    int lenS = strlen(s);
    int lenT = strlen(t);
    
    /*遍历字符串t*/
    int tmp = 0;
    bool ExistFlag = false;
    for (int i = 0; i < lenT; i++)
    {
        ExistFlag = false;
        for (int j = tmp; j < lenS; j++)
        {
            /*寻找到了*/
            if (s[j] == t[i])
            {
                tmp = j+1;
                ExistFlag = true;
                break;
            }
        }
        if (ExistFlag == false)
            break;
    }
    if (ExistFlag == true)
        cout << "Yes";
    else
        cout << "No";
    system("pause");
    return 0;
}