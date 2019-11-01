/*************************************************************************
    > File Name: 201909-4.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月11日 星期五 15时25分17秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
constexpr int N = 3E4+10;
struct node{
	int id,score;
	bool operator < (const node &u) const{
		if(score == u.score) {
			return id > u.id;
		}
		return score < u.score;
	}
};

struct newnode{
	int id,score,type;
	bool operator < (const newnode &u) const {
		if(score == u.score) {
			if(type == u.type) {
				return id > u.id;
			}
			return type > u.type;
		}
		return score < u.score;
	}
};

priority_queue<node> pq[N];
map<int,map<int,int>> vis;
int m,n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	int id,score,Q,type;
	for(int i = 0; i < n; ++i) {
		cin >> id >> score;
		for(int j = 0; j < m; ++j) {
			pq[j].push(node{id,score});
		}
	}
	cin >> Q;
	int c,K,k;
	while(Q--) {
		cin >> c;
		if(c == 1) {
			cin >> type >> id >> score;
			pq[type].push(node{id,score});
			vis[type][id] = 0;
		}else if(c == 2) {
			cin >> type >> id;
			vis[type][id] = 1;
		}else if(c == 3) {
			cin >> K;
			priority_queue<newnode> t;
			vector<newnode> v[51];
			for(int i = 0; i < m; ++i) {
				cin >> k;
				while(k > 0 && pq[i].size()) {
					node cur = pq[i].top(); pq[i].pop();
					if(vis[i][cur.id]) {
						continue;
					}
					t.push({cur.id,cur.score,i});
					k--;
				}
			}
			while(K-- && (!t.empty())) {
				newnode cur = t.top(); t.pop();
				v[cur.type].push_back(cur);
				pq[cur.type].push({cur.id,cur.score});
			}
			
			while(!t.empty()) {
				newnode cur = t.top(); t.pop();
				pq[cur.type].push({cur.id,cur.score});
			}
			for(int i = 0; i < m; ++i) {
				if(v[i].size() == 0) cout << -1 << '\n';
				else{
					sort(v[i].begin(), v[i].end(),[](const newnode &u,const newnode& r)->int{return u.id < r.id;});
					for(int j = 0; j < v[i].size(); ++j) {
						cout << v[i][j].id << ' ';
					}
					cout << '\n';
				}
			}
		}
	}

    return 0;
}
