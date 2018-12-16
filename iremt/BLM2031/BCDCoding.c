#include <stdio.h> 
// bu þekilde de tanýmlanabilir ama bitfieldlerin yerleri bu sýrada yerleþmeyebilir
//sonuç implementation dependent deðiþir
typedef union
{
	struct {
			unsigned int digit1:4;
			unsigned int digit2:4;
			unsigned int digit3:4;
			unsigned int digit4:4;
	}digitAll;
	unsigned int all; 
}BCD;

int main()
{
	int bilgi;
	unsigned int b1,b2,b3,b4;
	BCD code;
	printf("musteri bilgisini giriniz:\n");
	scanf("%d",&bilgi);
	b1=bilgi%10;
	bilgi/=10;
	b2=bilgi%10;
	bilgi/=10;
	b3=bilgi%10;
	b4=bilgi/10;
	
	code.digitAll.digit1=b1;
	code.digitAll.digit2=b2;
	code.digitAll.digit3=b3;
	code.digitAll.digit4=b4;
	printf("1:%d\n",code.digitAll.digit1);
	printf("2:%d\n",code.digitAll.digit2);
	printf("3:%d\n",code.digitAll.digit3);
	printf("4:%d\n",code.digitAll.digit4);
	
	printf("code all:%d\n",code.all);
}
