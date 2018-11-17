// DYNAMIC MEMORY ALLOCATION
#include <stdio.h>
#include <stdlib.h>
void OgrenciAl (int *, int, int );
float OrtalamaBul (int *, int );
void OgrListele (int *, int );
void YerGenislet (int *,int **, int , int );

int main()
{
	int *OgrNotDizi,*OgrNotDizi2;
	int **dummy;
	int i,n,m;
	float ort;
	printf("Ogrenci sayisini veriniz\n");
	scanf("%d",&n);
	
	OgrNotDizi = (int *) calloc( n , sizeof(int) ); 
	/* 
		MALLOC ILE YER AYRILIRSA
		OgrNotDizi = (int *) malloc( n * sizeof(int) ); 
	
	*/
	OgrenciAl (OgrNotDizi,0,n);
    ort=OrtalamaBul (OgrNotDizi, n);
	printf("ortalama:%f\n",ort);
   	OgrListele (OgrNotDizi, n);
   	printf("Kac ogrenci eklemek istersiniz");
	scanf("%d",&m);
	YerGenislet(OgrNotDizi,&OgrNotDizi2,n,m);
	if (OgrNotDizi2 == NULL)
		printf("yer genisletilemedi\n");
	else
		OgrenciAl (OgrNotDizi2,n,m);
	
	ort=OrtalamaBul (OgrNotDizi2, n+m);
	printf("yeni ortalama:%f\n",ort);
    OgrListele (OgrNotDizi2, n+m);
    free (OgrNotDizi2);
     
	return 0;
}

void OgrenciAl (int *ogrList, int basla, int sayi)
{
	int i;
	printf("ogrenci notlarini giriniz\n");
	for( i=basla; i < basla+sayi; i++) 
		scanf ( "%d", &ogrList[i] );
	
}

float OrtalamaBul (int *ogrList, int n)
{
	int i,toplam=0;
	for( i=0; i < n; i++) 
		toplam+=*(ogrList + i);
	
	return (float)toplam/n;
}

void OgrListele (int *ogrList, int n)
{
	int i;
	for( i=0; i < n; i++) 
		printf ( "%d  ", ogrList[i] );
	printf("\n");
}

void YerGenislet (int *ogrList, int **ogrList2 ,int n, int m)
{
	*(ogrList2) = realloc(ogrList, (m+n)*sizeof(int) ); 
}

