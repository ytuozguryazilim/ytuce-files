#include <stdio.h>
typedef struct 
{
    char a;
	char c;
	short b;
	
}ABC;

int main()
{
	ABC v;
	char *pv;
	v.a=10;
	v.b=32;
	v.c=1;
	pv=&(v.a);
	printf("1:%d\n",*pv);
	pv=pv+sizeof(char)+sizeof(char);
	printf("2:%d\n",*pv);
    printf("%p %p %p\n",&(v.a),&(v.b),&(v.c));
    printf("%d %d\n",sizeof(short),sizeof(char));
	return 0;
}
