import sys
'''
i.strip().split(" ")返回一个列表
map()函数在python2.X中返回列表；在python3.x中返回迭代器
sys.stdin.readlines()得到的是一个字符串列表，每个字符串为一行的输入
'''
for i in sys.stdin.readlines():
    try:
        print(sum(map(int, i.strip().split(" "))))
    except:
        print("error");