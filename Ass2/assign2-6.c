#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,x,y,z,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d %d %d",&x,&y,&z);
		while(y!=x)
		{
			if(y%2==0)
			{
				y=y/2;
			}
			else if((y-1)%10==0)
			{
				y=(y-1)/10;
			}
			else
			{
			    cnt=z+1;
				break;
			}
			cnt++;
		}
		if(cnt<=z)
		printf("YES\n");
		else
		printf("NO\n");
	}
}