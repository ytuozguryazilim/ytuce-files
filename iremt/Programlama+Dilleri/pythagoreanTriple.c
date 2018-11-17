// verilen bir dizide pythagorean triple bulunup bulunmadýgini kontrol ederek ekrana yazdiran program
// Orn: A[]=3,1,4,6,5  ->  3,4,5
#include <stdio.h>
int main()
{
	int A[20],i,j,k,n,start,stop;
	int a2,b2,c2;
	int p1=0,p2=0;
	printf("eleman sayisi:\n");
	scanf("%d",&n);
	printf("elemanlar:\n");
	for (i=0;i<n;i++)
		scanf("%d",&A[i]);
		
	for (i=0;i<n-2;i++)
	{
		a2=A[i]*A[i];
		for (j=i+1;j<n-1;j++)
		{
			b2=A[j]*A[j];
			p1++;
			for (k=j+1;k<n;k++)
			{
				c2=A[k]*A[k];
				p2++;
				if ((a2==b2+c2) || (b2==a2+c2) || (c2==a2+b2))
					printf("%d %d %d\n",A[i],A[j],A[k]);
			
			}
		}
	}
	
	printf("p1 noktasindan %d kez, p2 noktasindan %d kez gecilmistir\n",p1,p2);
	printf("p1 ve p2 'nin n'e bagli degerleri ne olur?\n");
}
