/*************************************************************************
    > File Name/ poj1753.cc
    > Author/ sqwlly
    > Mail/ sqw.lucky@gmail.com 
    > Created Time/ 2018年10月10日 星期三 18时05分20秒
 ************************************************************************/

#include<iostream>

using namespace std;
bool a[6][6];

bool check()
{
	char pre = a[0][0];
	for(int i = 0; i <= 3; ++i){
		for(int j = 0; j <= 3; ++j){
			if(a[i][j] != pre)
				return 0;
		}
	}
	return 1;
}

int change_row[] = {0,-1,0,1,0};
int change_col[] = {0,0,1,0,-1};

void flip(int row , int col){
	for(int i = 0 ; i < 5 ; i++)
		a[row+change_row[i]][col+change_col[i]] = !a[row+change_row[i]][col+change_col[i]];	
}

int f = 0,step = 0;
void dfs(int x,int y,int deep)
{
	if(step == deep){
		f = check();
		return;
	}
	if(f || x > 3 || y > 3 || x < 0 || y < 0) return;
	flip(x,y);
	if(x < 3)
		dfs(x + 1, y, deep + 1);
	else
		dfs(0, y + 1, deep + 1);
	flip(x,y);
	if(x < 3)
		dfs(x + 1, y, deep);
	else
		dfs(0, y + 1, deep);
	return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	char x;
	for(int i = 0; i <= 3; ++i){
		for(int j = 0; j <= 3; ++j){
			cin>>x;
			a[i][j] = ((x == 'w') ? 1 : 0);
		}
	}
	for(step = 0; step <= 16; ++step){
		dfs(0,0,0);
		if(f) break;
	}
	if(f)
		cout<<step<<endl;
	else
		cout<<"Impossible"<<endl;
    return 0;
}
