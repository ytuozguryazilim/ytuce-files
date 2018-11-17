// DIZI IN FUNCTION
#include <stdio.h>
int toplaDiziv1(int *,int);
int toplaDiziv2(int *,int);
int* diziAl (int);
int main()
{
	int dizi[20],n,i,toplam;
	int *dizi2;
	printf("Dizinin eleman sayisiniz giriniz\n");
	scanf("%d",&n);
	printf("elemanlari giriniz\n");
	for (i=0;i<n;i++)
		scanf("%d",&dizi[i]);
	toplam=toplaDiziv1(dizi,n);
	printf("toplam v1:%d\n",toplam);

	toplam=toplaDiziv2(dizi,n);
	printf("toplam v2:%d\n",toplam);
    
	printf("Ýkinci dizinin eleman sayisiniz giriniz\n");
	scanf("%d",&n);
	dizi2=diziAl(n);
	toplam=toplaDiziv1(dizi2,n);
	printf("toplam v1:%d\n",toplam);
	return 0;
}

int toplaDiziv1(int *dizi,int boyut)
{
	int i=0,toplam=0;
	for (i=0;i<boyut;i++)
		toplam+=dizi[i];
	return toplam;
}
//syntax olarak hata vermez ancak local deðiþkenler fonksiyon sonlandiginda deallocate edilir
//bu sebeple yanlis bir kullanim
int* diziAl(int boyut)
{
	int dizi2[50],i;
	printf("elemanlari giriniz\n");
	for (i=0;i<boyut;i++)
		scanf("%d",&dizi2[i]);
	return dizi2;
}

int toplaDiziv2(int dizi[],int boyut)
{
	int i=0,toplam=0;
	for (i=0;i<boyut;i++)
		toplam+=*(dizi+i);
	return toplam;
}


