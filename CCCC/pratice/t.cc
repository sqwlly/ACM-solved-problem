#include<bits/stdc++.h>

#define P pair<int,int>

using namespace std;

const int N = 1024;

vector<int> E[102];

struct node{

	int x,y;

}a[102];



int dis(node a,node b)

{

	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y);

}

int n,d;



bool check(int u)

{

	if(a[u].x + d <= -50 || a[u].y - d <= -50 || a[u].x + d >= 50 || a[u].y + d >= 50)

	return 1;

	return 0;

}



bool bfs()

{

	queue<int> pq;

	pq.push(0);

	while(!pq.empty()) {

		int u = pq.front(); pq.pop();

		if(check(u)) return 1;

		for(int i = 0; i < E[u].size(); ++i) {

			int v = E[u][i];

			if(u == 0) {

				if((d + 7.5) * (d + 7.5) < a[v].x * a[v].x + a[v].y * a[v].y) continue;

			}

			if(dis(a[u],a[v]) > d * d) continue;

			pq.push(v);
		}
	}
	return 0;

}



int main()

{

	//freopen("input.txt","r",stdin);

	cin >> n >> d;

	for(int i = 1; i <= n; ++i) {

		cin >> a[i].x >> a[i].y;

		E[0].push_back(i);

	}

	for(int i = 1; i <= n; ++i) {

		for(int j = 1; j <= n; ++j) {

			if(i == j) continue;

			E[i].push_back(j);

		}

	}

	puts((bfs())?"Yes":"No");

	return 0;

}
