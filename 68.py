num = int(input())
tree = {'0':[1,0]}  #[层数，子节点数]

for i in range(num-1):
    parent, child = input().split()
    if parent in tree and tree[parent][1] < 2:
        tree[parent][1] += 1
        tree[child] = [tree[parent][0]+1, 0]
print(max(x[0] for x in tree.values()))         #找出最大键值