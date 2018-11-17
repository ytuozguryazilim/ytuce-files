// verilen bir sayinin Trimorphic olup olmadigini kontrol eden program
// Örn: 25, 5, 4 
#include <stdio.h>
int main()
{
	int N,kup,bol,carp;
	scanf("%d",&N);
	kup=N*N*N;
	carp=1;
	bol=N;
	while (bol>0)
	{
		bol=bol/10;
		carp=carp*10;
	}
	if ((kup-N)%carp==0)
		printf("Trimorphic");
	else
		printf("Degil");
		
}
