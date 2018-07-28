n = int(input())
for i in range(n):
    s = input()
    #ZERO,TWO,FOUR,SIX,EIGHT均有独立的字母标识Z,W,U,X,G，且对应数字为2,4,6,8,0
    n2, n4, n6, n8, n0 = s.count('Z'), s.count('W'), s.count('U'), s.count('X'), s.count('G')
    #去除上述单词后，ONE,THREE,FIVE,SEVEN可分别由O,T,F,S标识，且对应数字为3,5,7，9
    n3, n5, n7, n9 = s.count('O')-n2-n4-n6, s.count('T')-n4-n0, s.count('F')-n6, s.count('S')-n8
    n1 = s.count('I')-n7-n8-n0
    print('0'*n0+'1'*n1+'2'*n2+'3'*n3+'4'*n4+'5'*n5+'6'*n6+'7'*n7+'8'*n8+'9'*n9)