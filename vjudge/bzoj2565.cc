/*************************************************************************
    > File Name: bzoj2565.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月10日 星期二 22时41分19秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;

struct Palindsome_Automaton {
	int child[maxn][28];
	int n, size, last, s[maxn], len[maxn], f[maxn], next[maxn];
	Palindsome_Automaton() {
		size = -1;
		newnode(0); //even
		newnode(-1); //odd
		last = n = 0;
		s[0] = -1;
		next[0] = next[1] = 1;
	}
	int newnode(int v) {
		int now = ++size;
		memset(child[now], 0, sizeof(child[now]));
		next[now] = 0;
		len[now] = v;
		return now;
	}
	void insert(int data,int id) {
		s[++n]=data;
		int p = last;
		while(s[n - len[p] - 1] != s[n]) p = next[p];
		if(!child[p][data]) {
			int now = newnode(len[p] + 2), q = next[p];
			while(s[n - len[q] - 1] != s[n]) q = next[q];
			next[now] = child[q][data];
			child[p][data] = now;
		}
		last = child[p][data];
		f[id] = len[last];
	}
} pam1,pam2;

string s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		pam1.insert(s[i] - 'a', i + 1);
	}
	for(int i = s.size() - 1; i >= 0; --i) {
		pam2.insert(s[i] - 'a', s.size() - i);
	}
	int ans = 0;
	for(int i = 1; i < s.size(); ++i) {
		ans = max(ans, pam1.f[i] + pam2.f[s.size() - i]);
	}
	cout << ans << '\n';
    return 0;
}
