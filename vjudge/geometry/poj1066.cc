/*************************************************************************
    > File Name: poj1066.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月03日 星期日 12时39分12秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iomanip>
#include<queue>
#include<cassert>
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
    void split(double& a, double& b) { a = x, b = y; }
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

int AC(line l, const vector<line> &seg)
{
	int cnt = 0;
	for(int i = 0; i < seg.size(); ++i) {
		if(l.s == seg[i].s || l.s == seg[i].e) continue;
		if(segxseg(seg[i], l)) {
			cnt++;
		}
	}
	return cnt;
}

void solve(const vector<line> &seg, point treasure)
{
	int ans = 1E9;
	for(int i = 0; i < seg.size(); ++i) {
		line s = line(seg[i].s, treasure);
		line e = line(seg[i].e, treasure);
		ans = min(ans, min(AC(e,seg), AC(s,seg)));
	}
	if(!seg.size()) ans = 0;
	cout << "Number of doors = " << ans + 1 << '\n'; 
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	double a,b,c,d;
	vector<line> seg;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		seg.push_back(line(point(a,b),point(c,d)));
	}
	point treasure;
	cin >> a >> b;
	treasure = point(a,b);
	solve(seg, treasure);
    return 0;
}
