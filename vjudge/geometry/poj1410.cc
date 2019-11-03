/*************************************************************************
    > File Name: poj1410.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月03日 星期日 16时02分42秒
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

bool PointOnSeg(point p,line l)
{
	return 
		sgn((l.s - p) ^ (l.e - p)) == 0 && 
		sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0 &&
		sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
}

double area(vector<point> p)
{
	double ret = 0;
	int n = p.size();
	for(int i = 0; i < n; ++i) ret += (p[i] ^ p[(i + 1) % n]) / 2;
	return fabs(ret);
}

// 点形成一个凸包，而且按逆时针排序(如是顺时针把里面的<0改为>0)
// 点的编号 ：[0,n)
// -1 ：点在凸多边形外
// 0  ：点在凸多边形边界上
// 1  ：点在凸多边形内
int PointIntConvex(point a,vector<point> p)
{
	int n = p.size();
	for(int i = 0; i < n; ++i) 
		if(sgn((p[i] - a) ^ (p[(i + 1) % n] - a)) < 0)
			return -1;
		else if(PointOnSeg(a, line(p[i], p[(i + 1) % n])))
			return 0;
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	line seg;
	point a,b;
	for(int i = 0; i < n; ++i) {
		vector<point> vtx;
		vector<line> rec;
		cin >> seg.s.x >> seg.s.y >> seg.e.x >> seg.e.y;
		cin >> a.x >> a.y >> b.x >> b.y;
		if(a.x > b.x) swap(a.x, b.x);
		if(a.y < b.y) swap(a.y, b.y);
		rec.push_back(line(a,point(a.x,b.y)));
		rec.push_back(line(a,point(b.x,a.y)));
		rec.push_back(line(b,point(b.x,a.y)));
		rec.push_back(line(b,point(a.x,b.y)));
		vtx.push_back(a); vtx.push_back(point(a.x, b.y));
		vtx.push_back(b); vtx.push_back(point(b.x, a.y));
		bool ok = 0;
		for(int j = 0; j < 4; ++j) {
			if(segxseg(rec[j], seg)) {
				ok = 1;
			}
		}
		if(PointIntConvex(seg.s,vtx) > -1 || PointIntConvex(seg.e,vtx) > -1) ok = 1;
		cout << (ok ? "T" : "F") << '\n';
	}
    return 0;
}
