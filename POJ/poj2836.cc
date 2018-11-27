/*************************************************************************
    > File Name: poj2836.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月25日 星期日 16时34分22秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

struct node {
	int id, area;
	node() {}
	node(int _id,int _area ) : id(_id), area(_area) {}
}a[300];

int dp[1 << 16], n;

pair<int,int> p[20];

bool fun(int i,int j,int k)
{	
	return ((p[i].first - p[k].first) * (p[j].first - p[k].first) <= 0 && ((p[i].second - p[k].second) * (p[j].second - p[k].second) <= 0));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	while(cin >> n, n) {
		int x,y;
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			p[i] = make_pair(x,y);
		}
		node t;
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				t.id = 0;
				t.area = max(1,abs(p[i].first - p[j].first)) * max(1,abs(p[i].second - p[j].second));
				t.id |= 1 << i;
				t.id |= 1 << j;
				for(int k = 0; k < n; ++k) {
					if(fun(i,j,k)) {
						t.id |= 1 << k;
					}
				}
				a[cnt++] = t;
			}
		}
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;
		for(int i = 0; i < cnt; ++i) {
			for(int j = 0; j < (1 << n); ++j) {
				dp[j | a[i].id] = min(dp[j | a[i].id], dp[j] + a[i].area);
			}
		}
		cout << dp[(1 << n) -1] << endl;
	}
    return 0;
}
