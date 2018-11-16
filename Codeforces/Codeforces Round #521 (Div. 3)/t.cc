#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("data.in","r",stdin);

    int n, i, sum = 0, x;
    vector< int > v, p;
    vector< int > :: iterator it, it2;
    cin >> n;
    for(i = 0; i < n; i++)
    {

        cin >> x;
        v.push_back(x);
        sum += x;
		if(sum < 0) {
			cout<<sum<<endl;
		}
    }
    it = max_element(v.begin(), v.end());
    x = *it;
    *it = 0;
    it2 = max_element(v.begin(), v.end());
    *it = x;
    for(i = 0; i < n; i++)
    {

        int mx, sm;
        sm = sum;
        if(v[i] == *it)
        {
            sm = sum - v[i] - *it2;
            if(sm == *it2) p.push_back(i + 1);
        }
        else
        {
            sm = sum - v[i] - *it;
            if(sm == *it) p.push_back(i + 1);
        }
    }
    if(p.size() == 0) cout << "0" << endl;
    else
    {

        cout << p.size() << endl;
        for(it = p.begin(); it != p.end(); it++) cout << *it << " ";
        cout << endl;
    }
    return 0;
}
