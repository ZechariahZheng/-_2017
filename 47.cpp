/*
C++
思路来源：潇潇古月
思路：
    直接计算肯定是超时的，所以这问题不能使用暴力破解，考虑到从高位到低位，依次进行位运算，
    如果两个数异或结果在某高位为1，而m的对应位为0，则肯定任何这两位异或结果为1的都会比m大。
    由此，考虑使用字典树（TrieTree）从高位到低位建立字典，再使用每个元素依次去字典中查对应
    高位异或为1， 而m为0的数的个数，相加在除以2既是最终的结果；直接贴出代码如下，非原创，欢迎讨论；
    补充：queryTrieTree在搜索的过程中，是从高位往低位搜索，那么，如果有一个数与字典中的数异或结果
    的第k位大于m的第k位，那么该数与对应分支中所有的数异或结果都会大于m， 否则，就要搜索在第k位异或
    相等的情况下，更低位的异或结果。queryTrieTree中四个分支的作用分别如下：
    1. aDigit=1， mDigit=1时，字典中第k位为0，异或结果为1，需要继续搜索更低位，第k位为1，异或结果为0，小于mDigit，不用理会；
    2. aDigit=0， mDigit=1时，字典中第k位为1，异或结果为1，需要继续搜索更低位，第k位为0，异或结果为0，小于mDigit，不用理会；
    3. aDigit=1， mDigit=0时，字典中第k位为0，异或结果为1，与对应分支所有数异或，结果都会大于m，第k位为1，异或结果为0，递归获得结果；
    4. aDigit=0， mDigit=0时，字典中第k位为1，异或结果为1，与对应分支所有数异或，结果都会大于m，第k位为0，异或结果为0，递归获得结果；
 
改进：
    1.字典树17位即可保证大于100000，移位范围为1~16位，则字典树构建时从16~0即可。
       字典树第一层不占位，实际上是15~-1层有数据，这也是数据中next的用法。
    2.queryTrieTree函数需要考虑到index为-1时的返回值。
     
时间复杂度：O(n)；
空间复杂度O(k),k为常数(trie树的高度)，因此可以认为O(1)。
 */
#include <iostream>
#include <vector>
using namespace std;
 
struct TrieTree
{
    int count;//每个节点存的次数
    struct TrieTree* next[2]{NULL,NULL};//每个节点存储两个节点指针
    TrieTree():count(1){}
};
 
TrieTree* buildTrieTree(const vector<int>& array)
{
    TrieTree* trieTree = new TrieTree();
    for(int i=0;i<(int)array.size();++i)
    {
        TrieTree* cur = trieTree;
        for(int j=16;j>=0;--j)
        {
            int digit = (array[i] >> j) & 1;
            if(NULL == cur->next[digit])
                cur->next[digit] = new TrieTree();
            else
                ++(cur->next[digit]->count);
            cur = cur->next[digit];
        }
    }
    return trieTree;
}
 
//查询字典树
long long queryTrieTree(TrieTree*& trieTree, const int a, const int m, const int index)
{
    if(NULL == trieTree)
        return 0;
 
    TrieTree* cur = trieTree;
     
    for(int i=index;i>=0;--i)
    {
        int aDigit = (a >> i) & 1;
        int mDigit = (m >> i) & 1;
 
        if(1==aDigit && 1==mDigit)
        {
            if(NULL == cur->next[0])
                return 0;
            cur = cur->next[0];
        }
        else if(0 == aDigit && 1==mDigit)
        {
            if(NULL == cur->next[1])
                return 0;
            cur = cur->next[1];
        }
        else if(1 == aDigit && 0 == mDigit)
        {
            long long val0 =  (NULL == cur->next[0]) ? 0 : cur->next[0]->count;
            long long val1 =  queryTrieTree(cur->next[1],a,m,i-1);
            return val0+val1;
        }
        else if(0 == aDigit && 0 == mDigit)
        {
            long long val0 =  queryTrieTree(cur->next[0],a,m,i-1);
            long long val1 =  (NULL == cur->next[1]) ? 0 : cur->next[1]->count;
            return val0+val1;
        }
    }   
    return 0;//此时index==-1,这种情况肯定返回0（其他情况在循环体中都考虑到了）
}
 
//结果可能超过了int范围，因此用long long
long long solve(const vector<int>& array, const int& m)
{
    TrieTree* trieTree = buildTrieTree(array);
    long long result = 0;
    for(int i=0;i<(int)array.size();++i)
    {
        result += queryTrieTree(trieTree,array[i],m,16);
    }
    return result /2;
}
 
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> array(n);
        for(int i=0;i<n;++i)
            cin>>array[i];
        cout<< solve(array,m) <<endl;
    }
    return 0;
}