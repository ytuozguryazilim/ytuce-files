#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
	char isim[20], soyisim[20];
	int numara;
	float puan;
}OGRENCI;

void dosyaOlustur();
void dosyaOku(FILE *);

int main()
{
	FILE *fa,*fb,*fs;
	OGRENCI ogr1,ogr2;
	
	dosyaOlustur();
	
	fa=fopen("Akitap.bin","rb");
	if (fa==NULL)
	{
		printf("not opened\n");
		exit(0);
	}
	
	fb=fopen("Bkitap.bin","rb");
	if (fa==NULL)
	{
		printf("not opened\n");
		exit(0);
	}
	
	fs=fopen ("Sonuc","wb");
	if (fs==NULL)
	{
		printf("not opened\n");
		exit(0);
	}
	
	fread(&ogr1,sizeof(OGRENCI),1,fa);
	fread(&ogr2,sizeof(OGRENCI),1,fb);
	
	while (!feof(fa) && !feof(fb))
	{
		if (ogr1.puan<ogr2.puan)
		{
			fwrite(&ogr2, sizeof(OGRENCI),1,fs);
			fread(&ogr2, sizeof(OGRENCI),1,fb);
		}
		else
		{
			fwrite (&ogr1,sizeof(OGRENCI),1,fs);
			fread(&ogr1, sizeof(OGRENCI),1,fa);
		}
	}
	
	if (feof(fa))
	{
		while (!feof(fb))
		{
			fwrite (&ogr2,sizeof(OGRENCI),1,fs);
			fread(&ogr2,sizeof(OGRENCI),1,fb);
		}
	}
	else
	{
		while (!feof(fa))
		{
			fwrite (&ogr1,sizeof(OGRENCI),1,fs);
			fread(&ogr1,sizeof(OGRENCI),1,fa);
		}
	}

	fclose(fa);
	fclose(fb);
	fclose(fs);
	
	fs=fopen ("Sonuc","rb");
	dosyaOku(fs);
}


void dosyaOlustur()
{
	int na,nb,i;
	OGRENCI ogr,ogrDizi[20];
	FILE *fs;
	fs=fopen ("Akitap.bin","wb");
	if (fs==NULL)
	{
		printf("not opened\n");
		exit(0);
	}
	
	printf("kitapcik a'dan kac ogrenci var\n");
	scanf("%d",&na);
	printf("ogrenci bilgilerini veriniz (azalan puan sirasi ile)\n");
	for (i=0;i<na;i++)
	{
		scanf("%s %s %d %f",ogr.isim,ogr.soyisim,&ogr.numara,&ogr.puan);
		fwrite (&ogr,sizeof(OGRENCI),1,fs);
	}
	fclose(fs);
	
	
	fs=fopen ("Bkitap.bin","wb");
	if (fs==NULL)
	{
		printf("not opened\n");
		exit(0);
	}
	
	printf("kitapcik b'dan kac ogrenci var\n");
	scanf("%d",&nb);
	printf("ogrenci bilgilerini veriniz (azalan puan sirasi ile)\n");
	for (i=0;i<nb;i++)
		scanf("%s %s %d %f",ogrDizi[i].isim,ogrDizi[i].soyisim,&ogrDizi[i].numara,&ogrDizi[i].puan);
	
	fwrite (ogrDizi,sizeof(OGRENCI),nb,fs);
	fclose(fs);
}

void dosyaOku(FILE *fs)
{
	OGRENCI ogr;
	fread(&ogr,sizeof(OGRENCI),1,fs);
	while (!feof (fs))
	{
		printf("%s %s %d %f\n",ogr.isim,ogr.soyisim,ogr.numara,ogr.puan);
		fread(&ogr,sizeof(OGRENCI),1,fs);
	}
}

