#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *one,*zero;
}node;
int main()
{
	node *root = (node*)malloc(sizeof(node));
	root->one=root->zero=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		node *current=root;
		for(int j=31;j>=0;j--)
		{//when j=31, the bit at 31st index from right will get extracted
			if(((a>>j)&1)==1)
			{//to get the bit at (j+1)th position from right
				if(current->one==NULL)
				{
					node *t = (node*)malloc(sizeof(node));
					t->one=t->zero=NULL;
					current->one=t;
				}
				current=current->one;
			}
			else
			{
				if(current->zero==NULL)
				{
					node *t = (node*)malloc(sizeof(node));
					t->one=t->zero=NULL;
					current->zero=t;
				}
				current=current->zero;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a;
		scanf("%d",&a);
		node *current=root;
		int val=0;
		int flag;
		if((a>>31)&1==1)
		{
			if(current->one!=NULL)//to obtain a positive number
				current=current->one;
			else
			{//a negative xor is obtained
				current=current->zero;
				val+=1<<31;
			}
		}
		else
		{
			if(current->zero!=NULL)
				current=current->zero;
			else
			{
				current=current->one;
				val+=1<<31;	
			}
		}
		for(int j=30;j>=0;j--)
		{
			if(((a>>j)&1)==1)
			{
				if(current->zero!=NULL)
				{
					current=current->zero;
					val+=1<<j;
				}
				else current=current->one;
			}
			else{
				if(current->one!=NULL)
				{
					current=current->one;
					val+=1<<j;
				}
				else current=current->zero;	
			}
		}
		printf("%d\n",val);
	}
}