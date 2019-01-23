/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月22日 星期二 22时33分33秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	cout<<n<<endl;
	for(int i = 1; i <= n; ++i) {
		printf("%d%c",1,i==n?'\n':' ');
	}
    return 0;
}
