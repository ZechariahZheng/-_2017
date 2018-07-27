/*
有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。
有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，翡翠和钻石这五种，
我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。如果无法找到则一个也无法带走。
请帮助学者找出如何切分项链才能够拿到最多的宝石。

输入描述:
我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，
我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
输出描述:
输出学者能够拿到的最多的宝石数量。每行一个
*/

/*
思路：从字符串中获取一段含有ABCDE的子字符串，要求包含该子字符串最短
且该字符串为循环数组
*/
#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

int main()
{
    string str;
    int min = INT_MAX;
    cin >> str;
    int strsize = str.size();
    for (int i = 0; i < strsize; i++)
    {
        int a[5] = {0};       //设置5个标志位
        int nchar = 0;
        /*从第i个数字遍历n个字符，找最短的min*/
        for (int j = 0; j < strsize; j++)
        {
            int n = (i+j)%strsize;
            switch(str[n])
            {
                case 'A': a[0] = 1;
                          break;
                case 'B': a[1] = 1;
                          break;
                case 'C': a[2] = 1;
                          break;
                case 'D': a[3] = 1;
                          break;
                case 'E': a[4] = 1;
                          break;
                default: break;
            }
            nchar++;
            if (a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1 && a[4]==1)
            {
                if (nchar < min)
                    min = nchar;
            }
        }
    }
    cout << strsize-min << endl;
    system("pause");
    return 0;
}