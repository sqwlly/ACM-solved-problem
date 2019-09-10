/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月05日 星期四 09时40分53秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
typedef long long LL;
const int N = 1E7+10, mod = 1e7+7;
LL prime[N],p[N],cnt;
bool vis[N];

void init()
{
    for(int i = 2; i < N; ++i) {
        if(vis[i] == 0) {
            prime[cnt++] = i;
        }
        for(int j = 0; 1LL * prime[j] * i <  N; ++j) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                break;
            }
        }
    }
}

void solve(int n)
{
	int t = 0;
	LL ans = 1;
	for(int i = 0; i < cnt && prime[i] <= n; ++i) {
		t = 0;
		for(LL j = prime[i]; j <= n; j = j * prime[i]) {
			t += n / j;
		}
		if(t == 0)continue;
		ans = ans * p[t] % mod;
	}
	cout << ans << '\n';
}

int f[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	init();
	p[1] = 3, p[2] = 6;
	int ic = 4;
	for(int i = 3; i < N; ++i) {
		p[i] = p[i - 1] + ic;
		ic++;
	}

	while(cin >> n && n) {
		solve(n);
	}
    return 0;
}
