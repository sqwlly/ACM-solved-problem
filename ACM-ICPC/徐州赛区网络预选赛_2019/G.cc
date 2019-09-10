/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月07日 星期六 14时46分10秒
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
const int N = 6E5+10;
int last[N][30],p[N];
char s[N],st[N];
int change()
{
    int len=strlen(st);
    int j=2;
    s[0]='^';
    s[1]='$';
    for (int i=0;i<len;i++)
    {
        s[j++]=st[i];
        s[j++]='$';
    }
    s[j]='&';
    return j;
}
void init(int len)
{
	for(int i = 0; i < 26; ++i) {
		last[len][i] = len;
	}
	for(int i = len - 1; i >= 0; --i) {
		for(int j = 0; j < 26; ++j) {
			last[i][j] = last[i + 1][j];
		}
		last[i][st[i] - 'a'] = i;
	}
}
LL Manacher()
{
	int len = change(), mid = 1, mx = 1;
	init(strlen(st));
	LL ans = 0;
	for (int i = 1; i < len; i++)
	{
		if (i < mx)
			p[i] = min(mx - i, p[mid * 2 - i]);
		else
			p[i] = 1;
		while (s[i - p[i]] == s[i + p[i]])
			p[i]++;
		if(mx < i + p[i])
		{
			mid = i;
			mx = i + p[i];
		}
	}
	int ori;
	for(int i = 1; i < len; ++i) {
		if(i & 1) 
			ori = (i + 1) / 2 - 1;
		else
			ori = i / 2 - 1;
		int cnt = p[i] / 2;
		for(int j = 0; j < 26; ++j) {
			if(last[ori][j] - ori < cnt) {
				ans += cnt - (last[ori][j] - ori);
			}
		}
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%s",st);
	printf("%lld\n",Manacher());
    return 0;
}
