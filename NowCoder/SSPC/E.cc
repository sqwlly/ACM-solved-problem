/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月02日 星期二 07时46分56秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;

struct node{
	int id,v;
	bool operator < (const node &u) const{
		return v > u.v;
	}
}a[N],b[N];

map<int,int> adx, bdx;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].v;
		a[i].id = i;
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i].v;
		b[i].id = i;
		bdx[b[i].v] = i;
	}
	sort(a, a + n);
	sort(b, b + n, [](const node &u, const node &r) ->int{
		return u.v < r.v;		
	});
	for(int i = 0; i < n; ++i) {
		adx[a[i].v] = bdx[b[i].v];
	}
	sort(a, a + n, [](const node &u, const node &r) ->int {
		return u.id < r.id;		
	});
	//3 2 4 1
	//1 4 2 3
	//
	//3 2 4 1
	//2 4 1 3
	//
	//3 2 4 1
	//2 3 1 4
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		while(adx[a[i].v] != i) {
			ret++;
			swap(a[i], a[adx[a[i].v]]);
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << adx[a[i].v] << endl;
	}
	cout << ret << endl;
    return 0;
}
