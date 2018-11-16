#include <bits/stdc++.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
int main(){
        freopen("data.in","w",stdout);
		const int n = 2 * 1e5, m = 1e6;
		printf("%d\n",n);
		for(int i = 0; i < n; ++i){
			if(i == n - 2) {
				printf("%d ",m - 1);
			}else if(i == n - 1) {
				printf("1\n");
			}else
			printf("%d%c",1000000,i==n-1?'\n':' ');
		}
        return 0;

}
