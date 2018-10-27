/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月27日 星期六 09时37分19秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int d, tot, cnt;
string s1,s2;
void dfs(int step,int i)
{
	if(i == s2.length()){
		tot++;
		if(step == d)
			cnt++;
		return;
	}
/*	if(step == d){
		cnt++;
		return;
	}*/
	if(s2[i] == '+'){
		dfs(step+1,i+1);
	}else if(s2[i] == '-'){
		dfs(step-1,i+1);
	}else if(s2[i] == '?'){
		dfs(step+1,i+1);
		dfs(step-1,i+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>s1>>s2;
	for(int i = 0; i < s1.length(); ++i)
		if(s1[i] == '+') d++; else d--;
//	cout<<d<<endl;
	dfs(0,0);	
//	cout<<cnt<<tot<<endl;
    printf("%.9f\n",1.0*cnt/tot); 
	return 0;
}
