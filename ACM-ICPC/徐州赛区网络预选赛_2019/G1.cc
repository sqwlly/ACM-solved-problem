/*************************************************************************
    > File Name: G1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月09日 星期一 17时46分15秒
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
const int N = 3E5+10;
struct PAM{
	int nxt[N][26], fail[N], len[N], cnt[N], S[N], pos[N];
	int tot,n,last;
	inline int newnode(int x) { 
		memset(nxt[tot],0,sizeof nxt[tot]); 
		cnt[tot] = 0, len[tot] = x; return tot++;
	}
	inline void init() {
		newnode(tot = 0), newnode(S[0] = -1), fail[last = n = 0] = 1;
	}
	inline int getfail(int x) {
		while(S[n - len[x] - 1] != S[n]) x = fail[x]; return x;
	}
	inline void Insert(int c) {
		c = c - 'a';
		S[++n] = c;
		int cur = getfail(last);
		if(!nxt[cur][c]) {
			int now = newnode(len[cur] + 2);
			fail[now] = nxt[getfail(fail[cur])][c];
			nxt[cur][c] = now;
		}
		last = nxt[cur][c]; cnt[last]++;
		pos[last] = n;
	}
	inline void getsum() {
		for(int i = tot - 1; i >= 0; --i) {
			cnt[fail[i]] += cnt[i];
		}
	}
}pam;

char s[N];
int sum[N][26];

int getsum(int l,int r) 
{
	int ret = 0;
	for(int i = 0; i < 26; ++i) if(sum[r][i] - sum[l - 1][i] > 0) ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> s + 1;
	int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 26; ++j) {
			sum[i][j] = sum[i - 1][j];
		}
		sum[i][s[i] - 'a']++;
	}
	pam.init();
	for(int i = 1; i <= n; ++i) {
		pam.Insert(s[i]);
	}
	pam.getsum();
	int l,r;
	long long ans = 0;
	for(int i = 2; i < pam.tot; ++i) {
		l = pam.pos[i] - pam.len[i] + 1;
		r = pam.pos[i];
		ans += 1LL * getsum(l,r) * pam.cnt[i];
	}
	cout << ans << '\n';
    return 0;
}
