 //主要考察快速幂。
#include<stdio.h>
int t,a,x,m,n;
long long modexp(long long mod, long long x, int b)
{
    long long res=a;
    while(b>0)
    {
        if(b&1)
            res=res*x%mod;
        b=b>>1;
        x=x*x%mod;
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        getchar();
        scanf("%d%d%d%d",&a,&x,&m,&n);
        printf("%d\n",modexp(m, x, n -1));
    }
}
