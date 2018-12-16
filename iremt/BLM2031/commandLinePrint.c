#include <stdio.h>
int main(int argc, char *argv[])
{

	while (argc-->0)
		printf("%d %s\n",argc, *argv++  ); 
	return 0;
}


