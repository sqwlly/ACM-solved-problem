/*************************************************************************
  > File Name: I.cc
  > Author: sqwlly
  > Mail: sqw.lucky@gmail.com 
  > Created Time: 2019年09月07日 星期六 12时21分18秒
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
struct QUERY{
	int left,right;
}q[N];

int sort_kuai(QUERY a, QUERY b) {
	//莫队算法的分块核心，同块比右，否则比左
	if (a.be == b.be) return a.right < b.right;
	else return a.left < b.left;
}

void revise(int x, int add) {
	//区间处理，并且更新答案
	if(gcd)
}

int pointer_left = 1, pointer_right = 0;
for (int i = 1; i <= Q; i++) {
	while (pointer_left < q[i].left) revise(CXK[pointer_left].value, -1), pointer_left++;
	while (pointer_left > q[i].left) revise(CXK[pointer_left - 1].value, 1), pointer_left--;
	while (pointer_right < q[i].right) revise(CXK[pointer_right + 1].value, 1), pointer_right++;
	while (pointer_right > q[i].right) revise(CXK[pointer_right].value, -1), pointer_right--;
	q[i].ans = ANSWER;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	
	sort(q + 1, q + 1 + Q, sort_kuai);
	return 0;
}
