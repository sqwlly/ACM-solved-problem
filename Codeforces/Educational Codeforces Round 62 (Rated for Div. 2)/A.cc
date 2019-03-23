/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月22日 星期五 23时04分05秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E4+10;
int a[N];

bool vis[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int day = 0, MAX = 0;
	for(int i = 1; i <= n; ) {
		while(vis[i] == 0 && vis[a[i]] == 0) {
			vis[i] = 1;
			MAX = max(MAX,a[i]);
			if(i < MAX) {
				i++;
			}else{
				break;
			}
		}
		i++;
		day++;
	}
	cout << day << endl;
    return 0;
}
