// m*n boyutunda gri seviye bir resim için histogram çýkaran program
#include <stdio.h>
int main()
{
	int m,n,i,j,temp;
	static int hist[256];
	// asagidaki kod parcasi ile veri girisi kalvyeden de yapilabilir
	/*
	int R[50][50];
	scanf("%d %d",&m,&n);
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			scanf("%d",&R[i][j]);
	*/
	
	/* R matrisi initialize edilirse */		
	m=5; n=5;
	int R[5][5]={{250,250,250,251,251},
				 {250,250,251,251,252},
				 {251,251,250,252,253},
				 {253,250,251,254,254},
				 {255,255,254,251,250}};
	
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
		{
			temp=R[i][j];
			hist[temp]++;
		}
	
	for (i=0;i<=255;i++)
	{
		printf("%3d - ",i);
		for (j=1;j<=hist[i];j++)
			printf("*");
		printf("\n");
	}
	
}


