/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月20日 星期六 14时55分03秒
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
const int N = 1010;
int n,m,rectangle,a[N][N],Left[N][N],Right[N][N],h[N][N];
#define P pair<int,int>
int H[N][N],A[N];
stack<int> st;
vector<P> v;

P ans;

void solve(int ret) 
{
	if(ret > ans.first) {
		ans = P(ret, ans.first);
	}else if(ret > ans.second) {
		ans.second = ret;
	}
}

void update(int x,int y)
{
	solve(x * y);
	solve(x * (y - 1));
	solve((x - 1) * y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    string s;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i){
		cin >> s;
        for(int j = 1; j <= m; ++j){
			a[i][j] = ((s[j - 1] == '1')? 1 : 0);
			if(a[i][j] == 1) H[i][j] = H[i - 1][j] + 1;
			else H[i][j] = 0;
        }
    }
	int top = 0;
	for(int i = 1; i <= n; ++i) {
		top = 0;
		for(int j = 1; j <= m; ++j) {
			A[j] = H[i][j];
	//		cout << A[j] << ' ';
		}
//		cout << endl;
		while(!st.empty()) st.pop();
		for(int j = 1; j <= m + 1; ++j) {
			if(st.empty() || A[j] >= A[st.top()]) {
				st.push(j);
			}else{
				while(!st.empty() && A[j] < A[st.top()]) {
					top = st.top();
					st.pop();
					int t = (st.empty() ? (j - 1) : (j - st.top() - 1));
			//		dbg(j, t, A[top]);
					update(t, A[top]);
				}
				st.push(j);
			}
		}
	}
	//dbg(ans.first);
	cout << ans.second << endl;
	return 0;
	/*
    for(int i = 1; i <= n; ++i){
        for(int j = 2; j <= m; ++j){
            if(a[i][j] == a[i][j - 1] && a[i][j] == 1) Left[i][j] = Left[i][j - 1];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = m - 1; j >= 1; --j){
            if(a[i][j] == a[i][j + 1] && a[i][j] == 1) Right[i][j] = Right[i][j + 1];
        }
    }
	int fh,fw;
    for(int i = 1; i <= m; ++i) Left[0][i] = 0, Right[0][i] = m + 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == a[i - 1][j] && i != 1 && a[i][j] == 1) {
                h[i][j] += h[i - 1][j];
                Left[i][j] = max(Left[i][j],Left[i - 1][j]);
                Right[i][j] = min(Right[i][j],Right[i - 1][j]);
            }
			v.push_back(P((Right[i][j] - Left[i][j] + 1), h[i][j])); 
            rectangle = max(rectangle, h[i][j] * (Right[i][j] - Left[i][j] + 1));
        }
	sort(v.begin(),v.end(),
	[](const P &u,const P &r) ->int{ 
		return u.first * u.second > r.first * r.second;	
	});
	dbg(v.size());
	for(int i = 0; i < v.size(); ++i) {
		dbg(v[i].first,v[i].second,v[i].first * v[i].second);
	}
	if(v.size() <= 1) {
		cout << 0 << endl;
		return 0;
	}
    cout<< v[1].first * v[1].second <<endl;
    return 0;*/
}

/*
3 4
1001
1111
1111
*/
