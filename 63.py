#动态规划问题  map可以迭代字符串，input().strip()返回的是字符串
#split()函数所有的空字符，包括空格、换行、制表符
N = int(input())
numlist = list(map(int, input().strip().split()))

dp = [0x3f3f3f3f]*(N+1)
dp[0] = 0
for i in range(1, N+1):
    dp[i] = 0x3f3f3f3f
    for j in range(i):
        if numlist[j] >= (i-j):
            dp[i] = min(dp[i], dp[j]+1)

if dp[N] != 0x3f3f3f3f:
    print(dp[N])
else:
    print(-1)