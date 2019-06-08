#include <stdio.h>
 
int main()
{
    int n;
    int temp[1001]={0};
    scanf("%d",&n);
    int a[1001]={0};
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
 
    int u;
    scanf("%d",&u);
    int b[1001]={0};
    for(int i=0;i<u;i++)
    {
        scanf("%d",&b[i]);
        temp[b[i]]=1;
    }
 
    int t;
    scanf("%d",&t);
    int c[1001]={0};
    for(int i=0;i<t;i++)
    {
        scanf("%d",&c[i]);
        if(temp[c[i]]!=1)
        temp[c[i]]=2;
    }
 
    int extra[1001]={0};
    int cnt=0;
    for(int i=0;i<1001;i++)
    {
        if(temp[i]==2)
        {
            extra[cnt]=i;
            cnt++;
        }
    }
 
    int size=1<<u;
    for(int i=0;i<size;i++)
    {
        for(int k=0;k<u;k++)
        {
            if(i & (1<<k))
            printf("%d ",b[k]);
        }
        for(int j=0;j<cnt;j++)
        printf("%d ",extra[j]);
        printf("\n");
    }
    return 0;
}
