/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月31日 星期日 22时25分25秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int a[2022];
vector<int> odd,even;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] & 1) odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	sort(odd.begin(), odd.end(), greater<int>());
	sort(even.begin(), even.end(), greater<int>());
	long long sum = 0;
	for(int i = min(odd.size(), even.size()); i < odd.size(); ++i) {
		sum += odd[i];
	}
	for(int i = min(odd.size(), even.size()); i < even.size(); ++i) {
		sum += even[i];
	}
	//1 5 7
	//2 8
	int idx = min(odd.size(), even.size());
	if(idx == odd.size()) {
		cout << sum - even[idx] << endl;
	}else{
		cout << sum - odd[idx] << endl;
	}
    return 0;
}
