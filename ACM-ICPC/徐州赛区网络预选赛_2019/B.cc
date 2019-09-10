/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月07日 星期六 12时13分00秒
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
struct QUERY{
	int c,x;
}Q[N];
unordered_map<int,int> f;

int getf(int v)
{
	if(f.count(v) == 0) f[v] = v;
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

inline void g(int x)
{
	f[x] = getf(x) + 1;
}
vector<int> v;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q,c,x;
	cin >> n >> q;
	for(int i = 0; i < q; ++i) {
		cin >> Q[i].c >> Q[i].x;
		f[Q[i].x] = Q[i].x;
		v.push_back(Q[i].x);
	}
	for(int i = 0; i < q; ++i) {
		if(Q[i].c == 1) {
			g(Q[i].x);
		}else{
			cout << getf(Q[i].x) << '\n';
		}
	}
    return 0;
}
