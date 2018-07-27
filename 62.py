#查找包含最短的字符串
str = input()
size = len(str)

min = size
FindStr = "ABCDE"
for i in range(size):
    n = 0
    map = {'A':0, 'B':0, 'C':0, 'D':0, 'E':0}
    for j in range(size):
        c = str[(i+j)%size]
        if FindStr.find(c) != -1:
            map[c] = 1
        n += 1
        if map['A']==1 and map['B']==1 and map['C']==1 and map['D']==1 and map['E']==1:
            if n < min:
                min = n
print(size-min)