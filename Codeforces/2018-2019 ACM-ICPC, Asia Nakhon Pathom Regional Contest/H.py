import math
m = [0] * 110
a = [0] * 110
three = [0] * 1001000
x = 0
y = 0
def exgcd(a, b):
    global x, y
    if b == 0:
        x = 1
        y = 0
        return a
    else:
        d = exgcd(b, a % b)
        t = x
        x = y
        y = t - (a // b) * y
        return d
def CRT(n):
    global x, y, M
    flag = 0
    for i in  range(1, n):
        d = exgcd(m[0], m[i])
        #print(d)
        u = a[i] - a[0]
        if u % d != 0:
            flag = 1
            break
        x = (x * u % m[i]) // d
        m[i] //= d
        x = (x % m[i] + m[i]) % m[i]
        a[0] += m[0] * x
        m[0] *= m[i]
    # print(flag)
    if flag == 1:
        print("he was definitely lying")
    else:
        print(int(math.ceil(math.pow(a[0],1.0/3))))
 
for i in range(0,11000):
    three[i] = i * i * i
T = int(input())
while(T > 0):
    T = T - 1
    n = 3
   # for i in range(0, n):
    m[0],m[1],m[2] = map(int,input().split())
   # for i in range(0, n):
    a[0],a[1],a[2] = map(int,input().split())
   # for i in range(0, n):
   #     print(a[i],m[i])
    CRT(n)
