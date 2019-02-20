/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月22日 星期二 23时11分21秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[4][4];
int check(int tag)
{
	if(tag) {
		for(int i = 0; i < 4; ++i) {
			if(a[i][0] == a[i][3] && a[i][0] && a[i][1] == a[i][2] && a[i][1] == 0) {
				printf("%d %d\n",i + 1, 2);
				for(int j = 0; j < 4; ++j) {
					a[i][j] = 0;
				}
				return 1;
	//			break;
			}
		}
	}else{
		for(int i = 0; i < 4; ++i) {
			if(a[0][i] == a[3][i] && a[0][i] && a[1][i] == a[2][i] && a[1][i] == 0) {
				printf("%d %d\n",2, i + 1);
				for(int j = 0; j < 4; ++j) {
					a[j][i] = 0;
				}
				return 1;
	//			break;
			}
		}
	}
	return 0;
}

void refresh()
{
	for(int i = 0; i < 4; ++i) {
		int f = 0;
		for(int j = 0; j < 4; ++j) {
			if(a[i][j]) {
				f++;
			}
		}
		if(f == 4) {
			for(int j = 0; j < 4; ++j) {
				a[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < 4; ++i) {
		int f = 0;
		for(int j = 0; j < 4; ++j) {
			if(a[j][i]) {
				f++;
			}
		}
		if(f == 4) {
			for(int j = 0; j < 4; ++j) {
				a[j][i] = 0;
			}
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	//1 1
	//0 0 0 0
	//1 0 0
	string s;
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len; ++i) {
		refresh();
		if(s[i] == '0') {
	//		if(check(0)) continue;
			int f = 0;
			for(int j = 0; j < 4; j++) {
				for(int k = 0; k < 4; k += 2) {
					if(a[k][j] == 0 && a[k + 1][j] == 0 && k < 4) {
						a[k][j] = a[k + 1][j] = 1;
						printf("%d %d\n",k + 1, j + 1);
						f = 1;
						break;
					}
				}
				if(f) break;
			}
		}else{
			int f = 0;
	//		if(check(1)) continue;
			for(int j = 0; j < 4; j++) {
				if(a[j][2] == 0 && a[j][3] == 0) {
					a[j][2] = a[j][3] = 1;
					printf("%d %d\n",j + 1, 3);
					f = 1;
					break;
				}
				if(f) break;
			}
		}
	}
    return 0;
}
