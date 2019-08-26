def exgcd(a, b):
    if b == 0:
        return 1, 0, a
    y, x, d = exgcd(b, a % b)
    y -= a // b * x
    return x, y, d

n, m = map(int, input().split())

b, a = map(int, input().split())

ans, M = a,b;

for i in range(n - 1):
    b, a = map(int, input().split())
    c = a-ans
    x, y, d = exgcd(M, b)
    if c%d:
        print('he was definitely lying')
        exit(0)
    x *= c//d
    ans += x*M
    M *= b//d
    ans %= M

ans = (ans%M+M)%M
if ans > m:
    print('he was probably lying')
    exit(0)
print(ans)
