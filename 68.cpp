/*
现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度

输入描述:
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
输出描述:
输出树的高度，为一个整数
*/
/*思路：
先建立二叉树，再根据二叉树来求高度*/
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;           //存放数组所在的位置
    struct node *left, *right;
    node(int a, node *b=NULL, node *c=NULL):data(a),left(b),right(c) {}
    node()
    {
        data = -1;
        left = NULL;
        right = NULL;
    }
};

/*利用前序遍历，到访问到叶结点时，比较最大，返回到父节点时，减去1*/
void find(node *start, int &result, int &tmp)
{
    /*采用先序遍历*/
    if (start==NULL)
    {
        if (tmp > result)
            result = tmp;
        return;
    }
    tmp++;
    find(start->left, result, tmp);
    find(start->right, result, tmp);
    tmp--;
}

int main()
{
    int n;
    cin >> n;
    vector<node> tree(n);
    int now, child;
    int first;
    int result = 0;

    /*形成树*/
    for (int i = 0; i < n-1; i++)
    {
        cin >> now >> child;
        if (i == 0)
            first = now;
        tree[now].data = now;
        //先存放在左节点
        if (tree[now].left==NULL || tree[now].right==NULL)
        {
            /*只要二叉树，后面的节点不要就可以*/
            if (tree[now].left == NULL)
                tree[now].left = &tree[child];
            else if (tree[now].left->data<child)
                tree[now].right = &tree[child];
            else if (tree[now].left->data>=child)
            {
                tree[now].right = tree[now].left;
                tree[now].left = &tree[child];
            }
        }
    }
    /*探搜二叉树的深度*/
    int tmp = 0;
    find(&tree[first], result, tmp);
    cout << result << endl;
    system("pause");
    return 0;
}