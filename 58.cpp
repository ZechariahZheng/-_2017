//这道题目可以定义一个结构体用于存储每个分段的起始时间，截止时间，价格，然后对所
//有相邻且价格一致的区间进行merge，这也是题目本身想要考察的。但是这样的做法不适
//合考试时候时间有限的情况下，虽然单纯的merge并不复杂，但是注意题目中提到了酒店
//的价格可能不一致，如果不一致，按后面的价格为准，如果后面记录的价格和前面的记录
//不一样，这就可能导致原来的一个区间段更新价格后分裂成为两个或者三个，略显复杂。
//所以可以直接用一个数组存储每天的价格，这样做的好处就是即使前后数据不一致，后面
//的会直接覆盖前面的完成价格更新，缺点就是需要一个数组来记录每天的价格，空间复杂
//度较高，对于这个实际问题而言，不会出现特别多的天数，所以不必考虑大数问题，当然
//也所幸内存够用。特别需要注意输出格式要满足题目要求。
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i = 0;
    int start, end, price;
    while (cin >> start >> end >> price){
        vector<int> prices(10000);
        for (i = start; i <= end; i++)
            prices[i] = price;
        int min = start;
        int max = end;
        while (cin >> start >> end >> price){
            if (start < min)
                min = start;
            if (end > max)
                max = end;
            for (i = start; i <= end; i++)
                prices[i] = price;
        }
 
        cout << "[" << min << ", ";
        for (i = min + 1; i <= max; i++){
            if (prices[i] != prices[i - 1]){
                if (prices[i - 1] != 0)
                    cout << i - 1 << ", " << prices[i - 1] << "]";
                if (i < max && prices[i] != 0)
                    cout << "," << "[" << i << ", ";
            }
        }
        cout << max << ", " << prices[max] << "]" << endl;
    }
    return 0;
}