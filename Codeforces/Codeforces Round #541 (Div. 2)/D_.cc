/* 
我的房间漂浮着不稳定的，大气呢，
一切都等待着等待着，晨昏交错你和我一样是无眠的，
世界不再是真实的，
每一个颠沛的自己，和每一段旅途中的你，
好不好啊，好不好啊，那就开始吧，那就开始吧，
每一个黄昏的谜语，和每一棵海草的气息，
好不好啊，好不好啊，那就静止吧，那就静止吧，
你会是那萤火虫的光，是荒野之魂的吟唱，
所有无法继续飞行的梦想，是我的，最真实的渴望，
再也没有什么能阻止着，故事继续发生。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2010;
//遇到有类似对应比较关系的问题记得图论
int pre[maxn], in[maxn], ans[maxn];
char s[maxn/2][maxn/2];
vector<int> fi[maxn];//邻接表建图
void init(int n)//初始化并查集
{
	for(int i = 0; i <= n; i++)
		pre[i] = i;
}
int finds(int x)//查找并查集
{
	return x == pre[x] ? x : pre[x] = finds(pre[x]);
}
void join(int x, int y)//并查集的合并
{
	int fx = finds(x), fy = finds(y);
	if(fx != fy)
		pre[fx] = fy;
}
void addedge(int u, int v)//加边
{
	fi[u].push_back(v);
	in[v]++;
}
bool topo(int n, int m)//拓扑排序
{
	queue<pair<int, int> > q;
	for(int i = 1; i <= n+m; i++) 
		if(in[i] == 0) 
			q.push(make_pair(i, 1));
	while(!q.empty())
	{
		pair<int, int> fir = q.front();
		q.pop();
		ans[fir.first] = fir.second;
		//cout << fir.second << endl;
		for(vector<int>::iterator it = fi[fir.first].begin(); it != fi[fir.first].end(); it++)
		{//cout << in[*it] << endl;
			if(--in[*it] == 0)//注意拓扑排序的原理，去掉一个点入度就要-1
				q.push(make_pair(*it, fir.second+1));
		}
	}
	for(int i = 1; i <= n+m; i++)
	{
		ans[i] = ans[finds(i)];
		if(ans[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, m; cin >> n >> m;
	init(n+m);
	for(int i = 1; i <= n; i++) scanf("%s", s[i]+1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '=')
				join(i, n+j);//并查集缩点
	//for(int i = 1; i <= n+m; i++) cout << pre[i] << endl;
	bool flag = true;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
		if(s[i][j] == '<')
			if(finds(i) != finds(n+j)) addedge(finds(i), finds(n+j));//添加一条有向边
				else flag = false;//环 false
		else if(s[i][j] == '>')
			if(finds(i) != finds(n+j)) addedge(finds(n+j), finds(i));
				else flag = false;
	//for(int i = 1; i <= n+m; i++) cout << in[i] << endl;
	if(flag == false) cout << "No" << '\n';
	else if(!topo(n, m)) cout << "No" << '\n';
	else
	{
		cout << "Yes" << '\n';
		for(int i = 1; i <= n; i++) 
			cout << ans[i] << " ";
		cout << '\n';
		for(int i = n+1; i <= n+m; i++)
			cout << ans[i] << " ";
	}
	//system("pause");
	return 0;
}
