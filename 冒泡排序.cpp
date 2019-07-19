#include<stdio.h>
#include<string.h>
int main(void)
{
    int m,n;
    scanf("%d %d",&m,&n);
    getchar();
    char s[101][101];
    for(int i = 0;i< m;i++)
    {
        fgets(s[i],20,stdin);
        s[i][strlen(s[i])-1] = '\0';
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m-1-i;j++)
        {
            if(strcmp(s[j],s[j+1])>0)
            {
                char a[101];
                strcpy(a,s[j]);
                strcpy(s[j],s[j+1]);
                strcpy(s[j+1],a);
            }
        }
    }
    for(int i = 0;i < m;i++)
        printf("%s\n",s[i]);
    return 0;
}