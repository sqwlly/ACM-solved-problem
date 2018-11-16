/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 22时59分46秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
//int a[100100];
struct node{
	int v,id;
	bool operator < (const node & a) const{
		return v < a.v;
	}
}a[200010];


vector<int> v;
//set<int> s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	LL sum = 0;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a[i].v);
		sum += a[i].v;
		a[i].id = i;
	}
	sort(a,a+n);
//	cout<<*s.end()<<endl;
	for(int i = 0; i < n; ++i) {
	//	s.erase(a[i]);
		//int t = *s.end();
		//cout<<a[i]<<' '<<t<<endl;
		if(i == n - 1) {
			if(sum - a[i].v - a[n - 2].v == a[n - 2].v) {
				v.push_back(a[i].id);
				break;
			}
			break;
		}
		if(sum - a[i].v - a[n - 1].v == a[n - 1].v) {
			v.push_back(a[i].id);
		}
	//	s.insert(a[i]);
	}
	cout<<v.size()<<endl;
	for(int i = 0; i < v.size(); ++i) {
		printf("%d%c",v[i]+1,i==v.size()-1?'\n':' ');
	}
    return 0;
}
