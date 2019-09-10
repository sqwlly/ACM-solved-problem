/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月10日 星期二 10时30分37秒
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
priority_queue<int> pq;
string s;
int n;
vector<int> E[N];
bool vis[N], go[N];
void bfs(int s,int e) 
{
	pq.push();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> s;
		vector<int> pos;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == 'o') {
				pos.push_back(i);
				go[i] = 1;
			}
		}
		
	}
    return 0;
}
