/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月06日 星期三 20时34分11秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
//1 5 3 2 4
//0 1 0 0 1
//1 3 2 5 4
//0 0 0 1 1
#define L tr[rt].l
#define R tr[rt].r
const int N = 2E5+10;
struct data{
	int l,r,Inc,nSum;
} tr[N << 2];

void pushup(int rt)
{
	tree[rt].nSum = tr[rt << 1].nSum + tr[rt << 1 | 1].nSum;
}

void pushdown(int rt)
{
	if(tr[rt].Inc) {
		int m = (L + R) / 2;
		tr[rt << 1].Inc += tr[rt].Inc;
		tr[rt << 1 | 1].Inc += tr[rt].Inc;
		tr[rt << 1].nSum += tr[rt].Inc * (m - L + 1);
		tr[rt << 1 | 1].nSum += tr[rt].Inc * (R - mid);
		tr[rt].Inc = 0;
	}
}

void build(int rt,int x,int y)
{

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif

    return 0;
}
