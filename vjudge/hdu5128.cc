/*************************************************************************
    > File Name: hdu5128.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月11日 星期四 19时26分02秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int sgn(double x)
{
	if(fabs(x) < 1e-8) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point{
	double x,y;
	Point() {}
	Point(double _x,double _y) { x = _x, y = _y; }
	void input() { cin>>x>>y; }
	Point operator - (const Point &b)const{
		return Point(x - b.x,y - b.y); 
	}

	double operator ^ (const Point &b)const{
		return x * b.y - y * b.x;
	}
};

struct Line{
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) { s = _s; e = _e; }
	
	int lineCrossSeg(Line v){ //不相交
		int d1 = sgn((e - s) ^ (v.s - s));
		int d2 = sgn((e - s) ^ (v.e - s));
		if((d1 ^ d2) == -2) return 2;
		return (d1 == 0 || d2 == 0);
	}

	int relation(Point p){
		int c = sgn((p -s) ^ (e - s));
		if(c < 0) return 1;
		else if(c > 0) return 2;
		else return 3;
	}

	bool parallel(Line v) {
		return sgn((e - s) ^ (v.e - v.s)) == 0;
	}

	// 0 parallel 1 重合 2 相交
	int lineCrossLine(Line v) {
		if((*this).parallel(v))
			return v.relation(s) == 3;
		return 2;
	}
};

struct rectangle{
	Line a, b, c, d;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	while(cin>>n && n){
		vector<Point> point;
		int x,y;
		for(int i = 0; i < n; ++i){
			cin>>x>>y;
			point.push_back(Point{x,y});
		}
		vector<Line> line;
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				Line t = Line{point[i], point[j]};
				line.push_back(t);
			}
		}
		for(int i = 0; i < line.size(); ++i){
			for(int j = i + 1; j < line.size(); ++j){
				if()
			}
		}
	}
    return 0;
}
