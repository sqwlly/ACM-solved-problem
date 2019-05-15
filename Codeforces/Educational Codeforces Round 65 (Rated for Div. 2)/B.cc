/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月15日 星期三 23时11分24秒
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

void ask(int i,int j)
{
	cout << "? " << i << ' ' << j << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int a[6] = {4,8,15,16,23,42}, ans[6] = {0};
	int x;
	for(int i = 0; i < 4; ++i) {
		ask(i + 1, i + 2);
		cin >> ans[i];
	}
	do{
		int cnt = 0,ok = 1;
		for(int i = 0; i < 4; ++i) {
			if(a[i] * a[i + 1] != ans[i]) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			cout << "! " ;
			for(int i = 0; i < 5; ++i) {
				cout << a[i] << ' ';
			}
			cout << a[5] << endl;
			return 0;
		}

	}while(next_permutation(a, a + 6));
    return 0;
}
