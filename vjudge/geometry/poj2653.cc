/*************************************************************************
    > File Name: poj2653.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月02日 星期六 13时44分46秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
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
const int N = 1E5+10;
void solve(const vector<line> &seg)
{
	//int N = seg.size();
	bool down[N];
	for(int i = 0; i < seg.size(); ++i) {
		down[i] = 0;
		for(int j = i + 1; j < seg.size(); ++j) {
			if(segxseg(seg[i],seg[j])) {
				down[i] = 1;
				break;
			}
		}
	}
//	printf("Top sticks: ");
	cout << "Top sticks: ";
	vector<int> ans;
	for(int i = 0; i < seg.size(); ++i) {
		if(!down[i]) {
			ans.push_back(i + 1);
		}
	}
	for(int i = 0; i < ans.size(); ++i) {
	/*	printf("%d", ans[i]);
		if(i == ans.size() - 1) {
			printf(".\n");
		}else{
			printf(", ");
		}*/
		cout << ans[i] << (i == ans.size() - 1 ? ".\n" : ", ");
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	while(cin >> n && n) {
//	while(scanf("%d",&n) && n) {
		vector<line> seg;
		point a,b;
		for(int i = 0; i < n; ++i) {
	//		scanf("%lf %lf %lf %lf",&a.x, &a.y, &b.x, &b.y);
				cin >> a.x >> a.y >> b.x >> b.y;
			seg.push_back(line(a,b));
		}
		solve(seg);
	}
	return 0;
}
