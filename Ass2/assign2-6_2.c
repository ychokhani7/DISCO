#include<stdio.h>
int recursive(int z,int current,int x,int y){
	if(x==y) return 1;
	if(z==current) return 0;
	if(recursive(z,current+1,x<<1,y)==1) return 1;
	if(recursive(z,current+1,(x<<3)+(x<<1)+1,y)==1) return 1;
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(recursive(z,0,x,y)==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}