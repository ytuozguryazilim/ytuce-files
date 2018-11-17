/* cm cinsinden kenar uzunluklari verilen bir dikdortgenin
   alanini m2 cinsinden hesaplayip ekrana yazdiran program
*/
#include <stdio.h>
void main(void)
{
 int uzunKenar, kisaKenar; // uzun ve kisa kenar buyuklukleri
 float Alan;               // dikdortgenin alani
 printf("Dikdortgenin kenar uzunluklarini veriniz\n");
 scanf("%d %d",&uzunKenar,&kisaKenar);
 Alan=(float)(uzunKenar*kisaKenar)/10000;  
 printf("Dikdortgenin Alani:%f",Alan);
 getch();   
}

