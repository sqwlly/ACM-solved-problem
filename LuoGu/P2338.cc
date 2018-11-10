#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    int n, d; char op;
    double curDis = 0, curT = 0;
    vector<int> a,b;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>op>>d;
        if(op == 'T') {
            a.push_back(d);
        }else{
            b.push_back(d);
        }
    }
    b.push_back(1000);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int x = 0, y = 0, cnt = 1;
    while(x < a.size() || y < b.size()) {
		bool f = y == b.size();
		if(!f && x < a.size()) 
			f = (curT + (b[y] - curDis) * cnt > a[x]);
		if(f) {
			curDis += (a[x] - curT) * 1.0 / cnt;
			curT = a[x++];
		}else{
			curT += (b[y] - curDis) * cnt;
			curDis = b[y++];
		}
		cnt++;
    }
    //cout<<curDis<<' '<<curT<<endl;
	printf("%.0lf\n",curT);
    return 0;
}


