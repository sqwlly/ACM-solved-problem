#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define mp make_pair
#define pii pair<int, int>
#define s second
#define f first
#define ld long double
#define pb push_back
#define ll long long

bool comparer(pii a, pii b)
{
    if(a.f < b.f)
        return true;
    else if (a.f > b.f)
        return false;

    return a.s > b.s;
}

bool comparer2(vector<int> a, vector<int> b)
{
    //cout << a.size() << " " << b.size() << endl;
    return b.size() < a.size();
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); cerr.tie(0);


    int n, m;
    cin >> n >> m;
    vector<pii > people;
    vector<vector<int> > a;

    for(int i = 0; i < n; i++)
    {
        pii x;
        cin >> x.f >> x.s;
        people.pb(x);
    }

    sort(people.begin(), people.end(), comparer);

    ll ind = -1;
    ll prev = -1;
    for(ll i = 0; i < people.size(); i++)
    {
        pii cur = people[i];
        if(cur.f != prev)
        {
            prev = cur.f;
            ind++;
            a.pb({});
        }

        a[ind].pb(cur.s);

        if(a[ind].size() >= 2)
        {
            //cout << a[ind][a.size() - 1] << " " << a[ind][a.size() - 2] << " " << a.size() << endl;
           a[ind][a[ind].size() - 1] += a[ind][a[ind].size() - 2];
        }
    }

    if(a.size() > 1)
        sort(a.begin(), a.end(), comparer2);
    //cout << "hey";

    ll mxSum = 0;
    for(int j = 1; j <= n; j++)
    {
        ll curSum = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i].size() >= j && a[i][j - 1] > 0)
                curSum += a[i][j - 1];
            if(a[i].size() < j)
                break;
        }
        mxSum = max(mxSum, curSum);
    }
    cout << mxSum << endl;
    return  0;
}

