#include<bits/stdc++.h>

int a[100010];
int bit[32];
//寻找1的高位位置 
int findHigh1(int x){
	int h=31;
	while(h>=0){
		if(x&(1<<h)){
			bit[h]++;
			break;
		}
		h--;
	}
	return h;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 0; i < 33; ++i){
			bit[i] = 0;
		}
		for(int i = 0; i < n; ++i){
			scanf("%d",a+i);
			findHigh1(a[i]);
		}
		int ret = 0;
		for(int i = 0; i < 32; ++i){
			ret = std::max(ret,bit[i]);
		}
		printf("%d\n",ret);
	}
	return 0;
}

