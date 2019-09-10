/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月08日 星期日 08时40分33秒
 ************************************************************************/

#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const double EPS=1e-10;

//考虑误差的加法运算
double add(double a,double b)
{
    if(fabs(a+b)<EPS*(fabs(a)+fabs(b)))
        return 0;
    return a+b;
}

//二维向量结构体
struct P
{
    double x,y;

    //构造函数
    P(){}
    P(double x,double y):x(x),y(y){}

    //重载加法运算
    P operator + (P p)
    {
        return P(add(x,p.x),add(y,p.y));
    }

    //重载减法运算
    P operator - (P p)
    {
        return P(add(x,-p.x),add(y,-p.y));
    }

    //重载乘法运算
    P operator * (double d)
    {
        return P(x*d,y*d);
    }

    //向量内积
    double dot(P p)
    {
        return add(x*p.x,y*p.y);
    }

    //向量外积
    double det(P p)
    {
        return add(x*p.y,-y*p.x);
    }
}p[4];

//判断点q是否在线段p1-p2上
bool on_seg(P p1,P p2,P q)
{
    return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}

//计算直线p1-p2与直线q1-q2的交点，使用前需判断两条直线是否平行（(p1-q1).det(p2-q2)==0表示两条直线平行）
P intersection(P p1,P p2,P q1,P q2)
{
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
   // ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		for(int i = 0; i < 4; ++i) {
			cin >> p[i].x >> p[i].y;
		}
		if(p[0].x > p[1].x) {
			swap(p[0],p[1]);
		}
		if(p[2].x > p[3].x) {
			swap(p[2],p[3]);
		}
		P cross = intersection(p[0],p[1],p[2],p[3]);
		if((p[0] - p[1]).det(p[2] - p[3]) != 0 && on_seg(p[0],p[1],cross) && on_seg(p[2],p[3],cross)) {
			double dis = 0, h = 0, tdis,th;

			if(p[0].y < p[2].y) {
				swap(p[2],p[0]);
				swap(p[1],p[3]);
			}
			if(p[2].y <= p[0].y) {
				P t1,t2,c1,c2;
				if(p[1].y >= p[2].y) {
					t1 = P(p[1].x - 1,p[1].y);
					c1 = intersection(p[1],t1,p[2],p[3]);
					dis = fabs(p[1].x - c1.x);
				}else{
					t1 = P(p[2].x - 1,p[2].y);
					c1 = intersection(p[2],t1,p[0],p[1]);
					dis = fabs(p[2].x - c1.x);
				}
				if(p[0].y <= p[3].y) {
					t2 = P(p[0].x - 1,p[0].y);
					c2 = intersection(p[0],t2,p[2],p[3]);
					tdis = fabs(p[0].x - c2.x);
				}else{
					t2 = P(p[3].x - 1,p[3].y);
					c2 = intersection(p[3],t1,p[0],p[1]);
					tdis = fabs(p[3].x - c2.x);
				}
			//	dbg(c1.x,c1.y,c2.x,c2.y);
				h = fabs(max(p[1].y,p[2].y) - cross.y);
				th = fabs(cross.y - min(p[0].y,p[3].y));
			}
	//		dbg(dis,h, tdis,th);
			printf("%.2f\n",dis * h * 0.5 + tdis * th * 0.5);
		//	cout << setw(2) << 
		}else{
			printf("0.00\n");
		}
	}
    return 0;
}
