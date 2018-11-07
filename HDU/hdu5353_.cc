#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
struct Node {
    int a, b;
    Node(int a, int b) : a(a), b(b) {}
};

vector<Node> ans;
int n;
ll sum;
int A[N], a[N];

bool run(int dir, int st) {
    ans.clear();
    memcpy(a, A, sizeof(A));

    int flag = 0;
    int u, v;
    if(a[st] == 2) {
        u = st; v = (st - dir + n) % n;
        a[u]--, a[v]++;
        ans.pb(Node(u, v));
        flag = 1;
    }

    for(int i = 0; i < n - flag; i++) {
        u = (st + i*dir + n) % n;
        v = (st + (i+1)*dir + n) % n;

        if(a[u] > 0) {
            a[u]--, a[v]++;
            ans.pb(Node(u, v));
        }else if(a[u] < 0) {
            a[u]++, a[v]--;
            ans.pb(Node(v, u));
        }
        if(abs(a[v]) >= 2) return false;
    }

    for(int i = 0; i < n; i++) {
        if(a[i]) return false;
    }

    return true;
}

bool solve() {
    sum /= n;
    for(int i = 0; i < n; i++) A[i] -= sum;
    for(int i = 0; i < n; i++)
        if(abs(A[i]) > 2)
            return false;
    if(n == 2 && abs(A[0]) >= 2) {
        return false;
    }
    for(int i = 0; i < n; i++) {
        if(A[i] > 0) {
            if(run(-1, i)) return true;
            if(run(1, i)) return true;
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        ans.clear();
        sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }
        if(sum % n != 0) {
            puts("NO");
            continue;
        }
        if(!solve()) {
            puts("NO");
        }else {
            puts("YES");
            printf("%d\n", (int)ans.size());
            for(int i = 0; i < ans.size(); i++)
                printf("%d %d\n", ans[i].a+1, ans[i].b+1);
        }
    }
    return 0;
}
