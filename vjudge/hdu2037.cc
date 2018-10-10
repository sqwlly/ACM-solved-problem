/*************************************************************************
    > File Name: hdu2037.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月10日 星期三 16时20分53秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct tv{
	int l,r;
	bool operator < (const tv & u)const{
		return r < u.r;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,l,r;
	while(cin>>n && n){
		vector<tv> v;
		for(int i = 0; i < n; ++i){
			cin>>l>>r;
			v.push_back(tv{l,r});
		}
		sort(v.begin(),v.end());
		int cnt = 1, pre = 0;
		for(int i = 1; i < n; ++i){
			if(v[pre].r <= v[i].l)
				cnt++, pre = i;
		}
		cout<<cnt<<endl;
	}

    return 0;
}
