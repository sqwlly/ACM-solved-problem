#include <bits/stdc++.h>
using namespace std;

long long n,k,m,q;

int main(){
    cin>>q;
    while(q--){
        cin >> n >> m >>k;
        long long ans = k;
        if(k < max(n,m)){
            puts("-1");
        }else{
            if((k - n) & 1) ans--;
            if((k - m) & 1) ans--;
            cout<< ans << endl;
        }
    }

	  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	int q;
	scanf("%d", &q);

	while(q--){
		LL n, m, k;
		scanf("%I64d%I64d%I64d", &n, &m, &k);


		LL Max = max(n, m);
		if(Max > k){
			puts("-1");
			continue;
		}



		LL Min = min(n, m);
		LL Mid = Max - Min;
		if(Mid % 2){        //这类 点 只走 对角线 无法到达
			printf("%I64d\n", k - 1);
		}else{             //这类点只走对角线可以到达

			if(((k - Max) & 1LL) == 0){  //不用浪费步数,只走对角线到达目标点,多出的步数也通过对角线消耗
				printf("%I64d\n", k);
			}else{                 //这类点多出来的步数无法通过对角线完全消耗,故需要将1个对角线化为两个边线
				printf("%I64d\n", k - 2);
			}

		}
	}
	return 0;
}*/
