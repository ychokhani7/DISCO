#include <stdio.h>

int main(void) {
int n,set[1001][1001],size[1001],imm1[10001],imm2[10001],c,f,z,k,j,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&size[i]);
    for(j=0;j<size[i];j++)
    scanf("%d",&set[i][j]);
}

for(i=0;i<n;i++)
{    if(size[i]==1)
     i++;
    for(j=1;j<(1<<(size[i]))/2;j++)
    { c=0;f=0;
        for(k=0;k<size[i];k++)
        {
            if((j&(1<<k))>0)
            {
                imm1[c]=set[i][k];
                c++;
            }
            else
            {imm2[f]=set[i][k];
            f++;
            }
    }
    for(k=0;k<i;k++)
    {
        for(z=0;z<size[k];z++)
        printf("%d ",set[k][z]);
        printf("\n");
    }
    for(k=0;k<c;k++)
    printf("%d ",imm1[k]);
    printf("\n");
    for(k=0;k<f;k++)
    printf("%d ",imm2[k]);
    printf("\n");
    for(k=i+1;k<n;k++)
    {
        for(z=0;z<size[k];z++)
        printf("%d ",set[k][z]);
        printf("\n");
    }
printf("*******************\n");    
}
}
    return 0;
}