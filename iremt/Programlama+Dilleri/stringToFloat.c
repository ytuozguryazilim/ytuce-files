// string seklinde verilmis bir ondalıklı bir sayiyi float tipinde bir değişkene atan program
#include <stdio.h>
int main()
{
    char number[20],dummy;
    float result=0,element,j=1.0;
	int i=0;
	printf("ifadeyi veriniz\n");
	gets(number);
	printf("number:%s",number);
	while (number[i]!='.')
	{
		result=result*10;
		result=result+(number[i]-'0');
		i++;
	}
	i++;
	while  (number[i]!=0)
	{
		j=j/10;
		element=number[i]-'0';
		element=element*j;
		result=result+element;
		i++;
	}
	printf("sonuc:%f",result);
	return 0;
}
