a = [0]*11000

while True:
    try:
        cin = input()
        if cin == '':
            break
        s = list(map(int, cin.split()))
        a[s[0]:s[1]+1] = [s[2]]*(s[1]-s[0]+1)
    except:
        break
cur, start, temp = 0, 0, 0
ans = ''
while cur < 11000:
    if a[cur] != 0:
        temp = a[cur]
        start = cur
        while a[cur] == temp:
            cur += 1
        ans += str([start, cur-1, temp])+','
    else:
        cur += 1
print(ans[0:-1])
