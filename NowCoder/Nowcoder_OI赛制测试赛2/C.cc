#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
        int n,a[10001]={0};
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
                scanf("%d", a+i);
        }
        std::vector<int> v;
        for(int i = 0, f = 0; i < n; ++i,f = 0) {
                for(int j = i + 1; j < n; ++j) {
                        if(a[j] > a[i]) {
								f = 1;
                                v.push_back(j+1);
                                break;
                        }
                }
				if(f==0)
					v.push_back(0);
        }
        for(int i = 0; i < v.size(); ++i) {
                printf("%d%c", v[i], (i==v.size()-1) ? '\n' : ' ');
        }
        return 0;
}
