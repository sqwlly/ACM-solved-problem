#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
int n , rem = 60;

bool ask1(int mid){
    cout << "> " << mid << endl;
    rem--;
    int ret;
    cin >> ret;
    return ret;
}

int ask2(int i){
    cout << "? " << i << endl;
    int ret;
    cin >> ret;
    return ret;
}

void finish(int x , int d){
    cout << "! " << x << ' ' << d << endl;
}

int getMax(){
    int l = 0 , r = 1e9 , ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(ask1(mid))l = mid + 1;
        else ans = mid , r = mid - 1;
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n;
    int mx = getMax();
    vector<int> a , per;
    for(int i = 0 ; i < n ; ++i)per.pb(i);

    shuffle(all(per) , rng);

    for(int i = 0 ; i < min((int)per.size() , rem) ; ++i){
        int v = ask2(per[i] + 1);
        a.pb(v);
    }

    int d = 0;
    for(int i = 0 ; i < (int)a.size() ; ++i){
        for(int j = i + 1 ; j < (int)a.size() ; ++j){
            d = __gcd(d , abs(a[i] - a[j]));
        }
    }

    int x1 = mx - d * (n - 1);
    finish(x1 , d);
}
