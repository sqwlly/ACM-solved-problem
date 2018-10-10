#include<bits/stdc++.h>

using namespace std;
int a[100],p[100],cnt[100],w[100],m,k,v;

void love()
{
	int ans = v;
	for(int i = 1; i <= m; ++i){
		int cost = 0;
		for(int j = 1; j <= k; ++j){
			cost += cnt[j] * ceil(w[j] * (1 - p[i]/100.0));
		}
        if(cost <= a[i])
			cost = a[i];
		ans = min(ans,cost);
	}
	cout<<ans/10<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
#endif
	int T;
	cin>>T;
	while(T--){
		cin>>m>>k;
		v = 0;
		for(int i = 1; i <= m; ++i){
			cin>>a[i]>>p[i];
		}
		int c,d;
		for(int i = 1; i <= k; ++i){
			cin>>c>>d;
			cnt[i] = c, w[i] = d;
			v += c * d;
		}
		love();
	}
    return 0;
}


