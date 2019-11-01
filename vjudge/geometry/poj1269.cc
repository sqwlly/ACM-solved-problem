/*************************************************************************
    > File Name: poj1269.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月01日 星期五 13时55分15秒
 ************************************************************************/
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
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

// <0, *> 表示重合; <1, *> 表示平行; <2, P> 表示交点是P
pair<int, point> spoint(line l1,line l2)
{
	point ret = l1.s;
	if(sgn((l1.s - l1.e) ^ (l2.s - l2.e)) == 0)
		return {sgn((l1.s - l2.e) ^ (l2.s - l2.e)) != 0, ret};
	double t = ((l1.s - l2.s) ^ (l2.s - l2.e)) / ((l1.s - l1.e) ^ (l2.s - l2.e));
	ret.x += (l1.e.x - l1.s.x) * t;
	ret.y += (l1.e.y - l1.s.y) * t;
	return {2, ret};
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	line lines[20][2];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			cin >> lines[i][j].s.x >> lines[i][j].s.y >> lines[i][j].e.x >> lines[i][j].e.y;
		}
	}
	cout << "INTERSECTING LINES OUTPUT\n";
	cout << fixed << setprecision(2);
	for(int i = 0; i < n; ++i) {
		pair<int, point> ret = spoint(lines[i][0], lines[i][1]);
		if(ret.first == 0) {
			cout << "LINE" << '\n';
		}else if(ret.first == 1) {
			cout << "NONE" << '\n';
		}else{
			cout << "POINT " << ret.second.x << ' ' << ret.second.y << '\n';
		}
	}
	cout << "END OF OUTPUT\n";
    return 0;
}
