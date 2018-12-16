#include<stdio.h>
#include<stdlib.h>

typedef struct
 {
  int no,sure,gol[3];
  } OYUN;

int hesapla (OYUN *,int);
OYUN *stryerac1(int);

OYUN *stryerac1(int n)
 {
   OYUN *dizi;
   dizi=(OYUN *) calloc(n,sizeof(OYUN));
   return dizi;
 }

int hesapla (OYUN *oyuncu,int n)
{
  int i,yer;
  float verim,maxverim=0;
  for (i=0;i<n;i++)
  {
   verim=(float)(oyuncu[i].gol[0]+oyuncu[i].gol[1]+oyuncu[i].gol[2])/oyuncu[i].sure;
   if (verim>maxverim)
   {
   maxverim=verim;
   yer=i;
   }
  }
  return yer;
}

OYUN hesaplaV2 (OYUN *oyuncu,int n)
{
  int i,yer;
  OYUN maxOyuncu;
  float verim,maxverim=0;
  for (i=0;i<n;i++)
  {
   verim=(float)(oyuncu[i].gol[0]+oyuncu[i].gol[1]+oyuncu[i].gol[2])/oyuncu[i].sure;
   if (verim>maxverim)
   {
   maxverim=verim;
   maxOyuncu=oyuncu[i];
   }
  }
  return maxOyuncu;
}

OYUN hesaplaV3 (OYUN *oyuncu,int n)
{
  int i,yer;
  OYUN maxOyuncu;
  float verim,maxverim=0;

  for (i=0;i<n;i++)
  {
   verim=(float)(oyuncu->gol[0]+oyuncu->gol[1]+oyuncu->gol[2])/oyuncu->sure;
   if (verim>maxverim)
   {
   maxverim=verim;
   maxOyuncu=*oyuncu;
   }
   oyuncu++;
  }
  return maxOyuncu;
}

int main()
{
   int i,y,n;
   OYUN *oyuncu, maxOyuncu;


   printf("kac adet oyuncu girmek istiyorsunuz\n");
   scanf("%d",&n);
   oyuncu=stryerac1(n);
   for (i=0;i<n;i++)
	{
             printf("oyuncu no: ");
             scanf("%d",&oyuncu[i].no);
             printf("goller: ");
             scanf("%d %d %d",&oyuncu[i].gol[0],&oyuncu[i].gol[1],&oyuncu[i].gol[2]);
             printf("sure: ");
             scanf("%d",&oyuncu[i].sure);
   }
   y=hesapla (oyuncu,n);
   printf("no:%d",oyuncu[y].no);

   maxOyuncu=hesaplaV2(oyuncu,n);
   printf("no:%d",maxOyuncu.no);

   maxOyuncu=hesaplaV3(oyuncu,n);
   printf("no:%d",maxOyuncu.no);
   return 0;
 }

