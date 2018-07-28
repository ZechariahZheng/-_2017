/*
给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格。
 比如： （1） “hello xiao mi”-> “mi xiao hello”

输入描述:
输入数据有多组，每组占一行，包含一个句子(句子长度小于1000个字符)
输出描述:
对于每个测试示例，要求输出句子中单词反转后形成的句子
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> all;
    
    getline(cin, str);
    char tmp[100];
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' || i==str.size()-1)
        {
            tmp[j] = '\0';
            if (i == str.size()-1)
            {
                tmp[j++] = str[i];
                tmp[j] = '\0';
            }
            string alltmp(tmp);
            all.push_back(alltmp);
            j = 0;
        }
        else
        {
            tmp[j] = str[i];
            j++;
        }
    }
    for (int i = all.size()-1; i >= 0; i--)
    {
        i==0 ? cout << all[i] : cout << all[i] << " ";
    }
    system("pause");
    return 0;
}