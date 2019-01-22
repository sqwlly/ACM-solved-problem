#include <bits/stdc++.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
int main(){
         freopen("input.in","w",stdout);
        srand(time(0));
		int T = 100;
		printf("100\n");
        while(T--) {
		int n=rand()%1000;
        while(n==1) n=rand()%1000;
        printf("%d\n",n);
        for(int i = 1; i <= n; ++i) {
                printf("%d%c", rand()%(int)1e8,i==n?'\n':' ');
        }
		}
        return 0;
}
