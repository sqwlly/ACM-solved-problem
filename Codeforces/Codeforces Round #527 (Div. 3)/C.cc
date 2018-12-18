/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月18日 星期二 22时56分32秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
struct node{
	string str;
	int f, id;
}s[300];


bool cmp(node a,node b)
{
	return a.str.size() < b.str.size();
}

bool cmp1(node a,node b)
{
	return a.id < b.id;
}
int n;
int dfs(int d,string now,int f)
{
	if(d > 2 * n - 2) return 1;
	if(f == 1 && s[d].str.substr(0,now.size()) == now) {
		if(d == 2 * n - 2 || d == 2 * n - 3) return 1;
		dfs(d + 1, now, 1);
	}else if(f == 0 && s[d].str.substr(s[d].str.size() - now.size(), s[d].str.size()) == now) {
		if(d == 2 * n - 2 || d == 2 * n - 3) return 1;
		dfs(d + 1, now, 0);
	}else{
		return 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n;
	string ss;
	for(int i = 0; i < 2 * n - 2; ++i) {
		cin >> ss;
		s[i].str = ss;
		s[i].id = i;
	}
	sort(s,s + 2 * n - 2, cmp);
	for(int i = 0; i < 2 * n - 2; i += 2) {
		int f = dfs(i,s[i].str,1);
		if(f) {
			s[i].f = 1;
			s[i + 1].f = 0;
		}else{
			s[i].f = 0;
			s[i + 1].f = 1;
		}
	}
	sort(s,s + 2 * n - 2, cmp1);
	for(int i = 0; i < 2 * n - 2; ++i) {
		putchar(s[i].f ? 'P' : 'S');
	}
/*	for(int i = 0; i < 2 * n - 2; ++i) {
		int l = s[i].str.length(), f = 0;
		for(int j = i + 2; j < 2 * n - 2; ++j) {
			if(s[j].str.substr(0,l) == s[i].str) {
				putchar('P');
				f = 1;
				break;
			}
		}
		if(f == 0) {
			putchar('S');
		}
	}*/
	cout<<endl;
    return 0;
}
