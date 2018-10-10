#include<bits/stdc++.h>

using namespace std;
int a[1010000];
int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in","r",stdin);
#endif
	int T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		set<int> s;
		for(int i = 0; i < n; ++i){
			cin>>a[i];
		}
		int l = 0, r = 0, ans = 0;
		for(; r < n; ){
			if(s.count(a[r]) == 0) s.insert(a[r++]);
			else s.erase(a[l++]);
			ans = max(ans, r - l);
		}
		cout<<ans<<endl;
	}
    return 0;
}
