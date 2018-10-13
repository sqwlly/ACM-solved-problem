/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月12日 星期五 23时11分20秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[10001];

int main()
{
	int n,r;
	cin>>n>>r;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	int cnt = 0, R = 0;
	while(R < n){
		int nxt = -1;
		for(int i = min(n, R + r - 1); i >= max(0, R - r + 1); --i){
			if(a[i]){
				nxt = i;
				break;
			}
		}
		if(nxt == -1) break;
		cnt++;
		R = nxt + r;
	}
	cout<<(R >= n ? cnt : - 1)<<endl;
    return 0;
}
