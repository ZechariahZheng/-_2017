#include <iostream>
#include <vector>

using namespace std;

/*
一个只包含'A'、'B'和'C'的字符串，如果存在某一段长度为3的连续子串中恰好'A'、'B'和'C'各有一个，那么这个字符串就是纯净的，否则这个字符串就是暗黑的。例如：
BAACAACCBAAA 连续子串"CBA"中包含了'A','B','C'各一个，所以是纯净的字符串
AABBCCAABB 不存在一个长度为3的连续子串包含'A','B','C',所以是暗黑的字符串
你的任务就是计算出长度为n的字符串(只包含'A'、'B'和'C')，有多少个是暗黑的字符串。
*/

/*
思路：
n=2 暗黑个数=9
n=3 暗黑个数=3x3+3x2x2 = 21
n=4 暗黑个数=2x（3x3+3x2x2）+3*3 = 2x21+9
由此发现：n=3的暗黑数是n=2时的暗黑数的2倍加上n=1时候的暗黑数
n=4的暗黑数是n=3时的暗黑数的2倍加上n=2时候的暗黑数
*/
int func(int n)
{
    int pre1 = 3;
    int pre = 9;
    int result = 0;
    
    if (n == 1)
        return pre;
    else if (n == 2)
        return pre1;
    while (n >= 3)
    {
        result = 2*pre+pre1;
        pre1 = pre;
        pre = result;
        n--;
    }
    return result;
}

int main()
{
    cin >> n;
    cout << func(n);
    system("pause");
    return 0;
}