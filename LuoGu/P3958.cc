/*************************************************************************
    > File Name: P3958.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月18日 星期二 17时32分39秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct ball{
	int x,y,z;	
	bool operator < (const ball & u) const {
		return z < u.z;
	}
}a[1010];

int n,h,r,T,e[1010][1010];
bool vis[1010][1010];

double dist(ball p1,ball p2)
{
	return sqrt(1LL*(p1.x-p2.x)*(p1.x-p2.x)+1LL*(p1.y-p2.y)*(p1.y-p2.y)+1LL*(p1.z-p2.z)*(p1.z-p2.z));
}

bool love(ball p,ball q)
{
	return dist(p,q) - r*2 <= 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof vis);
		scanf("%d%d%d",&n,&h,&r);
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i==j) e[i][j] = 1;
                else e[i][j] = (1<<30);
            }
        }
		sort(a,a+n);
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				if(love(a[i],a[j])){
					e[i][j] = 1;
					//printf("%d %d\n",i,j);
					e[j][i] = 1;
				}
			}
		}
		bool f = 0;
		queue<int> pq;
		for(int i = 0; i < n; ++i){
			if(a[i].z - r <= 0){
				pq.push(i);
	//			printf("i = %d z = %d r = %d\n",i,a[i].z,r);
			}
		}

		while(!pq.empty()){
			int cur = pq.front();
			pq.pop();
			if((a[cur].z + r) >= h) {
				f = 1;
	//			printf("%d %d %d\n",a[cur].x,a[cur].y,a[cur].z);
				break;
			}
			for(int i = 0; i < n; ++i){
				if(!vis[cur][i]&&e[cur][i]==1){
					vis[cur][i] = 1;
					pq.push(i);
				}
			}
		}
		if(a[0].z - r > 0) f = 0; 
		puts(f?"Yes":"No");
	}
    return 0;
}
