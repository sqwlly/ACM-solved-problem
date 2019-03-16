/*************************************************************************
    > File Name: t.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月16日 星期六 13时02分06秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
void solve(int Q, int type[], long long first[], long long second[]) {
    vector<long long> vec;
    for (int i = 0; i < Q; ++i) {
        if (type[i] == 1) {
            long long k = first[i], val = second[i];
            while (k--) {
                vec.push_back(val);
            }
        }
        else if (type[i] == 2) {
            sort(vec.begin(), vec.end());
            long long l = first[i] - 1, r = second[i], res = 0;
            while (l < r) {
                res = (res + vec[l++]) % 1000000007;
            }
            printf("%lld\n", res);
        }
    }
}
const int N = 1E5+10;
int type[N];
long long a[N],b[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		cin >> type[i] >> a[i] >> b[i];
	}
	solve(q,type,a,b);
	return 0;
}
