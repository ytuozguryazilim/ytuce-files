// -154p^3-12p^2+5p^1 formatýndaki bir polinomun sonucunu verilen p degeri icin hesaplayan program
#include <stdio.h>
void main()
{
	char polinom[100];
	int x,j,i=0,katsayi,carpim,islem=1,sonuc=0;
	gets(polinom);
	scanf("%d",&x);
	if ((polinom[0]=='-') && (polinom[i]!=0))
	{
		islem=-1;
		i++;
	}
	while (polinom[i]!=0)
	{
		katsayi=0;
		while(polinom[i]!='p')
		{
			katsayi=katsayi*10;
			katsayi=katsayi+(polinom[i]-'0');
			i++;
		}
		i=i+2;
		carpim=1;
		for (j=1;j<=(polinom[i]-'0');j++)
			carpim=carpim*x;
		i=i+1;
	
		sonuc=sonuc+islem*(katsayi*carpim);
	
		if (polinom[i]!=0) 
		{
			if (polinom[i]=='+')
				islem=1;
			else
				islem=-1;
			i=i+1;
		}
		
	}
	printf("sonuc:%d\n",sonuc);
}
