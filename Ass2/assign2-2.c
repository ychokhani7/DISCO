#include<stdio.h>
#include<string.h>

int n,m;
int graph[10][10];
int cur[10],bes[10];
int ans = 1e9;

void swap(int* a,int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void update()
{
	int cbest = 0;
	for(int i=0;i<n;++i)
	{
		if(graph[cur[i]][cur[(i+1)%n]]==-1)
			return;
		cbest += graph[cur[i]][cur[(i+1)%n]];
	}
	
	if(cbest<ans)
	{
		ans = cbest;
		memcpy(bes,cur,4*n);
	}
}

void all_perms(int x)
{
	if(x==n)
	{
		update();
		return;
	}

	for(int i=x;i<n;++i)
	{
		swap(cur+x,cur+i);
		all_perms(x+1);
		swap(cur+x,cur+i);
	}
}

int main()
{
	memset(graph,-1,sizeof(graph));
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;++i)
	{
		int p,q,r;
		scanf("%d %d %d",&p,&q,&r);
		graph[p][q] = r;
		graph[q][p] = r;
	}
	for(int i=0;i<n;++i)
		cur[i] = i;
	all_perms(0);
	for(int i=0;i<n;++i)
		printf("%c=>",'A'+bes[i]);
	printf("%c",'A'+bes[0]);
	printf("\n%d\n",ans);
	return 0;
}