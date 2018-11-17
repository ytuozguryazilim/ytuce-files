// kullanicidan alinmis bir kelime verilen bir key degeri ile sifrelenmektedir.
// çift numarali indislerde bulunan karakterler için key karakter sonraki
// tek numarali indislerde bulunan karakterler için ise key karakter onceki karakter kullanilmaktadir
// orn: ali  key=2 -> cjk
# include <stdio.h>
# include <string.h>
int main()
{
	int i=0,yon=1,key,n;
	char harf;
	char kelime[30];
	printf("kelimeyi giriniz\n");
	gets(kelime);          			// kelime string seklinde alinir
	n=strlen(kelime);				// kelimenin uzunlugu bulunur
	printf("key giriniz\n");
	scanf("%d",&key);
	
	// ilk cozum indisin tek mi cift mi oldugunu kontrol etmek
	/*
	for (i=0;i<n;i++)
		if (i%2==0)
			kelime[i]=kelime[i]+key;
		else
			kelime[i]=kelime[i]-key;
	*/
	
	// kontrol kullanmadan da cozebiliriz
	for (i=0;i<n;i++,yon=-yon)
		kelime[i]=kelime[i]+(key*yon);
	
	
	puts(kelime);
	return 0;
	
	
}
