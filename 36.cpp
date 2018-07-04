#include <iostream>
#include <vector>

using namespace std;

/*
找出n个数里最小的k个

输入描述:
每个测试输入包含空格分割的n+1个整数，最后一个整数为k值,n
不超过100。

输出描述:
输出n个整数里最小的k个数。升序输出
*/

/*
思路：
将输入数组排序即可
*/
/*冒泡排序：将最大的数移到后面*/
void BubbleSort(vector<int> &a)
{
    for (int i = 0; i < a.size()-1; i++)        //冒泡的次数
    {
        for (int j = i; j < a.size()-1-i; j++)  //两两比较
        {
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

int main()
{
    vector<int> input;
    int tmp;
    while (cin>>tmp && tmp!='\n')
    {
        input.push_back(tmp);
    }
    vector<int> n;
    int k = input[input.size()-1];
    for (int i = 0; i < input.size()-1; i++)
    {
        tmp = input[i];
        n.push_back(tmp);
    }
    sort(n.begin(), n.end());
    for (int i = 0; i < k; i++)
        cout << n[i] << " ";
    system("pause");
    return 0;
}