/*************************************************************************
    > File Name: 1182.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月09日 星期六 10时44分51秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 5E4+10;
struct node{
	int fa,kind;
}f[N];
int n;

int getF(int x)
{
	if(f[x].fa == x) return x;
	int t = getF(f[x].fa);
	f[x].kind = (f[f[x].fa].kind + f[x].kind) % 3;
	return f[x].fa = t;
}

int Merge(int x,int y,int d)
{
	if(x > n || y > n) return 1;
	if(x == y && d == 1) return 1;
	int t1 = getF(x);
	int t2 = getF(y);
	if(t1 != t2) {
		f[t2].fa = t1;
		f[t2].kind = (f[x].kind + 3 + d - f[y].kind) % 3;
		return 0;
	}else{
		if ((f[y].kind - f[x].kind + 3) % 3 != d) return 1;
		return 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	for(int i = 1; i < N; ++i) f[i].fa = i, f[i].kind = 0;
	int k,x,y,d,ans = 0;
	cin >> n >> k;
	for(int i = 0; i < k; ++i) {
		scanf("%d%d%d",&d,&x,&y);
		ans += Merge(x,y,d - 1);
	}
	cout << ans << endl;
    return 0;
}
