#include <stdio.h>
int main()
{
    int n;
    int a[100];
    char temp;
    for(int i=0;i<100;i++)
    a[i]=i;
    int count=0;
    scanf("%d", &n);
    for(int s=0;s<n;s++)
        {
            int m;
            scanf("%d",&m);
            int b[2*m];
            if(count<2*m)
            {
                count=2*m;
            }
            for(int i=0;i<2*m;i++)
            {   scanf("%d",&b[i]);
                
            } 
            char sign;
            scanf(" %c",&sign);
            if(sign=='=')
            {
                for(int i=0;i<2*m;i++)
                {   int z=b[i];
                    a[z]=-1;
                   }
            }
        }    
     int c[count];
    for(int i=0;i<count;i++)
    {
        c[i]=0;
    }
            
    int inc=0;
    for(int i=0;i<count;i++)
    {
        if(a[i+1]!=-1)
        c[inc++]=a[i+1];
    }
            
    if(c[1]!=0)
    {
        printf("-1");
    }
    else
    {
        for(int i=1;i<=count;i++)
        {
            if(a[i]!=-1)
                {
                    printf("%d",a[i]);
                    
                }
        }
    }       
return 0;
}