#include <iostream>

using namespace std;

/*
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。
*/

/*
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果

输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1
*/

/*
思路：
n = 6*x + 8*y
根据n来求x和y(且尽可能让y的值大一些)
*/
int main()
{
    int n;
    int x, y;
    
    cin >> n;
    if (n%8 == 0)
        cout << n/8;
    else
        y = n/8;
    x = n/6;
    for (int i = y; i >= 0; i--)
    {
        for (int j = 0; j <= x; j++)
        {
            if (8*i+6*j == n)
            {
                cout << i+j;
                system("pause");
                return 0;
            }
        }
    }
    cout << "-1";
    system("pause");
    return 0;
}