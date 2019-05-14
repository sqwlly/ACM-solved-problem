/*************************************************************************
    > File Name: hdu4578.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月12日 星期日 11时13分50秒
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
typedef long long LL;
int sum1[N << 2], sum2[N << 2], sum3[N << 2], add[N << 2], mul[N << 2], alt[N << 2];

void pushup(int rt)
{

}

void pushdown(int rt,int l,int r)
{

}

void build(int rt,int l,int r)
{

}

void update(int rt,int l,int r,int x,int y,int v,int d)
{

}

void query(int rt,int l,int r,int x,int y,int p)
{

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int a[3] = {0,1,2};
	dbg(a[0],a[1],a[2]);
    return 0;
}
