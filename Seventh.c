#include <stdio.h>
int arr[100][100] = {0};
int in[100]={0};
int vis[100] = {0};
int n,m;

int topo()
{
    int flag = 0;
    int count = 0;
    for(int i=0; i<n;i++)
    {
        if(vis[i] == 0 && in[i] == 0)
        {
            vis[i] = 1;
            for(int j=0;j<26;j++)
            {
                if(arr[i][j] >0)
                {
                    in[j]--;
                }
                
            }
            topo();
            vis[i] = 0;
            for(int j=0;j<26;j++)
            {
                if(arr[i][j] >0)
                {
                    in[j]++;
                }
                
            }
            flag = 1;

        }
        if(flag == 1)
            {
                count++;
            }
 
    }
    return count;
    
}

int main()
{
 
    int a,b;
    scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
            in[b]++;
    }
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        if(in[i] == 0)
            flag = 1;
    }
    int counter;
    if(flag == 1)
        counter = topo();
    else
        counter = -1;
        
    printf("%d\n",counter);
}
// 5 7
// 0 1
// 0 2
// 0 3
// 0 4
// 1 3
// 1 4
// 2 4

