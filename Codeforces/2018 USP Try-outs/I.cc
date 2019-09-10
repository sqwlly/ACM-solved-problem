/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月03日 星期二 13时11分37秒
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
int step,n,k,res;
void dfs(char a,char b,char c)
{
	if(!res) {
		cout << a << ' ' << c << '\n';
	}else{
		cout << a << ' ' << b << '\n';
		res--;
		dfs(b,a,c);
	}
}

void hannoi(int n,char from,char buffer,char to)
{
	if(n == 0) return;
	hannoi(n - 1, from, to, buffer);
	step++;
	if(step == (1 << n) - 1) {
		dfs(from,buffer,to);
		return;
	}
	cout << from << ' ' << to << '\n';
	hannoi(n - 1, buffer, from, to);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	if(k < (1 << n) - 1) {
		cout << 'N' << '\n';
	}else{
		cout << 'Y' << '\n';
		res = k - (1 << n) + 1;
		hannoi(n, 'A', 'B', 'C');
	}

    return 0;
}
