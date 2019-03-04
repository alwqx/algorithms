#include <stdio.h>
using namespace std;

const int maxn = 1010;
int num[maxn];
int sum=0,n,ipos=0;
int num_col = 0;

void dfs(int x)
{
    if(sum>n)
    return;
    else if(sum==n)
    {
        num_col++;
        printf("%d=%d",n,num[0]);
        for(int i=1;i<ipos;i++)
            printf("+%d",num[i]);
        if(num_col%4==0||ipos==1)
            printf("\n");
        else printf(";");
    }
    else if(sum<n)
    {
        for(int i=x;i<=n;i++)
        {
            sum+=i;
            num[ipos++] = i;
            dfs(i);
            sum-=i;
            ipos--;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}