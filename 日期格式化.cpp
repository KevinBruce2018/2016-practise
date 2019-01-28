#include <stdio.h>

int main(void)
{
	int day,mon,year;
	scanf("%d-%d-%d",&mon,&day,&year);
	printf("%d-%02d-%02d\n",year,mon,day);
	return 0;
}