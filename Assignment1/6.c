#include <stdio.h>
int main()
{
    int n,m,a,b;
        scanf("%d",&n);
        scanf("%d",&m);
    int folder[n];
    for(int i=0;i<n;i++)
        folder[i]=0;
    folder[0]=1;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            if(folder[a]==1)
                folder[b]=1;
         }
    for(int i=0;i<n;i++)
    {
        if(folder[i]==1)
        printf("%d ",i);
    }        
    return 0;
}