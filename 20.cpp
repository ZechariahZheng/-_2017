#include <iostream>
#include <queue>

using namespace std;

/*
小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
输入描述:
第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000），输入的所有n之和不超过200000。

输出描述:
对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.
*/

/*
思路：
反向思维（画图即可知）
*/

deque<int> func(int &tmp)
{
    deque<int> result;
    int qtmp;
    for (int i = tmp; i >0; i--)
    {
        if (i == tmp)
            result.push_back(i);
        else
        {
            /*1、先获得输出时的队列*/
            result.push_front(i);
            /*2、将队列的最后一个元素放到队列头部*/
            qtmp = result.back();
            result.pop_back();
            result.push_front(qtmp);
        }
    }
    return result;
}

int main()
{
    int T;
    cin >> T;
    vector<deque<int> > result;
    deque<int> resultTmp;
    int tmp;
    
    for (int i = 0; i < T; i++)
    {
        cin >> tmp;
        resultTmp = func(tmp);
        result.push_back(resultTmp);
    }
    for (int i = 0; i < result.size(); i++)
    {
        while (!result[i].empty())
        {
            cout << result[i].front();
            if (result[i].size() != 1)
                cout << " ";
            result[i].pop_front();
        }
        cout << endl;
    }
    system("pause");
    return 0;
}