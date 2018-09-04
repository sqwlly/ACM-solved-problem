#include<bits/stdc++.h>
using namespace std;
const int N = 2E5+10;
int a[N],vis[N],x,y,n;
vector<int> e[N], v;

void solve()
{
	if(a[0]!=1){
		puts("No");
		return;
	}
	queue<int> q;
	vis[a[0]] = 1;
	q.push(a[0]);
	v.push_back(a[0]);
	int p = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int size = 0, len = e[u].size();
		for(int i = 0; i < len; ++i){
			if(vis[e[u][i]]==0){
				vis[e[u][i]] = 1;
				size++;
			}
		}
		for(int i = 0; i < size; ++i, ++p){
			vis[a[p]] = 1;
			q.push(a[p]);
			v.push_back(a[p]);
		}
	}
	puts((v.size()==n)?"Yes":"No");
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n-1; ++i){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	solve();
	return 0;
}
