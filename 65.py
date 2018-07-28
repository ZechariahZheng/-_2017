m, n = map(int, input().split())

def f(x):
    bai = x//100
    shi = (x%100)//10
    ge = x%10
    sum = bai*bai*bai + shi*shi*shi + ge*ge*ge
    if sum == x:
        return True
    else:
        return False

result = []
for i in range(m, n+1):
    if f(i)==True:
        result.append(i)
out=""
if len(result):
    for i in range(len(result)):
        if i==len(result)-1:
            out += str(result[i])
        else:
            out += str(result[i])+" "
else:
    out = "no"
print(out)