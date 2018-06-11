#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*考拉有n个字符串字符串，任意两个字符串长度都是不同的。
考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。*/

/*
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成

输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
*/

/*思路
字符长度排序：
根据字符串长度来进行排序
字典排序：
对于一系列字符串，依次比较每个字符，前一个字符串的字符应该小于等于后一个字符串的字符
*/

/*检验是否满足字符长度排序*/
bool func1(vector<string> &all)
{
    for (int i = 0; i < all.size()-1; i++)
    {
        if (all[i].size() > all[i+1].size())
            return false;
    }
    return true;
}

/*检验是否满足字典排序
即挨个检查字符串，前一个字符串的字符小于等于后一个字符串的字符*/
bool func2(vector<string> &all)
{
    int length = 0;
    for (int i = 0; i < all.size()-1; i++)
    {
        length = all[i].size();
        for (int j = 0; j < length; j++)
        {
            if (all[i][j] == all[i+1][j])
                continue;
            else if (all[i][j] < all[i+1][j])
                break;
            else
                return false;
        }
    }
    return true;
}


int main()
{
    int n;
    vector<string> all;
    string tmp;
    bool result_1, result_2;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        all.push_back(tmp);
    }
    result_1 = func1(all);
    result_2 = func2(all);
    
    if (result_1&&result_2)
        cout << "both";
    else if (result_1)
        cout << "lengths";
    else if (result_2)
        cout << "lexicographically";
    else
        cout << "none"
    system("pause");
    return 0;
}