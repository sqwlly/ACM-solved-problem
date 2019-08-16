/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月10日 星期六 12时10分23秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
const int N = 1E5+10, M = 1e5+10, BLOCK = sqrt(N); //~sqrt(N)

int first[N],last[N],a[N],p[N];
long long d[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,l,r,tot = 0, ans = 0;
	cin >> n;
	memset(first, -1, sizeof first);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = d[i - 1];
		if(first[a[i]] == -1) {
			tot++;
			first[a[i]] = i;
			for(int j = 1; j <= i; ++j) {
				d[i] += p[j - 1] + 1;
				p[j] = p[j - 1] + 1;
			}
//			d[i] += i * (i + 1) / 2 + tot;
//			dbg(i * (i + 1) / 2);
		}else{
			d[i] += i;
		}
	//	ans += d[i];
	}
	cout << d[n] << endl;
	//1 1 1 
	//3 = 1 + 1 + 1
	//1 + 1 + 1 + 1 + 1 + 1
//	cout << ans << endl;
	//1 + 2 + 2 + 3
	//
	//size      1   2       3    4    5 ... n-1  n
	//cnt       n  n-1      n-2  n-3  n-4    2   1
	//ans       n  max[n-1]  
	//
    return 0;
}

