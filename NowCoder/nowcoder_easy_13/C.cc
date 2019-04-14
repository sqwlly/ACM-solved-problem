/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月12日 星期五 21时10分27秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	//x      -> 2
	//y      -> 4
	//x <= y ok
	//b      -> 3
	//a      -> 1
	//a <= 2y ok
	//
	//a + x + y = n - b ==> a + x = n - b - y
	//x + a <= 3y => ok ==> n - b - y <= 3y
	//                      n - b - 4y <= 0 => n <= 4y + 
	cout << (1 <= (2 < 3)) << endl;
    return 0;
}
