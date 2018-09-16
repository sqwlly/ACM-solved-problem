#include<iostream>
#include<cstdio>
#include<cstring>
#include<iterator>
using namespace std;
struct ins
{
	string op;
	int v;
	int k;
}INS[10007];

int V[10002][257];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		ins tempins;
		for(int i=1;i<=n;i++)
		{
			memset(V[i],0,sizeof(V[i]));
			cin>>tempins.op;
			if(tempins.op=="add")
				cin>>tempins.v;
			else
				cin>>tempins.v>>tempins.k;
			INS[i]=tempins;
		}
		int reg=0;
		int p=1;
		bool flg=1;
		while(p<=n)
		{
			if(V[p][reg]==0)
			{
				V[p][reg]=1;
			}
			else
			{
				flg=0;break;
			}
			tempins=INS[p];
			if(tempins.op=="add")
			{
				reg=(reg+tempins.v)%256;
				p++;
				continue;
			}
			else
			{
				if(tempins.op=="beq")
				{
					if(tempins.v==reg)
					{p=tempins.k;continue;}
					else
					{p++;continue;}
				}
				if(tempins.op=="bne")
					if(tempins.v!=reg)
						{p=tempins.k;continue;}
					else
						{p++;continue;}
				}
				if(tempins.op=="blt")
				{
					if(tempins.v>reg)
						{p=tempins.k;continue;}
					else
						{p++;continue;}
				}
				if(tempins.op=="bgt")
				{
					if(tempins.v<reg)
						{p=tempins.k;continue;}
					else
						{p++;continue;}
				}
			}
		}
		if(flg)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

}
