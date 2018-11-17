#include <stdio.h>

struct OGR
{
 char OGR_isim[15] , OGR_soyisim[20]; 
 short OGR_yas;
 float OGR_puan; 
}; 


int main()
{
	int i,max=0,maxYer;
	static struct OGR *ogrenci,ogrenciler[3];  
	struct OGR *maxYerStr;
	printf("ogrenci bilgilerini veriniz\n");
	for (i=0;i<3;i++)
	{
		scanf("%s %s %d %f",ogrenciler[i].OGR_isim,ogrenciler[i].OGR_soyisim,&ogrenciler[i].OGR_yas,&ogrenciler[i].OGR_puan);
		if (ogrenciler[i].OGR_puan>max)
		{
			max=ogrenciler[i].OGR_puan;
			maxYer=i;
		}
	}
	
	printf("%s %d\n",ogrenciler[maxYer].OGR_isim,max);
	ogrenci=&ogrenciler[maxYer];  
	printf("v1:%s\n",ogrenci->OGR_soyisim);
	printf("v2:%s\n",(*ogrenci).OGR_soyisim);
	
	/*maximum puan ve yeri bulmak icin kullanýlan kod asagidaki gibi de yazilabilir*/
	/* array üzerinden gitmektense pointer aritmatiði ile pointer uzerinden gidilir*/
	max=0;
	ogrenci=ogrenciler;  
	for (i=0;i<3;i++)
	{
		if (ogrenci->OGR_puan>max)
		{
			max=ogrenci->OGR_puan;
			maxYerStr=ogrenci;
		}
		ogrenci++;
	}
	
	printf("v3:%s\n",maxYerStr->OGR_soyisim);
	printf("boyut:%d\n",sizeof(struct OGR));
}


