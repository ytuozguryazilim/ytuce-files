// terimleri büyükten küçüðe sýralanmýþ iki polinomu toplayan program
// polinom üst ve katsayýlarý matris formunda verilmistir
#include <stdio.h>
int main( ) 
{
	static int pol1[2][10],pol2[2][10],sonuc[2][20];
	int i,j,n,m,z;
	
	printf("ilk polinomun terim sayisi?\n");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("ust ve katsayi?\n");
		scanf("%d %d",&pol1[0][i],&pol1[1][i]);
	}
	printf("ikinci polinomun terim sayisi?\n");
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		printf("ust ve katsayi?\n");
		scanf("%d %d",&pol2[0][i],&pol2[1][i]);
	}
	i=j=z=0;
	while ((i<n) && (j<m))
	{
		if (pol1[0][i]==pol2[0][j])
		{
			sonuc[0][z]=pol1[0][i];
			sonuc[1][z]=pol1[1][i]+pol2[1][j];
			z++;
			i++;
			j++;
		}
		else
			if (pol1[0][i]<pol2[0][j])
			{
				sonuc[0][z]=pol2[0][j];
				sonuc[1][z]=pol2[1][j];
				z++;		
				j++;
			}
			else
			{
				sonuc[0][z]=pol1[0][i];
				sonuc[1][z]=pol1[1][i];
				z++;		
				i++;
			}
	}
	
	if (i>=n)
		while (j<m)
		{
				sonuc[0][z]=pol2[0][j];
				sonuc[1][z]=pol2[1][j];
				z++;		
				j++;
		}
	else
		while (i<n)
		{
				sonuc[0][z]=pol1[0][i];
				sonuc[1][z]=pol1[1][i];
				z++;		
				i++;
		}
	
	for (i=0;i<z;i++)
	{
		printf("%d %d\n",sonuc[0][i],sonuc[1][i]);
	}

	return 0;
}
