#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e6+10;

int a[N];
LL pre[N],suf[N];

int main(){
	int n,k;
	while(cin >> n >> k) {
		LL sum = 0;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			sum += a[i];
			suf[i]=suf[i-1]+a[i];
			//  pre[i] = pre[i-1] + (a[i] - a[i-1])*i;
		}
		sort(a + 1,a + 1 + n);
		for(int i = 1; i <= n; ++i){
			pre[i] = 1LL * i*a[i]-suf[i];
		}
		bool ok = 0;
		for(int i = 1,j=n; i<=n; ) {
			if(pre[i] <= k && i != n) i++,j--;
			else{
				LL mi = (k-pre[i-1])/(i-1)+a[i-1];
				LL mx = (pre[i-1]-k)/(n-j)+a[j+1];
				//   cout << mx << ' '<<mi<<endl;
				ok = 1;
				cout << (mi<mx?mx-mi:(sum%n!=0))<< '\n';
				break;
			}

		}
		if(!ok)
		cout << (sum % n!=0) << '\n';
	}
	return 0;
}

