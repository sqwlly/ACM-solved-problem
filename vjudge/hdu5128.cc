/*************************************************************************
    > File Name: hdu5128.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月11日 星期四 19时26分02秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct Point{
	int x,y;
	Point() {}
	Point(int _x,int _y) { x = _x, y = _y; }
	bool operator < (const Point & u)const{
		if(x == u.x) return y < u.y;
		return x < u.x;
	}
};

struct rectangle{
	Point p1,p2;
	int area;
};

bool vis[301][301];

int ok(rectangle a, rectangle b)
{
	if(a.p2.x < b.p1.x || a.p2.y < b.p1.y)
		return 1;
	if(b.p2.x < a.p1.x || b.p2.y < a.p1.y)
		return 1;
	if(a.p1.x < b.p1.x && a.p1.y < b.p1.y && a.p2.x > b.p2.x && a.p2.y > b.p2.y)
		return 2;
	if(b.p1.x < a.p1.x && b.p1.y < a.p1.y && b.p2.x > a.p2.x && b.p2.y > a.p2.y)
		return 3;
	return 0;
		
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	while(cin>>n && n){
		vector<Point> point;
		int x,y;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; ++i){
			cin>>x>>y;
			vis[x][y] = 1;
			point.push_back(Point{x,y});
		}
		sort(point.begin(), point.end());
		vector<rectangle> rec;
		for(int i = 0; i < point.size(); ++i){
			for(int j = i + 1; j < point.size(); ++j){
				int px = point[j].x, py = point[i].y;
				if(px > point[i].x && point[j].y > py && vis[px][py] && vis[point[i].x][point[j].y]){
					Point t1 = {point[i].x, point[i].y};
					Point t2 = {point[j].x, point[j].y};
					int area = (point[j].x - point[i].x) * (point[j].y - point[i].y);
					rec.push_back(rectangle{t1,t2,area});
				}
			}
		}
		int ans = -1;
		for(int i = 0; i < rec.size(); ++i){
			for(int j = i + 1; j < rec.size(); ++j){
				if(ok(rec[i],rec[j]) == 1)
					ans = max(ans, rec[i].area + rec[j].area);
				else if(ok(rec[i],rec[j]) == 2)
					ans = max(ans, rec[i].area);
				else if(ok(rec[i],rec[j]) == 3) 
					ans = max(ans, rec[j].area);
			}	
		}
		if(~ans) cout<<ans<<endl;
		else cout<<"imp"<<endl;
	}
    return 0;
}
