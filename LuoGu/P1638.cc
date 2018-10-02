/*************************************************************************
    > File Name: P1638.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月26日 星期三 16时58分05秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int n,m,d[1000010],now[2001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		cin>>d[i];
	}

	int front = 1, rear = 1, ans_X = 1, ans_Y = 1e7, cnt = 0;
	while(front <= rear){
		if(now[d[rear]] == 0) cnt++;
		if(rear<=n)
		now[d[rear++]]++;
		for( ; now[d[front]] > 1; front++)
			now[d[front]]--;
		if(cnt >= m){
			if(rear - front < ans_Y - ans_X)
				ans_X = front, ans_Y = rear;
		}
		if(rear == n + 1) break;
	}
	cout<<ans_X<<' '<<ans_Y-1<<endl;
    return 0;
}
