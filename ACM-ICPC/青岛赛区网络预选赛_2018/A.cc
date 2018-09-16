#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int ret = n-m, max1 = m;
		
		printf("%d %d\n",max1,(int)ceil(1.0*m/(ret+1)));
	}
    return 0;
}
