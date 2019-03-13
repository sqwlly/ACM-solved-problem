/*************************************************************************
    > File Name: L2_02.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月12日 星期二 17时51分14秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

struct node{
	int addr,nxt;
	int v;
}a[101000], r[101000];
map<string,pair<int,string>> ret; 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int s,b;
	int n,x,init = 0;
	cin >> s >> n;
	init = s;
	for(int i = 1; i <= n; ++i) {
		cin >> s >> x >> b;
		a[s].nxt = b;
		a[s].v = x;
		a[s].addr = s;
	}
	vector<node> v;
	int cnt = 1;
	while(init != -1) {
		r[cnt++] = a[init];
		init = a[init].nxt;
	}
	int k = 1;
	int l = 1, j = cnt - 1;
	while(l <= j) {
		if(l == j) 
			v.push_back(r[l++]);
		else{
			v.push_back(r[j--]);
			v.push_back(r[l++]);
		}
	}
	for(int i = 0; i < v.size(); ++i) {
		v[i].nxt = v[i + 1].addr;
	}
	v[v.size() - 1].nxt = -1;
	/*
	for(int i = 0; i < n; ++i) {
		r[n - k + 1].nxt = r[k].addr;
		r[k].nxt = r[n - k].addr;
		v.push_back(r[n - k + 1]);
		v.push_back(r[k]);
		k++;
	}
	if(n & 1) {
		v.push_back(r[n / 2 + 1]);
	}
	v[n - 1].nxt = -1;*/
	n = v.size();
	for(int i = 0; i < n - 1; ++i) {
		cout << setw(5) << setfill('0') << v[i].addr << ' ' << v[i].v << ' ' << setw(5) << setfill('0') << v[i + 1].addr << endl;
	}
	cout << setw(5) << setfill('0') << v[n - 1].addr << ' ' << v[n - 1].v << ' ' << -1 << endl;
    return 0;
}

