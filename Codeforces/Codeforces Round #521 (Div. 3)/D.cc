/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 23时52分52秒
 ************************************************************************/
#include<bits/stdc++.h>
#define P pair<int,int> 
using namespace std;
map<int,int> m,cnt;
int a[200100];
/*bool cmp(const pair<int,int> &p1,const pair<int,int> &p2)//要用常数，不然编译错误
{
	return p1.first>p2.first;
}*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i = 0; i < n; ++i) {
		scanf("%d",a + i);
		m[a[i]]++;
	}
//	vector<P,vector<P>,greater<P> > arr;
	vector<int> v;
	priority_queue<P,vector<P> > pq;
	for(auto t : m) {
		pq.push({t.second,t.first});
	}
	while(v.size() < k) {
		P t = pq.top();
		//cout<<t.first<<' '<<t.second<<endl;
		pq.pop();
		v.push_back(t.second);
		cnt[t.second]++;
		t.first = m[t.second] / (cnt[t.second] + 1);
		pq.push(t);
	}
	for(int i = 0; i < v.size(); ++i) {
		printf("%d%c",v[i],i==v.size()-1?'\n':' ');
	}
    return 0;
}
