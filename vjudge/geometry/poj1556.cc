/*************************************************************************
    > File Name: poj1556.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月01日 星期五 16时05分51秒
 ************************************************************************/
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
const double eps = 1e-8;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))

struct point
{
    double x,y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator - (const point& b) const { return point(x - b.x, y - b.y); }
    point operator + (const point& b) const { return point(x + b.x, y + b.y); }
    // 两点是否重合
    bool operator == (const point& b) { return zero(x - b.x) && zero(y - b.y); }
    // 点积(以原点为基准)
    double operator * (const point& b) { return x * b.x + y * b.y; }
    // 叉积(以原点为基准)
    double operator ^ (const point& b) { return x * b.y - y * b.x; }
    // 绕P点逆时针旋转a弧度后的点
    point rotate(point b, double a)
    {
        double dx, dy;
        (*this - b).split(dx, dy);
        double tx = dx * cos(a) - dy * sin(a);
        double ty = dx * sin(a) - dy * cos(a);
        return point(tx, ty) + b;
    }
    // 点坐标分别赋值到a和b
    void split(double& a, double& b) {a = x, b = y; }
};

struct line
{
    point s, e;
    line() {}
    line(point _s, point _e) { s = _s, e = _e; }
};
double dist(point a, point b) { return sqrt((a - b) * (a - b)); }

bool segxseg(line l1,line l2)
{
	return
		max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
		max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
		max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
		max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
		sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
		sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}

struct door{
	double y1, y2;
};
const int N = 200, INF = 1E9;
#define P pair<double,int>

struct wall{
	double x;
	door d[2];
	line l[3];
}w[N];

vector<pair<int,double> > E[N];
vector<point> p[N];

void construct(vector<point> v, vector<line> block, int n)
{
	for(int i = 0; i < v.size(); ++i) {
		for(int j = i + 1; j < v.size(); ++j) {
			bool ok = 1;
			for(int k = 0; k < block.size(); ++k) {
				if(segxseg({v[i],v[j]}, block[k]) && (!(v[i] == block[k].s)) && (!(v[i] == block[k].e))
						&& (!(v[j] == block[k].s)) && (!(v[j] == block[k].e))) {
					ok = 0;
					break;
				}
			}
			if(ok)
			E[i].push_back(make_pair(j, dist(v[i],v[j])));
		}
	}
}

struct Dijkstra{
	priority_queue<P, vector<P>, greater<P> > pq;
	double dis[N];
	int n;

	void dijkstra(int s)
	{
		for(int i = 0; i <= n; ++i) {
			dis[i] = INF;
		}
		pq.push(P(dis[s] = 0, s));
		while(!pq.empty()) {
			P cur = pq.top(); pq.pop();
			int u = cur.second;
			if(dis[u] < cur.first) continue;
			for(int i = 0; i < E[u].size(); ++i) {
				int v = E[u][i].first;
				double w = E[u][i].second;
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push(P(dis[v], v));
				}
			}
		}
		//for(int i = 0; i <= n; ++i) {
		//	cout << i << ' ' << dis[i] << "\n";
		//}
	}
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;

	while(cin >> n && (~n)) {
		for(int i = 0; i < N; ++i) {
			E[i].clear();
		}
		int tot = 0;
		vector<point> v;;
		vector<line> block;
		v.push_back(point(0,5));
		for(int i = 0; i < n; ++i) {
			cin >> w[i].x;
			for(int j = 0; j < 2; ++j) {
				cin >> w[i].d[j].y1 >> w[i].d[j].y2;
				v.push_back({w[i].x, w[i].d[j].y1});
				v.push_back({w[i].x, w[i].d[j].y2});
				tot += 2;
			}
			line a,b,c;
			a = {{w[i].x,0},{w[i].x,w[i].d[0].y1}};
			b = {{w[i].x,w[i].d[0].y2},{w[i].x,w[i].d[1].y1}};
			c = {{w[i].x,w[i].d[1].y2},{w[i].x,10}};
			block.push_back(a);
			block.push_back(b);
			block.push_back(c);
		}
		v.push_back({10,5});
//		cout << "tot =" << tot + 2 << endl;
//		cout << "v.size() = " << v.size() << endl;
		construct(v, block, n);
/*		for(int i = 0; i < E->size(); ++i) {
			cout << E[i].size() << '\n';
			for(int j = 0; j < E[i].size(); ++j) {
				cout << i << "->" << E[i][j].first << ' ' << E[i][j].second <<  endl;
			}
		}
		cout << "end\n";*/
		Dijkstra solve;
		solve.n = v.size();
		solve.dijkstra(0);
		cout << fixed << setprecision(2) << solve.dis[solve.n - 1] << '\n';
	}
    return 0;
}
