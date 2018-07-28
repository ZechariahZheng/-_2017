from functools import cmp_to_key

n = int(input())
all = list(input().split())

def mycmp(x, y):
    if x+y > y+x:
        return 1
    elif x == y:
        return 0
    else:
        return -1

all.sort(key=cmp_to_key(mycmp), reverse=True)
result = ""
for i in range(len(all)):
    result += all[i]
print(result)