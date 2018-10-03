#include<iostream>
#include <queue>
using namespace std;
int dir[8][2] = {
    {1,2},{1,-2},{-1,2},{-1,-2},
    {2,1},{2,-1},{-2,1},{-2,-1}
};
int n, m;
int maze[1100][1100];
bool vis[1100][1100];
struct Point {
    int x, y, step;
    Point(int _x, int _y, int _step) :
        x(_x), y(_y), step(_step) {}
};
void bfs(int sx, int sy)
{
    queue<Point>q;
    q.push(Point(sx, sy, 0));
    vis[sx][sy] = 1;
    maze[sx][sy] = 0;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        maze[x][y] = step;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (!vis[tx][ty]&&tx<61&&ty<61&&tx>=0&&ty>=0)
            {
                q.push(Point(tx, ty, step + 1));
                vis[tx][ty] = 1;
            }
        }
    }
}
int main() {
    //freopen("1.txt", "w", stdout);
    bfs(30, 30);
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j <60; j++) {
			printf("%3d",maze[i][j]);
            //cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

