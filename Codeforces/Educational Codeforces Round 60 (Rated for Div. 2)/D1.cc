#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007
unordered_map<ll,ll> mem;
ll m;
ll DP(ll n){
	if(n<0)return 0;
	if(n<m)return mem[n]=1;
	if(mem.find(n)!=mem.end())return mem[n];
	ll  mid = (n+1)/2, ret = (DP(mid-1)*DP(n-mid))%MOD;
	for(ll i = 1; i<=m;i++){
		
		ret = (ret+(DP(mid-i)*DP(n-m-mid+i))%MOD)%MOD;
	}
	return mem[n]=ret;
}

int main(){
	ll n;
	cin>>n>>m;
	mem[0]=0;
	mem[1]=1;
	cout<<DP(n);
	return 0;
}
