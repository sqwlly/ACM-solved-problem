/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月30日 星期日 22时59分27秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int n;

struct node{
	int x,y;
	bool operator <(const node& u) {
		return x < u.x;
	}
}a[1001];

struct clue{
	int x,y;
	bool operator < (const clue & u) {
		return x > u.x;
	}
}c[1001];
bool vis[1001];
int ans_x = 1e8, ans_y = 1e8;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%d",&n);
	 for(int i = 0; i < n; ++i) {
		scanf("%d %d",&a[i].x,&a[i].y);
	 }
	 for(int i = 0; i < n; ++i) {
		scanf("%d %d",&c[i].x,&c[i].y);
	 }
	 long long sum_x = 0, sum_y = 0;
	 for(int i = 0; i < n; ++i) {
		sum_x += a[i].x + c[i].x;
		sum_y += a[i].y + c[i].y;
	 }
	 cout << sum_x / n << ' ' << sum_y / n << endl;
	 return 0;
}
