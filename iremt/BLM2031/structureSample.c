#include <stdio.h>
/*
struct
{
 char OGR_isim[15] , ogr_soyisim[20]; 
 short OGR_yas;
 float OGR_puan; 
} ogrenci1;  //tek bir degisken üretecek tek bir structure kullanmak istiyorsan. Bunu birdaha kullanamazsýn
*/
/*
struct OGR
{
 char OGR_isim[15] , OGR_soyisim[20]; 
 short OGR_yas;
 float OGR_puan; 
} ogrenci1;  //ogrenci1,ogrenci2,ogrenciDizi[3]; de olabilirdi. Structure i tanýmladýðýn yerde deðiþken üretmelisin
*/

/*
struct OGR
{
 char OGR_isim[15] , OGR_soyisim[20]; 
 short OGR_yas;
 float OGR_puan; 
}; 
struct OGR ogrenci1,ogrenci2;  //ayni özelliklere sahip farkli degiskenler uretilebilir. main icinde de tanimlanabilir
struct OGR ogrenci3={"ahmet","baris",20,20};   //initialization
*/


typedef struct{
 char OGR_isim[15] , OGR_soyisim[20]; 
 short OGR_yas;
 float OGR_puan; 
}OGR; // ogr tipi oluþturulur. bu tipden yeni degiskenler uretilebilir


int main()
{
   	
	OGR ogrenci1;  //typedef ile tanýmlamýþsan
	printf("ogrenci bilgilerini veriniz\n");
	scanf("%s %s %d %f",ogrenci1.OGR_isim,ogrenci1.OGR_soyisim,&ogrenci1.OGR_yas,&ogrenci1.OGR_puan);
	if (ogrenci1.OGR_yas<18)
	{
		ogrenci1.OGR_puan++;
		printf("%s %s isimli ogrencinin yeni puani:%f\n",ogrenci1.OGR_isim,ogrenci1.OGR_soyisim,ogrenci1.OGR_puan);
	}
	
	return 0;
}
