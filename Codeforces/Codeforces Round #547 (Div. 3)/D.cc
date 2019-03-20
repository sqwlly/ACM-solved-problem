/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月19日 星期二 23时35分29秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 150010;
vector<int> L[250],R[250],dL,dR;
string a,b;

vector<pair<int,int>> ans;
bool vis_L[N],vis_R[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i) {
		L[a[i]].push_back(i + 1);
		R[b[i]].push_back(i + 1);
	}
	for(int i = 0; i < 250; ++i) {
		if(i == (int)'?') continue;
		int k = min(L[i].size(), R[i].size());
		for(int j = 0; j < k; ++j) {
			ans.push_back(make_pair(L[i][j],R[i][j]));
			vis_L[L[i][j]] = vis_R[R[i][j]] = 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(vis_R[i] == 0 && b[i] != '?') {
			dR.push_back(i);
		}
	}
	for(int i = 0; i < L[(int)'?'].size() && i < dR.size(); ++i) {
		if(vis_L[L[(int)'?'][i]] == 0 && vis_R[dR[i]] == 0) {
			ans.push_back(make_pair(L[(int)'?'][i],dR[i]));
			vis_L[L[(int)'?'][i]] = vis_R[dR[i]] = 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(vis_L[i] == 0 && a[i] != '?') {
			dL.push_back(i);
		}
	}
	for(int i = 0; i < R[(int)'?'].size() && i < dL.size(); ++i) {
		if(vis_R[R[(int)'?'][i]] == 0 && vis_L[dL[i]] == 0) {
			ans.push_back(make_pair(dL[i],R[(int)'?'][i]));
			vis_R[R[(int)'?'][i]] = vis_L[dL[i]] = 1;
		}
	}
	int p = 0, q = 0;
	dL.clear();
	dR.clear();
	for(int i = 0; i < L[(int)'?'].size(); ++i) {
		if(vis_L[L[(int)'?'][i]] == 0) {
			p++;
			dL.push_back(L[(int)'?'][i]);
		}
	}
	for(int i = 0; i < R[(int)'?'].size(); ++i) {
		if(vis_R[R[(int)'?'][i]] == 0) {
			q++;
			dR.push_back(R[(int)'?'][i]);
		}
	}
	int mm = min(dL.size(), dR.size());
	for(int i = 0; i < mm; ++i) {
		ans.push_back(make_pair(dL[i],dR[i]));
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
    return 0;
}
