/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月17日 星期六 12时18分42秒
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
typedef long long LL;

string s[511];
map<string,vector<pair<int,int>> > mp;
vector<string> st[50];
set<string> s1[50];


void dfs(LL k,int n)
{
	
}


int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n;
	s[1] = "COFFEE", s[2] = "CHICKEN";
	s[3] = "COFFEECHICKEN";
	
	LL f[550];
	fill(f, f + 550, LLONG_MAX);
	f[0] = 0, f[1] = 6, f[2] = 7;
	for(int i = 3; i <= 60; ++i) {
		if(f[i - 2] + f[i - 1] > 1e12) break;
		f[i] = f[i - 2] + f[i - 1];
	}
	for(int i = 3; i <= 10; ++i) {
		s[i] = s[i - 2] + s[i - 1];
	}

	for(int i = 1; i <= 30; ++i) {
		for(int k = 0; k < s[i].length(); ++k) {
			string t = s[i].substr(k,10);
			int find1 = 0;
			if(s1[i].find(t) == s1[i].end()) {
		//		dbg(k);
			}
			s1[i].insert(t);
		}
	//	dbg(s[i].size(), s1[i].size());
		for(int j = 1; j <= i; ++j) {
			if(s1[i] == s1[j]) {
		//		dbg(i,j);
				break;
			}
		}
	}
	int even[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,25,26,27,28,29,30,31,32};
	int odd[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,45};
	LL k;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		if(n > 7) {
			if(k <= 45) {
				if(n & 1) {
					for(int i = 0; i < 21; ++i) {
						if(odd[i] >= k) {
							cout << s[7].substr(odd[i - 1],10) << endl;
						}	 
					}
				}else{
					for(int i = 0; i < 21; ++i) {
						if(even[i] >= k) {
							cout << s[7].substr(even[i - 1],10) << endl;
							break;
						}
					}
				}
			}else{
				if(f[n] == LLONG_MAX) {
					
				}else{
					if(k < f[n] - 9) {
						if(n & 1)
							k = odd[20];
						else
							k = even[20];
						dbg(k);
						cout << s[7].substr(k + 1, 10) << endl;
					}else{
						cout << s[7].substr(77 + (9 - (f[n] - k)) - 1, 10) << endl;
					}
				}
			}
		}else{
			cout << s[n].substr(k - 1,10) << endl;
		}
	}

	/*
	for(int i = 1; i <= 20; ++i) {
		for(int k = 1; k <= s[i].length(); ++k) {
			string t = s[i].substr(k - 1,10);
			if(i == 15 && k == 4003) {
				dbg(t);
			}
			mp[t].push_back(make_pair(i,k));
			if(st.find(t) != st.end()) {
				//cout << k << endl;
			}
			//cout << t << endl;
			st.insert(t);
		}
	}*/
	/*
	LL len = 0;
	for(auto i : mp) {
		cout << i.first << " : ";
		for(int j = 0; j < i.second.size(); ++j) {
			cout << i.second[j].first << ' ' << i.second[j].second << "    ";
			if((j + 1) % 10 == 0) cout << endl;
		}
		cout << endl;
	}*/
	//vector<string> v;
//	cout << st.size() << endl;
//	for(auto i : st) {
//		v.push_back(i);
//		cout << i << endl;
//	}
//	cout << "-----------------------" << endl;
//	sort(v.begin(),v.end(),[](const string &u,const string &r) ->int {return u.size() < r.size();});
//	for(auto i : v) {
//		cout << i << endl;
//	}
    return 0;
}
