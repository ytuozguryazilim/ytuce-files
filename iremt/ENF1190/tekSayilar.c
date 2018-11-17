/* 1-10 arasý tek sayýlarý ekrana yazdiran program */
#include <stdio.h>
int main()
{
	int i=1;
	while (i<10)
	{
		printf("%d ",i);
		i=i+2;
	}
	
	printf("\n");
	
	i=1;
	do {
		printf("%d ",i);
		i=i+2;
	}while (i<=9);
	
	printf("\n");
	
	for (i=1;i<10;i=i+2)
	{
		printf("%d ",i);
	}
	
	
	
	return 0;
}
