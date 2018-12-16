/* depo kapasitesi ve depodaki yakit miktarı bilinen bir araç a noktasından b noktasına hareket etmeyi planlamaktadır. 
   a ve b noktalarinin tam ortasinda bir yakit istasyonu bulunmaktadir. Araç, yakiti hedefe ulaşmaya yetmiyorsa yakit 
   istasyonunda deposunu doldurmak zorundadir. Aracın yola cikmaya yetecek yakiti olup olmadigini kontrol eden ve yola
   cikmasi halinde hedefe ulastiginda deposunda kalan yakitin miktarini hesaplayan program
*/
#include <stdio.h>
int main()
{
 int yol, depoKapasite, mevcutYakit;
 float kalanYakit;
 printf("yol uzunlugunu, depo kapasitesini ve mevcut yakit miktarini veriniz\n");
 scanf("%d %d %d",&yol,&depoKapasite,&mevcutYakit);
 if (mevcutYakit>=yol)
 {
    kalanYakit=mevcutYakit-yol;
    printf("yakit alinmadan hedefe ulasildi. kalan yakit:%f\n",kalanYakit);
 }
 else
 {
      /* int iki sayi ile bolme yapildiginda, sonucu ondalikli olarak elde etmek istiyorsak casting yapmaliyiz. */
	 if (mevcutYakit>=(float)yol/2) 
	 {
        kalanYakit=depoKapasite-((float)yol/2);
        printf("yakit alindi. hedefe ulasildi. kalan yakit:%f\n",kalanYakit);                             
     }
     else
     {
        printf("istasyona ulasmaya yetecek kadar yakit yok");
     }
 }
 
 return 0; 
}

