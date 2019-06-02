#include <stdio.h>
int n;
int arr[26][26] = {0};
int in[26]={0};
int vis[26] = {0};

void topo()
{
    for(int i=0; i<26;i++)
    {
        if(vis[i] == 0 && in[i] == 0)
        {
            printf("%c ",i+97);
            vis[i] = 1;
            for(int j=0;j<26;j++)
            {
                if(arr[i][j] >0)
                {
                    in[j]--;
                    topo();
                }
                
            }
        }
    }
}
int main() {
    
    scanf("%d", &n);
    char str[3];
    int a,b;
    for(int i=0;i<26;i++)
    {
        in[i] = -1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        a = str[0] - 97;
        scanf("%s",str);
        b = str[0] - 97;
        arr[a][b] = 1;
        if( in[a] == -1)
            in[a] = 0;
        if(in[b] == -1 | in[b] == 0)
            in[b] = 1;
        else if(in[b] > 0)
            in[b]++;
    }
    int flag = 0;
    for(int i=0;i<26;i++)
    {
        if(in[i] == 0)
            flag = 1;
    }
    if(flag == 0)
        printf("-1");
    else
        topo();
    
    
    return 0;
}
