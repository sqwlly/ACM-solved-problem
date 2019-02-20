#include <bits/stdc++.h>
using namespace std;
vector <int> UD(100000+1);
vector <int> LR(100000+1);
int n;

typedef long long ll;


int check(ll step,int x1,int y1, int x2,int y2)
{
    ll xl=x1+LR[n]*(step/n)+LR[step%n];
    ll yl=y1+UD[n]*(step/n)+UD[step%n];
    return (abs(x2-xl)+abs(y2-yl) <= step);
}

int main() {
    int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	
	char c[n+5];
	scanf("%s", c);
	

	UD[0]=0;
	LR[0]=0;
	for(int i=0;i<n;i++)
	{
		LR[i+1]=LR[i];
		UD[i+1]=UD[i];
		if(c[i]=='U') UD[i+1]++;
		if(c[i]=='D') UD[i+1]--;
		if(c[i]=='L') LR[i+1]--;
		if(c[i]=='R') LR[i+1]++;
	}
	
	
	ll step=(1LL<<50)-1;
	if (check(step,x1,y1,x2,y2)==0) cout<<-1;
	else 
	{
	    for(ll i=49;i>=0;i--) 
	    
	    if(check(step-(1LL<<i),x1,y1,x2,y2)==1) 
	    step-=1LL<<i;
	    
	    cout<<step<<endl;
	}
	
	return 0;
}
