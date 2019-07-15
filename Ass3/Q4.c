#include <stdio.h>
#include <string.h>

int main()
{
    int cnt=0;
    int global[26]={};
    int indent[26]={};
    int values[26][26]={};
    int notempty[26]={};
    for(int i=0;i<26;i++)
        indent[i]=-1;
    while(1)
    {
        char str[100];
        str[0]='\0';
        gets(str);
        if(strlen(str)==0)
            break;
        
            
        if(cnt==0)
        {
            for(int i=0;i<strlen(str);i++)
            {
                if((int)str[i]>=97 && (int)str[i]<=122)
                    global[str[i]-'a']=1;
            }
        }
        else
        {
            for(int i=strlen(str)-1;i>=0;i--)
            {
                if(str[i]==':')
                {
                    int spaces=i-1;
                    int ch=str[i-1]-'a';
                    notempty[ch]=1;
                    if(spaces==0)
                    {
                        for(int i=0;i<26;i++)
                            indent[i]=-1;
                    }
                    for(int i=0;i<26;i++)
                    	if(indent[i]==spaces)
                    		indent[i]=-1;
                    indent[str[i-1]-'a']=spaces;
                    gets(str);
                    for(int i=0;i<strlen(str);i++)
                    {
                        if((int)str[i]>=97 && (int)str[i]<=122)
                            values[ch][str[i]-'a']=1;
                    }
                    for(int i=0;i<26;i++)
                        if(global[i])
                            values[ch][i]=1;
                    if(spaces>0)
                    {
                        for(int j=0;j<26;j++)
                        {
                            if(indent[j]<spaces && indent[j]!=-1)
                            {
                                for(int k=0;k<26;k++)
                                {
                                    if(values[j][k])
                                        values[ch][k]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        cnt++;
    }
    
    printf("Global: ");
    for(int i=0;i<26;i++)
        if(global[i])
            printf("%c ",(char)(i+97));
    
    printf("\n");
    
    for(int i=0;i<26;i++)
    {
        if(notempty[i])
        {
            printf("%c: ",(char)(i+97));
            for(int j=0;j<26;j++)
            {
                if(values[i][j])
                {
                    printf("%c ",(char)(j+97));
                }
            }
            printf("\n");
        }
    }
    return 0;
}