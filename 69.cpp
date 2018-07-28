/*
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。

输入描述:
有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N<=100），第二行包含N个数(每个数不超过1000，空格分开)。
输出描述:
每组数据输出一个表示最大的整数。
*/

/*
思路：字符串有条件的拼接
将所有字符串排序，按照从左到右的字符大小顺序排序
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool func(string a, string b)
{
    return a+b>b+a ? true : false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> all(n);

    for (int i = 0; i < n; i++)
        cin >> all[i];
    sort(all.begin(), all.end(), func);
    for (int i = 0; i < all.size(); i++)
        cout << all[i];
    cout << endl;
    system("pause");
    return 0;
}