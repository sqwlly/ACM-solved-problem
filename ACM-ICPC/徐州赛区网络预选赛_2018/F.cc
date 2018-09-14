#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
struct feature
{
	int fx,fy;
	int lastframe;
	int countinueshow;
};
class featureSortCriterion {
    public:
    bool operator() (const feature &a, const feature &b) const 
	{
        if(a.fx < b.fx)
            return true;
        else if(a.fx == b.fx) {
            if(a.fy < b.fy)
				return true;
            else
				return false;
        }
		else
            return false;
	}
};

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int ans=0;
		int n;
		cin>>n;
		set<feature,featureSortCriterion> s;
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				int tempx,tempy;
				cin>>tempx>>tempy;
				feature ftemp;
				ftemp.fx=tempx;
				ftemp.fy=tempy;
				set<feature,featureSortCriterion>::iterator it;
				it=s.find(ftemp);
				if(it!=s.end())
				{
					ftemp=(*it);
					s.erase(it);
					if(ftemp.lastframe==i-1)
					{
						ftemp.countinueshow++;
						ftemp.lastframe=i;
						if(ftemp.countinueshow>ans)
							ans=ftemp.countinueshow;
						s.insert(ftemp);
					}
					else if(ftemp.lastframe==i)
					{
						s.insert(ftemp);
					}
					else
					{
						ftemp.countinueshow=1;
						ftemp.lastframe=i;
						if(ftemp.countinueshow>ans)
							ans=ftemp.countinueshow;
						s.insert(ftemp);
					}
				}
				else
				{
					ftemp.lastframe=i;
					ftemp.countinueshow=1;
					if(ftemp.countinueshow>ans)
						ans=ftemp.countinueshow;
					s.insert(ftemp);
				}
			}
		}
		cout<<ans<<endl;
	}
}
