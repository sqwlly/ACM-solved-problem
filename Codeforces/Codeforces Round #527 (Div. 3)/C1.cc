#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 300010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int N;
vi vec;
string S[1010];

string pre(int a, int b) {
	rep(i, 0, N - 2) {
		if(S[a][i + 1] != S[b][i]) return "";
	}
	string ans = S[a] + S[b].back();
	string tmp(2 * N - 2, '$');
	tmp[a] = 'P';
	tmp[b] = 'S';
	rep(i, 1, N - 1) {
		vi vec;
		rep(j, 0, 2 * N - 2) {
			if(sz(S[j]) == i) vec.pb(j);
		}
		if(ans.substr(0, i) == S[vec[0]] && ans.substr(N - i, -1) == S[vec[1]]) {
			tmp[vec[0]] = 'P';
			tmp[vec[1]] = 'S';
		}
		else if(ans.substr(0, i) == S[vec[1]] && ans.substr(N - i, -1) == S[vec[0]]) {
			tmp[vec[0]] = 'S';
			tmp[vec[1]] = 'P';
		}
		else return "";
	}
	return tmp;
}

void solve() {
	cin >> N;
	rep(i, 0, 2 * N - 2) {
		cin >> S[i];
		if(sz(S[i]) == N - 1) vec.pb(i);
	}
	string ans;
	ans = pre(vec[0], vec[1]);
	if(ans != "") {
		cout << ans << "\n";
		return;
	}
	ans = pre(vec[1], vec[0]);
	if(ans != "") {
		cout << ans << "\n";
		return;
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
