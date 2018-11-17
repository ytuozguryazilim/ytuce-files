#include <stdio.h>
int mystrlen ( register char *p)  
{
	register int len=0;
	while(*p++)  
		len++;
	return len;
}

int main()
{
	printf("--%d--",mystrlen("irem"));
	return 0;
}
