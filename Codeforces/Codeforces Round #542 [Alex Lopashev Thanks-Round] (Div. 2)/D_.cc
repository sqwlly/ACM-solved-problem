#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ss second
#define ff first
int stat,num;


int dist(int a,int b){
    
    
    if(b>=a) return b-a;
    else return stat-(a-b);
    
}


int main() {
    IOS;
	
	cin>>stat>>num;
	vector<int> cand[stat+1];
	
	//first is number of candies and second is min station for candies
	for(int i=0;i<num;i++){
	    int t1,t2;
	    cin>>t1>>t2;
	    cand[t1].push_back(dist(t1,t2));
	}
	
	for(int i=1;i<=stat;i++) sort(cand[i].begin(),cand[i].end());
	
	int ans;
	for(int i=1;i<=stat;i++){
	    
	    ans = -1;
	    for(int j=1;j<=stat;j++){
	        if(cand[j].size()!=0){
	            
	            int tmp;
	            tmp = (cand[j].size()-1)*stat;
	            tmp+=dist(i,j);
	            tmp+=cand[j][0];
	            ans = max(ans,tmp);
	        }
	    }
	    
	    cout<<ans<<" ";
	}
	
	
	return 0;
}
