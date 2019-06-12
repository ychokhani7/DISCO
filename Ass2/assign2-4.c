#include<stdio.h>
#include<stdlib.h>
void recursive(int n,int adj1[n][n],int adj2[n][n],int arr[n],int flag[n],int pos)
{
	if(pos==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(adj1[i][j]!=adj2[arr[i]][arr[j]])
					return;
			}
		}
		printf("Yes");
		exit(0);
	}
	else{ 
		for (int i = 0; i < n; ++i)
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				arr[pos]=i;
				recursive(n,adj1,adj2,arr,flag,pos+1);
				flag[i]=0;
			}
		}
	}
}
int main()
{
	int n,a;
	scanf("%d%d",&n,&a);
	int adj1[n][n],adj2[n][n];
	int flag[n];//to check if the number is already assigned or not
	for(int i=0;i<n;i++)
	{
		flag[i]=0;
		for(int j=0;j<n;j++)
			adj1[i][j] = adj2[i][j]= 0;
	}
	for(int i = 0;i<a;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj1[x][y]=1;
	}
	int m,b;
	scanf("%d%d",&m,&b);
	if(n != m || a != b)
	{
		printf("No");
		exit(0);
	}
	for(int i = 0; i < b; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj2[x][y] = 1;
	}
	int arr[n];
	recursive(n,adj1,adj2,arr,flag,0);
	printf("No");
}