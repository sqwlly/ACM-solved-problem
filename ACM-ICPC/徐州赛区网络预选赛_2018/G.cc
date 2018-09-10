#include <bits/stdc++.h>
typedef long long LL;
int n,x,y;
LL love(std::vector<int> fuck)
{
        std::set<int> s;
        LL ret = 0;
        for(int i = n-1; i >= 0; --i) {
                std::set<int>::iterator iter = s.lower_bound(fuck[i]);
                if(iter == s.begin())
                        ret += fuck[i];
                else
                        iter--,ret += fuck[i] - *iter;
                s.insert(fuck[i]);
        }
        return ret;
}


int main(int argc, char const *argv[]) {
        scanf("%d", &n);
        std::vector<int> s,b;
        for(int i = 0; i < n; ++i) {
                scanf("%d%d",&x,&y);
                s.push_back(x);
                b.push_back(y);
        }
        printf("%lld\n", love(s)+love(b));
        return 0;
}
