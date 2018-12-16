#include<stdio.h>
#include<stdlib.h>

typedef struct
 {
  int no,sure,*gol;
  int macSayisi;
  } OYUN;

OYUN *stryerac1(int n)
 {
   OYUN *dizi;
   dizi=(OYUN *) calloc(n,sizeof(OYUN));
   return dizi;
 }

int hesapla (OYUN *oyuncu,int n)
{
  int i,j,yer,toplam;
  float verim,maxverim=0;
  for (i=0;i<n;i++)
  {
   		toplam=0;
		for (j=0;j<oyuncu[i].macSayisi;j++)
   			toplam+=oyuncu[i].gol[j];
  		verim=(float)toplam/oyuncu[i].sure;
  		printf("verim:%f no:%d\n",verim,oyuncu[i].no);
   		if (verim>maxverim)
  	 	{
   			maxverim=verim;
   			yer=i;
   		}
  }
  return yer;
}

int main()
{
   int i,y,n,j,mac,*sayilar;
   OYUN *oyuncu;
   int hesapla (OYUN *,int);
   OYUN *stryerac1(int);

   printf("kac adet oyuncu girmek istiyorsunuz\n");
   scanf("%d",&n);
   //oyuncu icin yer ac
   oyuncu=stryerac1(n);
   for (i=0;i<n;i++)
	{
             printf("oyuncu no?: ");
             scanf("%d",&oyuncu[i].no);
             printf("kac adet mac oynamis\n");
   			 scanf("%d",&mac);
			 // sayilar her seferinde yeni acilan yerin adresini tutar
			 sayilar=(int *) calloc(mac,sizeof(int));
			 oyuncu[i].gol=sayilar;
			 // her futbolcunun oynadigi mac sayisini ilgili field a atalim. 
			 oyuncu[i].macSayisi=mac;
			 printf("maclar icin yer acildi goller?: ");
			 for (j=0;j<mac;j++)
             	scanf("%d",&oyuncu[i].gol[j]);
             printf("sure?: ");
             scanf("%d",&oyuncu[i].sure);
   }
   // maximum verimli oyuncu
   y=hesapla(oyuncu,n);
   printf("no:%d\n\n",oyuncu[y].no);
   
   // tum oyuncu bilgileri
   for (i=0;i<n;i++)
   {
   		printf("\n no:%d sure:%d maclar:\n",oyuncu[i].no, oyuncu[i].sure);
   		for (j=0;j<oyuncu[i].macSayisi;j++)
            printf("%d ",oyuncu[i].gol[j]);
   }
   
   for (i=0;i<n;i++)
		free (oyuncu[i].gol);
   free(oyuncu);
   return 0;
 }
