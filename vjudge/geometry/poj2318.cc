#include<iostream>
#include<cmath>

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

bool isLeft(line x, point y)
{
    return ((x.e - x.s) ^ (y - x.s)) > 0;
}
const int N = 5010;
point p[N], L, R;
line seg[N];
int ret[N];

int solve(point p,int n)
{
    int l = 0, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(isLeft(seg[mid],p)) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    if(isLeft(seg[l], p)) l++;
    return l;
}

int main()
{
    int n, m;
  //  freopen("input.in", "r", stdin);
    while(cin >> n && n) {
        cin >> m >> L.x >> L.y >> R.x >> R.y;
        int c,d;
        for(int i = 0; i <= n + 1; ++i) ret[i] = 0;
        for(int i = 0; i < n; ++i) {
            cin >> c >> d;
            seg[i] = {point(c, L.y), point(d, R.y)};
        }
        for(int i = 0; i < m; ++i) {
            cin >> c >> d;
            ret[solve({c * 1.0, d * 1.0}, n - 1)]++; 
        }
        for(int i = 0; i <= n; ++i) {
            cout << i << ": " << ret[i] << "\n";
        }
        cout << '\n';
    }   
    return 0;
}