#include <math.h>
#include <stdio.h>

int lattice(int n)
{
    int b=n;
    int a[b],j=0;
    for(int i=0;i<b;i++)
        a[i]=0;
    int pro=1,ans=0;
    while(n%2==0)
    {
        a[j]++;
        n=n/2;
    }
    j++;
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        while(n%i==0)
        {
            a[j]++;
            n=n/i;
        }
        j++;
    }
    if(n>2)
        a[j]++;
    for(int i=0;i<=j;i++)
    {
        a[i]++;
        pro=pro*a[i];
    }
    for(int i=0;i<=j;i++)
    {
        if(a[i]>1)
        ans=ans+(pro*(a[i]-1))/a[i];
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",lattice(n));
}
