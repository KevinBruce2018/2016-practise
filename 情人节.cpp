#include<stdio.h>

int main(void)
{
	char name[100][11];
	int i;
	for(i = 0;i < 100; i++)
	{
		scanf("%s",name[i]);
		if(name[i][0] == '.')
			break;
	}
    //过于简单 没话说……
	if(i< 2 )
		printf("Momo... No one is for you ...\n");
	else if(i < 14)
		printf("%s is the only one for you...\n",name[1]);
	else
		printf("%s and %s are inviting you to dinner...\n",name[1],name[13]);
	return 0;
}