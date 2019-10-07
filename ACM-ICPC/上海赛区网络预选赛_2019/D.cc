/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月15日 星期日 12时03分48秒
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
const int N = 1E6+10;
long long sum[N][11];
int S(int n,int b)
{
	int t = 0;
	while(n > 0) {
		t += n % b;
		n /= b;
	}
	return t;
}

void init()
{
	int inc = 1;
	for(int b = 2; b <= 10; ++b) {
		sum[1][b] = 1;
	//	inc = 2;
		for(int j = 2; j < N; ++j) {
			for(int k = 1; k <= j; ++k)
			sum[j][b] += S(k,b);
	//		sum[j][b] = sum[j - 1][b] + inc;
	//		inc = (inc + 1) % b;
	//		inc = inc ? inc : 1;
		}
	}
}

unordered_map<int,int> m;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,b,w=0;
	init();
	cin >> T;

	while(T--) {
		cin >> n >> b;
		
	//	int t = 0;
	//	for(int j = 1; j <= 20; ++j) {
	//		t = 0;
	//	for(int i = 1; i <= j; ++i) {
	//		t += S(i,3);
	//	}
	//	cout << j << ' ' << t << endl;
	//	}
		cout << "Case #" << ++w << ": " << sum[n][b] << '\n';
	}
    return 0;
}
