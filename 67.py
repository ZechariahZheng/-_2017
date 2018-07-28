s = list(input().split())

result = ""
for i in range(len(s))[::-1]:
    if i == 0:
        result += s[i]
    else:
        result += s[i]+" "
print(result)