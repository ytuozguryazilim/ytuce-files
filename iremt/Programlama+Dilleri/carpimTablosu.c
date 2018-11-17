#include <stdio.h>
int main( ) {
int j, k;
	printf("          1    2    3    4    5    6    7    8    9    10\n");
	printf("\n-------------------------------------------------------------------\n");
	for (j=1; j<=10; j++)
	{
		printf("%5d|", j);
		for (k=1;k<=10;k++)
			printf("%5d", j*k);
		printf("\n");
	}
	return 0;
}
