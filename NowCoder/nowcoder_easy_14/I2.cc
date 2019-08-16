#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
 
long long n,i,a,b;
long long sum;
 
int main(){
	scanf("%lld",&n);
	//sum = 0;
	//for(i=1;i<=n;i++)
	//	sum += i * (n / i);
	//printf("n = %lld\n",n);
	//printf("%lld\n",sum);
	sum = 0;
	for(i=1;i*i<=n;i++){
		sum += i * (n / i);
		b = n/i;
		a = n/(i+1)+1;
		//if (i==1) printf("%lld %lld\n",a,b);
		sum += (a+b) * (b-a+1) / 2 * i;
	}
	i--;
	if (i == n / i)
		sum -= i * (n / i);
	printf("%lld\n",sum);
	return 0;
}
