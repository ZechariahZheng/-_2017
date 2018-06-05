#include <iostream>
#include <math.h>

using namespace std;

/*航天飞行器是一项复杂而又精密的仪器，飞行器的损耗主要集中在发射和降落的过程，科学家根据实验数据估计，
如果在发射过程中，产生了 x 程度的损耗，那么在降落的过程中就会产生 x2 程度的损耗，如果飞船的总损耗超过
了它的耐久度，飞行器就会爆炸坠毁。问一艘耐久度为 h 的飞行器，假设在飞行过程中不产生损耗，那么为了保证
其可以安全的到达目的地，只考虑整数解，至多发射过程中可以承受多少程度的损耗？*/

/*思路：
f(x) = x^2+x  (f(x)<=h)
求x的最大值
1、求出f(x)的开方值，从这里依次递减，直到找到第一个满足条件的值*/

long func(long x)
{
    long tmp = 0;
    
    tmp = (long)pow(x, 2);
    
    return (tmp+x);
}

int main()
{
    long h;
    long tmp = 0;
    long result = 0;
    
    scanf("%ld", &h);
    tmp = (long)sqrt(h);
    for (long i = tmp; i >= 0; i--)
    {
        if (func(i) <= h)
        {
            result = i;
            break;
        }
    }
    printf("ld", result);
    system("pause");
    return 0;
}