n,k = map(int,input().split())
s = input().split(' ')
list = []
for i in range(0,n):
    list.append(0)
ic = 0;
list1 = []
jump = False
for i in range(len(s)):
    if jump == True:
        jump = False
        continue
    if str.isdigit(s[i][0]) or s[i][0] == '-':
        t = int(s[i])
        list1.append(-t)
        ic = (ic + int(s[i]) + n) % n
    else:
        m = int(s[i + 1])
        jump = True
        for j in range(0,m):
            if(len(list1) - j - 1 >= 0):
                ic = (ic + list1[len(list1) - j - 1]) % n
        for j in range(0,m):
            list1.pop()
print(ic)


