/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月23日 星期三 22时34分25秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int q;
	cin >> q;
	int l1,l2,r1,r2;
	while(q--) {
		cin >> l1 >> r1 >> l2 >> r2;
		int a,b;
		if(l1 == r2) {
			l1++;
		}
		cout << l1 << ' ' << r2 << endl;
	}
    return 0;
}
