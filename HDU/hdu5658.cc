/*************************************************************************
    > File Name: hdu5658.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月10日 星期二 21时19分19秒
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
const int N = 1E3+10;
struct PAM{
	int nxt[N][26], fail[N], len[N], cnt[N], S[N], pos[N];
	int tot,n,last;
	inline int newnode(int x) {
		memset(nxt[tot], 0, sizeof nxt[tot]);
		cnt[tot] = 0, len[tot] = x; return tot++;
	}
	inline void init() {
		newnode(tot = 0), newnode(S[0] = -1), fail[last = n = 0] = 1;
	}
	inline int getfail(int x) {
		while(S[n - len[x] - 1] != S[n]) x = fail[x]; return x;
	}
	inline void insert(int c) {
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
};

PAM pam[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,l,r,q;
	string s;
	cin >> T;
	while(T--) {
		cin >> s >> q;
		int n = s.length();
		for(int i = 1; i <= n; ++i) {
			pam[i].init();
			for(int j = i; j < n; ++j) {
				pam[i].insert(s[j]);
			}
		}
		for(int i = 0; i < q; ++i) {
			cin >> l >> r;
			cout << pam[r].tot - pam[l].tot << '\n';
		}
	}
    return 0;
}
