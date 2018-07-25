'''
python3.x中raw_input()和input（）,去除了raw_input，仅保留了input()函数，其接收任意输入，
将所有输入默认为字符串处理
'''

str = input()

if '.' in str:
    str = str.split('.')
    print(str)
else:
    print('null')