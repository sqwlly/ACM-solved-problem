/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月12日 星期五 20时53分03秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
string Manacher(string s)
{
    /*改造字符串*/
    string res="$#";
    for(int i=0;i<s.size();++i)
    {
        res+=s[i];
        res+="#";
    }

    /*数组*/
    vector<int> P(res.size(),0);
    int mi=0,right=0;   //mi为最大回文串对应的中心点，right为该回文串能达到的最右端的值
    int maxLen=0,maxPoint=0;    //maxLen为最大回文串的长度，maxPoint为记录中心点

    for(int i=1;i<res.size();++i)
    {
        P[i]=right>i ?min(P[2*mi-i],right-i):1;     //关键句，文中对这句以详细讲解
        
        while(res[i+P[i]]==res[i-P[i]])
            ++P[i];
        
        if(right<i+P[i])    //超过之前的最右端，则改变中心点和对应的最右端
        {
            right=i+P[i];
            mi=i;
        }

        if(maxLen<P[i])     //更新最大回文串的长度，并记下此时的点
        {
            maxLen=P[i];
            maxPoint=i;
        }
    }
    return s.substr((maxPoint-maxLen)/2,maxLen-1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = s.length(), ans = 0;
	for(int i = 0; i < n; ++i) {
		string t = s.substr(i + 1, n - i - 1) + s.substr(0, i + 1);
	//	cout << t << endl;
		ans = max(ans, (int)Manacher(t).length());
	}
	cout << ans << endl;
    return 0;
}
