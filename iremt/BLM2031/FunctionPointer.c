#include <stdio.h>
// Two simple functions
int fun1(int,int);
int fun2(int,int);
void wrapper(int (*)(),int (*)(),int,int);
//void wrapper(int (*)(int,int),int (*)(int,int),int,int);

int fun1(int a,int b)
{
	printf("Fun1\n");  
	return a-b;
}

int fun2(int a,int b)
{ 
	printf("Fun2\n"); 
	return b-a;
}
// A function that receives two function pointers 
// as parameter and calls the appropriate one

//void wrapper(int (*fun1)(int,int),int (*fun2)(int,int),int a,int b)
void wrapper(int (*funx)(),int (*funy)(),int a,int b)
{
	int c;
	if (a>b)		
		c=(*funx)(a,b);
	else
		c=(*funy)(a,b);
	
	printf("result:%d",c);
}

int main()
{
	wrapper(fun1,fun2,70,10);
	return 0;
}
