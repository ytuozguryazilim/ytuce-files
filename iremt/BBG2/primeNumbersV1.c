// Verilemn N sayisina kadar olan asal sayilari bulan program 
// Orn: N=110  prime[]= 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109
#include <stdio.h>
#include <math.h>
int main()
{
	int i,N,pp=3,diziboy=1,spr;
	int prime[100];
	prime[0]=2;
	printf("N?\n");
	scanf("%d",&N);
	while (pp<=N)
	{
		i=0;
		while ((i<diziboy) && (pp%prime[i]!=0))
			i++;
		if (i>=diziboy)	
		{
			prime[i]=pp;
			diziboy++;
		}
		pp=pp+2; //pp=pp+1; de olabilirdi. Boyle yaparak cift sayilari atliyoruz. 
	}
	
	for (i=0;i<diziboy;i++)
		printf("%d ",prime[i]);
	return 0;	
}
