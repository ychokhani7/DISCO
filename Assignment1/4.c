#include <stdio.h>
 
    int getMostWork(int folder[],int worker,int n)
    {
        int lw =0;
        int hi = 0;
        for(int i=0;i<n;i++)
        {
            if(lw<folder[i])
                lw=folder[i];
            hi+=folder[i];
        }
        int mid_load;
        int req_workers=1;
        int cur_load;
        if(worker==1)
        return hi;
        while(lw<hi)
        {
            mid_load = (lw+hi)/2;
            cur_load=0;
            req_workers=1;
            for(int i=0;i<n;i++)
            {
                if(cur_load+folder[i]<=mid_load)
                {
                    cur_load += folder[i];
                }
                else
                {
                    cur_load=folder[i];
                    req_workers += 1;
                }
            }
            if(req_workers<=worker)
            hi = mid_load;
            else if(req_workers>worker)
            lw=mid_load+1;
        }
        return hi;
    }
int main()
{
    int a,workers,n;
        scanf("%d",&workers);
        scanf("%d",&n);
    int folder[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            folder[i]=a;
         }
        printf("%d",getMostWork(folder,workers,n));
    return 0;
}