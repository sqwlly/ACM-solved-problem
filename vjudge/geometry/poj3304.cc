#include<iostream>
#include<cmath>
#include<vector>
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
double xmult(point p0,point p1,point p2) //p0p1 X p0p2
{
    return (p1-p0)^(p2-p0);
}
bool Seg_inter_line(line l1,line l2) //判断直线l1和线段l2是否相交
{
    return sgn(xmult(l2.s,l1.s,l1.e))*sgn(xmult(l2.e,l1.s,l1.e)) <= 0;
}
//l1是直线，l2是线段
bool segxline(line l1, line l2)
{
    return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}

bool check(const vector<line> &v, line c)
{
    if(sgn(dist(c.s,c.e)) == 0) return 0;
    for(int i = 0; i < v.size(); ++i) {
        if(!Seg_inter_line(c, v[i])) return 0; 
    }
    return 1;
}

bool solve(const vector<line> &lines)
{
    for(int i = 0; i < lines.size(); ++i) {
        for(int j = 0; j < lines.size(); ++j) {
            if(check(lines,{lines[i].s,lines[j].s}) || check(lines,{lines[i].s,lines[j].e}) || check(lines,{lines[i].e,lines[j].s}) || check(lines,{lines[i].e,lines[j].e})) {
                return 1;
            }
            /*vector<line> v = {line(lines[i].s, lines[j].s),line(lines[i].s, lines[j].e),line(lines[i].e, lines[j].s),line(lines[i].e, lines[j].e)};
            for(int c = 0; c < v.size(); ++c) {
                if(check(lines, v[c])) {
                    return 1;
                }
            }*/
        }
    }
    return 0;
}

int main()
{
    int T,n;
    freopen("input.in", "r", stdin);
    cin >> T;
    while(T--) {
        cin >> n;
        vector<line> lines;
        double a,b,c,d;
        for(int i = 0; i < n; ++i) {
            cin >> a >> b >> c >> d;
            lines.push_back({(a,b),(c,d)});
        }
        cout << (solve(lines) ? "Yes" : "No") << '\n';
        lines.clear();
    }
    return 0;
}