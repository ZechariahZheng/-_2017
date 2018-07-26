'''
思路：从左到右找到字符串中相邻右边小于左边的数，删除
split()函数返回一个列表
strip(x)方法只能用于移除字符串头尾指定的字符
'''
line = input()
line = line.split(' ')
N = int(line[1])
while N:
    N -= 1
    strlen = len(line[0])
    for i in range(strlen-1):
        n = i
        if line[0][i] < line[0][i+1]:
            line[0] = line[0][0:i] + line[0][i+1:]
            break
    if n == strlen-1:
        lien[0].strip(line[0][n])
print(line[0])