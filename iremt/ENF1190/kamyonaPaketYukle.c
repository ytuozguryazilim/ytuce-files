/* 
agirlik ve hacim olarak tasima kapasitesi verilen kamyonlara belirli sayýda paket yuklenecektir.
kullanýcýnýn istedigi kadar paketi alip kamyonlara yukleyen program
*/
#include <stdio.h>
int main(void)
{
 int i,agirlikKapasite, hacimKapasite, toplamHacim=0, toplamAgirlik=0, kamyonNo=1, paketSayisi, paketAgirlik, paketHacim;
 printf("kamyonlarin hacim ve agirlik kapasitesini veriniz\n");
 scanf("%d %d",&hacimKapasite,&agirlikKapasite);
 printf("paket sayisini veriniz\n");
 scanf("%d",&paketSayisi);
 
 for (i=1;i<=paketSayisi;i++)
 {
     printf("paket agirligini ve hacmini veriniz\n");
     scanf("%d %d",&paketAgirlik,&paketHacim);
     if ((paketAgirlik>agirlikKapasite) || (paketHacim>hacimKapasite))
        printf("tek seferde tasinamaz\n");
     else
     {
         if (((paketAgirlik+toplamAgirlik)<=agirlikKapasite) && ((paketHacim+toplamHacim)<=hacimKapasite))
         {
            toplamAgirlik=toplamAgirlik+paketAgirlik;
            toplamHacim=toplamHacim+paketHacim;                      
         }
         else
         {
            kamyonNo=kamyonNo+1;
            toplamAgirlik=paketAgirlik;
            toplamHacim=paketHacim;                
         }
         printf("paket %d nolu kamyona yuklendi\n",kamyonNo);
     }
     
 }
 
getch();   
 return 0; 
}

