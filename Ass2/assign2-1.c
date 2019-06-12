#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int adj[n][n];
	int con[n];
	for(int i=0;i<n;i++)
	{
		con[i]=0;
		for(int j=0;j<n;j++)
			adj[i][j]=-1;
	}
	con[0]=1;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a][b]=c;
		adj[b][a]=c;
	}
	int tot=0;
	for(int i=1;i<n;i++)
	{
		int x=-1,cost=-1;
		for(int j=0;j<n;j++)
		{//assigned elements only
			if(con[j]==0)
				continue;
			for(int k=0;k<n;k++)
			{//unassigned only
				if(con[k]==1)
					continue;
				if(adj[j][k]!=-1)
				{
					if(x==-1)
					{//first occurence
						x=k;
						cost=adj[j][k]; 
					}
					else
					{
						if(adj[j][k]<cost){
							cost=adj[j][k];
							x=k;
						}
					}
				}
			}
		}
		tot+=cost;
		con[x]=1;
	}
	printf("%d",tot);
	return 0;
}