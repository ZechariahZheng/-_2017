#include <iostream>
#include <string>

using namespace std;

/*
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I

输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100

输出描述:
依次输出倒置之后的字符串,以空格分割
*/

/*
思路：
从句子中获取一个个的单词，然后再反着打印出来即可*/

int main()
{
    string input;
    vector<string> words;
    char tmp[100];
    int j = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            string TmpWords(tmp);
            words.push_back(TmpWords);
            memset(tmp, sizeof(tmp), 0);
            j = 0;
        }
        else
        {
            tmp[j++] = input[i];
        }
    }
    for (int i = words.size()-1; i >= 0; i--)
    {
        cout << words[i] << " ";
    }
    system("pause");
    return 0;
}