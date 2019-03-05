#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long int LL;

LL a, n, cnt;
LL b[200005];

int main()
{
	scanf("%lld %lld",&a,&n);
    LL i, cot, x;
	cnt=200000;
	cot=cnt;
	x=0;

	for(i=n; i>=1; i--)
	{
		b[cnt]=(a*i+x)%10;
		x=(a*i+x)/10;
		cnt--;
	}

	int tag=1;
	if(x!=0)
	{
		printf("%lld",x);
		tag=0;
	}
	
	for(LL i=cnt+1;i<=cot;i++)
	{
		printf("%lld",b[i]);
		tag=0;
	}
	if(tag) printf("0");

	return 0;
}