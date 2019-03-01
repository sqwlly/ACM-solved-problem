#include<bits/stdc++.h>
using namespace std;
double Pow(double x){ return x*x; }
double san(double x){ return x*x*x; }
const double PI = acos(-1);

struct node {
    double x, y, z, r;

    void get() { scanf("%lf%lf%lf%lf", &x, &y, &z, &r); }

    double dis(node a) {
        return sqrt(Pow(x - a.x) + Pow(y - a.y) + Pow(z - a.z));
    }

    double get_aera(node a) {
        double d = dis(a);
        double x1 = (a.r * a.r - r * r + d * d) / 2 / d;
        double x2 = d - x1;
        double h1 = r - x2;
        double h2 = a.r - x1;
        return PI / 3 * (3 * r - h1) * h1 * h1
               + PI / 3 * (3 * a.r - h2) * h2 * h2;
    }
}a[2];
int main() {
    a[0].get();
    a[1].get();
    double ans = 0;
    double p = 4.0 / 3 * PI * san(a[1].r), q = 4.0 / 3 * PI * san(a[0].r);
    if (a[0].dis(a[1]) <= fabs(a[0].r - a[1].r)) {
        ans = max(p, q);
    } else if (a[0].dis(a[1]) >= a[0].r + a[1].r) {
        ans = p + q;
    } else {
        ans = p + q - a[0].get_aera(a[1]);
    }
    printf("%.7f\n", ans);
}


