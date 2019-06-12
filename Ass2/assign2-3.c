#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
void dfs(int n, node* edges[n],int visited[n],int *count,int x)
{
	node *current = edges[x];
	while(current!=NULL)
	{
		if(visited[current->val]==0)
		{
			visited[current->val]=1;
			*count=*count+1;
			dfs(n,edges,visited,count,current->val);
		}
		current=current->next;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	node* edges[n];
	node *current[n];
	int visited[n];
	int count=0;
	for(int i=0;i<n;i++)
		edges[i]=NULL;
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		node *t1 = (node*)malloc(sizeof(node));
		node *t2 = (node*)malloc(sizeof(node));
		t1->next = t2->next=NULL;
		t1->val=b;
		t2->val=a;
		if(edges[a]==NULL)
			current[a]=edges[a]=t1;
		else
		{
			current[a]->next=t1;
			current[a]=t1;
		}
		if(edges[b]==NULL)
			current[b]=edges[b]=t2;
		else
		{
			current[b]->next=t2;
			current[b]=t2;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			visited[j]=0;//resetting
		visited[i]=1;
		count=1;
		if(edges[i]!=NULL)
			dfs(n,edges,visited,&count,edges[i]->val);
		if(count<n)
			printf("%d ",i);
	}
}