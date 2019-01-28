#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N;
	char a[10][4];

	scanf("%d%*c",&N);

	for(int i = 0;i < N;i++){
		int breath,jump;
		scanf("%s %d %d%*c",a[i],&breath,&jump);
		if( (breath>20 ||breath<15) || (jump<50 ||jump>70))
			printf("%s\n",a[i]);
	}

	return 0;
}