/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月16日 星期六 20时04分07秒
 ************************************************************************/

#include<iostream>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int a,b;
	cin >> a >> b;
	if(b % a == 0) 
	{
		cout << a + b << endl;
	}else{
		cout << b - a << endl;
	}
    return 0;
}
