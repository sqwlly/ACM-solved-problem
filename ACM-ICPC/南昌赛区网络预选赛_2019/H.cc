/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月08日 星期日 13时58分35秒
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
const int MOD = 998244353;
typedef long long LL;
struct Mat {
    static const LL M = 2;
    LL v[M][M];
    Mat() { memset(v, 0, sizeof v); }
    void eye() { for (int i = 0; i < M; ++i) v[i][i] = 1; }
    LL* operator [] (LL x) { return v[x]; }
    const LL* const operator [] (LL x) const { return v[x]; }
    Mat operator * (const Mat& B) {
        const Mat& A = *this;
        Mat ret;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < M; ++j)
                 for (int k = 0; k < M; ++k)
                      ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % MOD;
        return ret;
    }
    Mat pow(LL n) const {
        Mat A = *this, ret; ret.eye();
        for (; n; n >>= 1, A = A * A)
            if (n & 1) ret = ret * A;
        return ret;
    }
    Mat operator + (const Mat& B) {
        const Mat& A = *this;
        Mat ret;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < M; ++j)
                 ret[i][j] = (A[i][j] + B[i][j]) % MOD;
        return ret;
    }
    void prt() const {
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < M; ++j)
                 printf("%lld%c", (*this)[i][j], j == M - 1 ? '\n' : ' ');
    }
};
map<LL,LL> m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL N,Q,A, ans = 0;
	cin >> Q >> N;
	if(N == 0) return cout << 0 << '\n',0;
	Mat a;
	a.v[0][0] = 3, a.v[0][1] = 2, a.v[1][0] = 1;
	Mat b;
	for(int i = 0; i < Q; ++i) {
	//	A = b.v[0][0];
		if(m.count(N)) A = m[N];
		else m[N] = A = a.pow(N - 1).v[0][0];
		assert(A * A > 0);
		assert(N ^ (A * A) > 0);
		N = N ^ (A * A);
//		dbg(N);
		ans ^= A;
	}
	cout << ans%MOD << '\n';
    return 0;
}

