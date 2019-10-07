/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月02日 星期三 12时05分52秒
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
const int N = 1E5+10;

#define lowbit(x)  ((x) & (-x))
struct BIT{
	int tree[N],n;
	void update(int x,int k)
	{
		while(x <= n) {
			tree[x] += k;
			x += lowbit(x);
		}
	}

	int query(int x)
	{
		int ret = 0;
		while(x > 0) {
			ret += tree[x];
			x -= lowbit(x);
		}
		return ret;
	}

}bit[26];

int getsum(int l,int r)
{
	int cnt = 0;
	for(int i = 0; i < 26; ++i) {
		if(bit[i].query(r) - bit[i].query(l - 1) > 0) {
			cnt++; 
		}
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	int q;
	cin >> s >> q;
	for(int i = 0; i < 26; ++i) bit[i].n = s.size();
	for(int i = 0; i < s.size(); ++i) {
		bit[s[i] - 'a'].update(i + 1, 1);
	}
	int c,l,r,x;
	char ch;
	while(q--) {
		cin >> c;
		if(c == 1) {
			cin >> x >> ch;
			bit[s[x - 1] - 'a'].update(x, -1);
			s[x - 1] = ch;
			bit[s[x - 1] - 'a'].update(x, 1);
		}else{
			cin >> l >> r;
			cout << getsum(l,r) << '\n';
		}
	}
    return 0;
}
