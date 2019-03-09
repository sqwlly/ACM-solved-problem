/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月08日 星期五 16时15分07秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 100000+10;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	int MAXL = 0, L = 0, one = 0, two = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] == a[j]) {
				if(a[j] == 1) {
					one++;
				}else{
					two++;
				}
			}else{
				i = j - 1;
				break;
			}
		}
		if(one == two) {
			MAXL = max(MAXL, one + two);
		}
	}
	cout << MAXL << endl;
    return 0;
}
