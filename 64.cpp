/*
数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

输入描述:
输入数据有多组，每组占一行，由两个整数n（n < 10000）和m(m < 1000)组成，n和m的含义如前所述。
输出描述:
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。
*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int m;
    double n, sum = 0;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        sum += n;
        n = sqrt(n);
    }
    printf("%.2f", sum);
    system("pause");
    return 0;
}