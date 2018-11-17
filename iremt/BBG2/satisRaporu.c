// urunAdet kadar urun saticiAdet kadar satici tarafindan satilmaktadir. Urunlerin birim fiyatlari urunAdet dizisinde tutulmaktadir
// Her urunun her satici tarafindan kac adet satildigi bilgisi ise urunAdet*saticiAdet boyutunda bir dizide verilmektedir
// Verilen bilgileri kullanarak matris formunda bir satis raporu olusturan programi yaziniz
// En cok satisi yapan saticiyi bulunuz
// Her urunun her satici tarafindan farkli bir birim fiyat ile satilmasi mümkün olsaydi bilgiler nasil bir formda tutulabilirdi?
#include <stdio.h>
int main()
{
    int Fiyat[10],Satis[100],Rapor[10][10];
    int SaticiAdet,UrunAdet,Kazanan,i,j,max=0,top;
    printf("SaticiAdet ve UrunAdet nedir?\n");           
	scanf("%d",&SaticiAdet);
	scanf("%d",&UrunAdet);
	printf ("Urun Fiyatlarini Veriniz\n");    
    for (i=0;i<UrunAdet;i++)
        scanf("%d",&Fiyat[i]);
    printf ("Satislari Veriniz\n");    
    for (i=0;i<UrunAdet*SaticiAdet;i++)
        scanf("%d",&Satis[i]);
    for (i=0;i<SaticiAdet;i++)
    {
        top=0;
        for (j=0;j<UrunAdet;j++)
            {
            Rapor[j][i]=Satis[i*UrunAdet+j]*Fiyat[j];
            top=top+Rapor[j][i];
            }
        if (max<top)
        {
               max=top;
               Kazanan=i;
        }   
    }
    printf ("Rapor:\n"); 
    for (i=0;i<UrunAdet;i++)
    {
        for (j=0;j<SaticiAdet;j++)
            printf("%d ",Rapor[i][j]);
        printf("\n");
    }    
    
    printf("En cok satisi:%d nolu satici yapmistir",Kazanan);
    getch();
    return 0;
}

