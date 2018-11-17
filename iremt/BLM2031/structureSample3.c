#include <stdio.h>
#include <stdlib.h>

typedef struct{
 char OGR_isim[15] , OGR_soyisim[20]; 
 short OGR_yas;
 float OGR_puan; 
}OGR; // OGR tipi oluþturulur. bu tipden yeni degiskenler uretilebilir


int main()
{
	OGR *ogrenciler;
	int n,i;
	scanf("%d",&n);
	ogrenciler=(OGR*) calloc (n,sizeof(OGR));
	
	/* asagidaki uc erisim de legal*/
	//ogrenciler[0].OGR_yas=19;
	(*ogrenciler).OGR_yas=19;
	//ogrenciler->OGR_yas=19;
	printf("%d",ogrenciler->OGR_yas);
	free (ogrenciler);
	return 0;
}


