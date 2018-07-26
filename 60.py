line = input()
#使用字典保存不一样的字符出现的次数
line = line.strip()
D = {}
Flag = False

for char in line:
    Exist = False
    for key in D:
        if ((char>='A' and char<='Z') or (char>='a' and char<='z')) and char==key:
            Exist = True
            D[key] += 1
            if (D[key] == 3):
                print(key)
                Flag = True
                break
    #字典中不存在这个字符
    if ((char>='A' and char<='Z') or (char>='a' and char<='z')) and Exist == False:
        D[char] = 1
    if Flag == True:
        break