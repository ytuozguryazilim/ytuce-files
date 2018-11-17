#include <stdio.h>
#include <stdlib.h>
/*
typedef struct{
 char gun;
 char ay;
 char yil;	
} TARIH;	//typedef ile tanimlandigi icin tarih tipi baska structure lar icinde de kullanilabilir

typedef struct{
 char isim[30];
 int maas; 
 TARIH tarih;
}CALISAN; 
*/

/*
typedef struct {
 char isim[30];
 int maas; 
 struct {
 	char gun;
 	char ay;
 	char yil;
 }tarih;		// sadece bir kez kullanilabilir
  
}CALISAN; 
*/


struct CALISAN{
 char isim[30];
 int maas; 
 struct {
 	char gun;
 	char ay;
 	char yil;
 }tarih;		// sadece bir kez kullanilabilir
}; 


/*  ILLEGAL KULLANIM (tarih struct'indan bir deðiþken uretilmeli)
struct CALISAN{
 char isim[30];
 int maas; 
 struct tarih{
 	char gun;
 	char ay;
 	char yil;
 };		// sadece bir kez kullanilabilir
};
*/

int main()
{
	//CALISAN calisan2={"ali",7000,{11,10,90}}; //typedef ile tanimlanmissa
	//CALISAN calisan1;							//typedef ile tanimlanmissa
	struct CALISAN calisan1;
	calisan1.tarih.ay=2;
	calisan1.tarih.gun=12;
	calisan1.tarih.yil=98;
	return 0;
}

