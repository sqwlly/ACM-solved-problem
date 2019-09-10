/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月08日 星期日 12时22分43秒
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
const int N = 2E5+10;
int nxt[N][10],cnt[N][10];

void init(string s)
{
	for(int i = s.length(); i >= 1; --i) {
		for(int j = 9; j >= 0; --j) {
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][s[i - 1] - '0'] = i;
	}
	for(int i = 1; i <= s.length(); ++i) {
		for(int j = 0; j < 10; ++j) {
			cnt[i][j] = cnt[i - 1][j];
		}
		cnt[i][s[i - 1] - '0']++;
	}
}
vector<int> v = {9,1,0,2};
void solve(int l,int r)
{
	bool ok = 1;
	vector<int> pos;
	for(int i = 0; i < v.size(); ++i) {
		pos.push_back(nxt[l][v[i]]);
		if(nxt[l][v[i]] > r) {
			ok = 0;
			break;
		}
		while(i > 0 && nxt[l][v[i]] < nxt[l][v[i - 1]] && l <= r) l++;
		if(l > r) ok = 0;
	}
	if(!ok) {
		cout << -1 << '\n';
		return;
	}
	

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	int n,q,l,r;
	cin >> n >> q >> s;
	init(s);
	for(int i = 0; i < q; ++i) {
		cin >> l >> r;
	}
    return 0;
}
