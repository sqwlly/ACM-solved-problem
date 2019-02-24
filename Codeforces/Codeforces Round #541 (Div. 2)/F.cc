/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月23日 星期六 19时57分22秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 150100;
int f[N],n;
list<int> lis[N];

int getF(int v)
{
	if(f[v] == v) return f[v];
	return f[v] = getF(f[v]);
}

void merge1(int u,int v)
{
	int t1 = getF(u);
	int t2 = getF(v);
	if(t1 != t2) {
		if(lis[t1].size() > lis[t2].size()) {
			f[t2] = t1;
			lis[t1].splice(lis[t1].end(),lis[t2]);
		}else {
			f[t1] = t2;
			lis[t2].splice(lis[t2].end(),lis[t1]);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x,y;
	for(int i = 0; i <= n; ++i) {
		f[i] = i;
		lis[i].push_back(i);
	}
	for(int i = 0; i < n; ++i) {
		cin >> x >> y;
		merge1(x,y);
	}
	
	int rt = getF(1);
	for(auto &v : lis[rt]) {
		cout << v << ' ';
	}
    return 0;
}
