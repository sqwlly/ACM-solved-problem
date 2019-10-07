T,k = map(int, input().split(' '))
mod = int(1e9 + 7)
while(T > 0):
    T = T - 1;
    a,b = map(int, input().split(' '))
    ans = b - a + 1;
    for i in range(a, b + 1):
        c = (k + i // k * k) * (i // k) // 2
        ans = (ans + i // k * i - c + i // k + mod) % mod
    print(ans)
