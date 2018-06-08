#include <iostream>
#include <algorithm>

using namespace std;

/*思路：
广度搜索+剪枝
*/

int n;
int nums[1005];

/*思路：
DFS生成全组合，同时注意剪枝、避免重复组合
*/
int dfs(int *nums, int index, long sum, long multi)
{
    int count = 0;
    for (int i = index; i < n; i++)
    {
        sum += nums[i];
        multi *= nums[i];
        if (sum > multi)
            count += 1 + dfs(nums, i+1, sum, multi);            //满足条件后，count加1，再递归剩余的数
        else if (nums[i] == 1)
            count += dfs(nums, i+1, sum, multi);                //不满足条件，即sum<=multi时，要在选一个数使其满足sum+b>multi*b,则b必为1
        else
            break;
        sum -= nums[i];         //加上的数要减去
        multi /= nums[i];       //乘上的数要除去
        /*跳过相等的元素，避免重复组合*/
        while (i<n-1 && nums[i]==nums[i+1])
            i++;
    }
    return count;               //此处也为终止条件
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    /*从小到大排序*/
    sort(nums, nums+n);
    cout << dfs(nums, 0, 0, 1);
    system("pause");
    return 0;
}