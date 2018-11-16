/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 23时52分52秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int a[100100];
bool cmp(const pair<int,int> &p1,const pair<int,int> &p2)//要用常数，不然编译错误
{
	return p1.second>p2.second;
}
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
	vector<pair<int,int> > arr;
	vector<int> v;
	int cnt = 0;
	for(auto t : m) {
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end(),cmp);
	for (vector<pair<int,int> >::iterator it=arr.begin();it!=arr.end();++it){
		int d = it->second, t = 1;
		cout<<d<<endl;
		if((it + 1)!= arr.end() && d / (t + 1) >= (it+1)->second) {
			v.push_back(it->first);
			cnt++;
			while(d / (t + 1) >= (it+1)->second){
				v.push_back(it->first);
				d /= (t + 1);
				t++;
				cnt++;
			}
		}else{
			v.push_back(it->first);
			cnt++;
		}
		if(cnt == k) break;
	}
/*	for(auto it : arr) {
		int d = it.second, t = 1;
		if(d / (t + 1) >= k){
			while(d / (t + 1) >= k) {
				v.push_back(it.first);
				d /= (t + 1);
				t++;
				k--;
			}
		}else{
			v.push_back(it.first);
			cnt++;
		}
		if(cnt == k) break;
	}*/
	for(int i = 0; i < v.size(); ++i) {
		printf("%d%c",v[i],i==v.size()-1?'\n':' ');
	}
    return 0;
}
