import math
def quick(a, n):
    res = 1;
    while(n > 0):
        if(n & 1):
            res = res * a
        a = a * a
        n >>= 1
    return res
def quickP(a, n, p):
    res = 1
    while(n > 0):
        if(n & 1):
            res = res * a % p
        a = a * a % p
        n >>= 1
    return res % p
mod = int(1e9+7)
ans = 1
x, n = map(int,input().split(' '))
q = float(x + 0.5)
for i in range(2,int(math.sqrt(q)) + 5):
    if(x % i == 0):
        for j in range(65):
            s = quick(i, j)
            if(s > n):
                break
            if(s == 1): continue
            t = quickP(i, n // s, mod) % mod
            ans = ans * t % mod;
        while(x % i == 0):
            x //= i

if(x > 1):
    for j in range(65):
        s = quick(x, j)
        if(s > n):
            break
        if(s == 1): continue
        t = quickP(x, n // s, mod) % mod
        ans = ans * t % mod;
print(ans)

