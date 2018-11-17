 /*2 3 4 8 90 78 2 90 2 5   // 10 elemanly 
 esik degeri 1.2 verilmelidir*/
#include <stdio.h>
#define N 10

int kontrol(float ,float , float );

int main(){
	float dizi[N],toplam=0,ort=0,ustsinir,altsinir;
	float esikdeger=0;
	int i,outlier=0,m=0;
	/* Dizinin elemanlarý klavyeden giriliyor, ayný anda elemanlar toplanýyor  */
	for(i=0;i<N;i++){   
		printf("%d. elemani giriniz :",i+1);
		scanf("%f",&dizi[i]);
		toplam +=dizi[i];
	}

	printf("Esik degeri giriniz :");
	scanf("%f",&esikdeger);
    
	/*ortalama alinir, alt ve üst sýnýrlar hesaplanýr */
	ort=toplam/N;
	ustsinir=(esikdeger*ort)+ort;
	altsinir=ort-(esikdeger*ort);
	
	for(i=0;i<N;i++){
		if(kontrol(dizi[i],ustsinir,altsinir)){
				printf("\n %2.0f outlier degerdir",dizi[i]); 
				m++;
		}
    }
    if(m!=0)
    	printf("\noutlier sayisi:%d\n",m);
    else
		printf("outlier yok");
    
	return 0;
}

int kontrol(float sayi,float ustlimit, float altlimit){
	return (sayi>ustlimit || sayi<altlimit);
}

