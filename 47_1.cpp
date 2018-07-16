#include <iostream>
#include <vector>

using namespace std;

/*
使用字典树来解题
*/

struct TrieTree {
    int count;                                  //每个节点存的次数
    struct TrieTree *next[2] {NULL, NULL};      //每个节点存储两个节点指针，因为每位只有0和1两种情况，如果是字典树，则为26
    TireTree():count(1) {}
};

/*
创建字典树，字典树的特征：
1、根节点不包含字符，除根节点外的每一个子节点包含一段信息
2、从根节点到某一节点，路径上经过的信息连接起来，为整段的信息

该字典树的除根节点以外的每个节点包含，数的每位信息
*/
TrieTree *buildTrieTree(vector<int> &array)
{
    TrieTree *trieTree = new TrieTree();
    for (int i = 0; i < (int)array.size(); i++)
    {
        TrieTree *cur = trieTree;
        for (int j = 16; j >= 0; j--)
        {
            int digit = (array[i] >> j) & 1;
            if (NULL == cur->next[digit])
                cur->next[digit] = new TireTree();
            else
                (cur->next[digit]->count)++;
            cur = cur->next[digit];
        }
    }
    return trieTree;
}

/*
查询字典树
1. aDigit=1， mDigit=1时，字典中第k位为0，异或结果为1，需要继续搜索更低位，第k位为1，异或结果为0，小于mDigit，不用理会；
2. aDigit=0， mDigit=1时，字典中第k位为1，异或结果为1，需要继续搜索更低位，第k位为0，异或结果为0，小于mDigit，不用理会；
3. aDigit=1， mDigit=0时，字典中第k位为0，异或结果为1，与对应分支所有数异或，结果都会大于m，第k位为1，异或结果为0，递归获得结果；
4. aDigit=0， mDigit=0时，字典中第k位为1，异或结果为1，与对应分支所有数异或，结果都会大于m，第k位为0，异或结果为0，递归获得结果；
*/
long long queryTrieTree(TrieTree *&trieTree, const int a, const int m, const int index)
{
    if (NULL == trieTree)
        return 0;
    
    TireTree *cur = trieTree;
    for (int i = index; i >= 0; i--)
    {
        int aDigit = (a >> i) & 1;
        int mDigit = (m >> i) & 1;
        
        if (1==aDigit && 1==mDigit)
        {
            if (NULL == cur->next[0])
                return 0;
            cur = cur->next[0];
        }
        else if (0==aDigit && 1==mDigit)
        {
            if (NULL == cur->next[1])
                return 0;
            cur = cur->next[1];
        }
        else if (1==aDigit && 0==mDigit)
        {
            long long val0 = (NULL == cur->next[0]) ? 0 : cur->next[0]->count;
            long long val1 = queryTrieTree(cur->next[1], a, m, i-1);
            return val0+val1;
        }
        else if (0==aDigit && 0==mDigit)
        {
            long long val1 = (NULL == cur->next[1]) ? 0 : cur->next[1]->count;
            long long val0 = queryTrieTree(cur->next[0], a, m, i-1);
            return val0+val1;
        }
    }
    return 0;
}

long long solve(const vector<int> &array, const int &m)
{
    TireTree *trieTree = buildTrieTree(array);
    long long result = 0;
    for (int i = 0; i < (int)array.size(); i++)
        result += queryTrieTree(trieTree, array[i], m, 16);
    return result/2;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> array(n);
        for (int i = 0; i < n; i++)
            cin >> array[i];
        cout << solve(array, m) << endl;
    }
    return 0;
}