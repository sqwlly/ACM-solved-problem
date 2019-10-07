/*************************************************************************
    > File Name: bzoj3676.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月16日 星期一 11时00分55秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	pam.init();
	for(int i = 0; i < s.size(); ++i) pam.Insert(s[i]);
	pam.getsum();
	long long ans = 0;
	for(int i = 0; i < pam.tot; ++i) {
		ans = max(ans, 1LL * pam.cnt[i] * pam.len[i]);
	}
	cout << ans << '\n';
	return 0;
}
