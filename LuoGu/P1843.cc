/*************************************************************************
    > File Name: P1843.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月25日 星期二 23时03分13秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+10;

priority_queue<int> pq;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,A,B,x;
	cin>>n>>A>>B;
	for(int i = 0; i < n; ++i){
		cin>>x;
		pq.push(x);
	}
	int t = 0;
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		if(cur - t * A <= 0){
			break;
		}
		t++;
		pq.push(cur - B);
	}
	printf("%d\n",t);
	return 0;
}
