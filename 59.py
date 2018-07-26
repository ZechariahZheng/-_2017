import sys

strs = sys.stdin.readlines()
for s in strs:
    line = s.strip()      #将空格全部舍弃
    #将字符串按照要求保留下来
    out = ''
    for i in line:
        if i>='0' and i<='9':
            out += i
        if len(out)==6 or len(out)==15:
            out += ' '
    print(out)