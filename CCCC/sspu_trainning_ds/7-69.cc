/*************************************************************************
    > File Name: 7-69.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月29日 星期五 15时45分21秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E6+10;
int nxt[N];
string p,q;

//优化过后的next 数组求法
void GetNextval()
{
	int pLen = q.length();
	nxt[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || q[j] == q[k])
		{
			++j;
			++k;
			//较之前next数组求法，改动在下面4行
			if (q[j] != q[k])
				nxt[j] = k;   //之前只有这一行
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
				nxt[j] = nxt[k];
		}
		else
		{
			k = nxt[k];
		}
	}
}

int KmpSearch()
{
	int i = 0;
	int j = 0;
	int sLen = p.length();
	int pLen = q.length();
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
		if (j == -1 || p[i] == q[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
			//next[j]即为j所对应的next值
			j = nxt[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> p;
	int n;
	cin >> n;
	while(n--) {
		cin >> q;
		memset(nxt, 0, sizeof nxt);
		GetNextval();
		string ret = "";
		int dx = KmpSearch();
		if(dx != -1) {
			ret = p.substr(dx, p.length());
		}else{
			ret = "Not Found";
		}
		cout << ret << endl;
	}
    return 0;
}
