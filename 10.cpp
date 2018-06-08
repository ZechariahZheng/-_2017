#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子
是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
*/

/*
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)

输出描述:
输出可以产生的幸运的袋子数
*/

/*思路：
从n个数中随机取几个数，满足这几个数的和大于这几个数的积
这几个数的组合不能重复
*/

/*
n:提取的n个数

递归算法：不停地从剩余队列中随机抽取一个数
*/
vector<int> allTmp;            //每次抽取的量存放处
vector<vector<int> > all;            //每次抽取的量存放处

void func0(vector<int> &a, int n, const int n_1)
{
    vector<int>::iterator it, it_1;
    if (n == 0)
    {
        return;
    }
    vector<int> b = a;
    for (it = a.begin(); it != a.end(); it++)
    {
        allTmp.push_back(*it);                                  //抽取一个数
        b = a;
        it_1 = find(b.begin(), b.end(), *it);                   //擦除抽取的数
        b.erase(it_1);
        func0(b, n-1, n_1);                                     //从剩余的数中抽取n-1个数
        if (allTmp.size() == n_1)
        {
            vector<int> tmp = allTmp;
            sort(tmp.begin(), tmp.end());
            if (find(all.begin(), all.end(), tmp) == all.end())     //保存不一致的元素
                all.push_back(tmp);                             //当满足条件时保存下来
        }
        allTmp.pop_back();                                      //进入下一个元素时，将当前的元素出栈
        if (n_1 == n)
            allTmp.clear();                                     //当返回到最顶层时，清空临时vector
    }
}


/*
检查函数是否满足条件
*/
bool func1(vector<int> &a)
{
    int sum = 0;
    int ji = 1;
    
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        ji *= a[i];
    }
    
    return sum>ji;
}

int main()
{
    int n;
    int tmp;
    vector<int> X;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        X.push_back(tmp);
    }
    
    /*依次从袋子里拿出1个到n-2个*/
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        /*随机抽取i个数，保证这i个数不重复*/
        func0(X, i, i);
        for (int j = 0; j < all.size(); j++)
        {
            if (func1(all[j]))
                result++;
        }
        all.clear();
    }
    cout << result;
    system("pause");
    return 0;
}