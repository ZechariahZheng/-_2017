'''
python格式化输出%号，**0.5即开根号，python自动类型转换
map前面有n个变量，即split()函数分割的数量，即可赋值
'''
n, m = map(int, input().split())
sum = n
for i in range(m-1):
    n = n**0.5
    sum += n

print("%.2f" %sum)