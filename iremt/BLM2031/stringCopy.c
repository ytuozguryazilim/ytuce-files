//verilen bir string'in uzunlugunu bulan ve baska bir string'e kopyalayan program

#include <stdio.h>
int myStrLenFunc(char*);
void myStrcpy(char*,char*);
void myStrcpyV2(char*,char*);
void myStrcpyV3(char*,char*);

int main()
{
char p[] = "anne"; 
printf("%d\n",myStrLenFunc(p));
char m[10];
myStrcpy(p,m);
//myStrcpyV2(p,m);
//myStrcpyV3(p,m);
printf("%s\n",m);
return 0;
}

int myStrLenFunc(char* str)
{
	int i;
	while (str[i])
		i++;
	return i;	
}

void myStrcpy(char str1[],char str2[])
{
	int i;
	for (i=0;str1[i];i++)
		str2[i]=str1[i];
	str2[i]='\0';
	
}

void myStrcpyV2(char *str1,char *str2)
{
	int i;
	for (i=0;*(str1+i);i++)
		*(str2+i)=*(str1+i);
	str2[i]='\0';
	
}

void myStrcpyV3(char *str1,char *str2)
{
	while(*str2++=*str1++);	//An assignment expression has the value of the left operand after the assignment
	
}


