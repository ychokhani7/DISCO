#include <stdio.h>
int main()
{
 int n,m;
 scanf("%d",&n);
    int a,b;
    int k[1440];
    for(int i=0;i<1440;i++)
        k[i]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        k[a]+=1;
        k[b+1]-=1;
    }
    int max=k[0];
    for(int i=1;i<1440;i++)
    {
        k[i]+=k[i-1];
        if(k[i]>max)
            max=k[i];
    }
    printf("%d",max);
    return 0;
}