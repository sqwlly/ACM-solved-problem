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

//l1是直线，l2是线段
bool segxline(line l1, line l2)
{
    return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}

void solve(const vector<line> &v,int n)
{
    for(int i = 0; i < v.size(); ++i) {
        for(int j = i + 1; j < v.size(); ++j) {
            if(i == j) continue;
            bool ok = 1;
            line t[] = {{v[i].s, v[j].s}, {v[i].s, v[j].e}, {v[i].e, v[j].s}, {v[i].e, v[j].e}};
            for(int c = 0; c < 4; ++c) {
                if(dist(t[c].s, t[c].e) < eps) continue;
                for(int k = 0; k < n; ++k) {
                    if(segxline(t[c], v[k])) {
                        ok = 1;
                    }else{
                        ok = 0;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok) { cout << "Yes!\n"; return; }
        }
    }
    cout << "No!\n";
}

int main()
{
    int T,n;
    freopen("input.in", "r", stdin);
    cin >> T;
    while(T--) {
        vector<line> lines;
        cin >> n;
        double a, b, c, d;
        for(int i = 0; i < n; ++i) {
            cin >> a >> b >> c >> d;
            lines.push_back({{a,b},{c,d}});
        }
        if(n == 1 || n == 2) {
            cout << "Yes\n";
            continue;
        }
        solve(lines, n);
    }
    return 0;
}