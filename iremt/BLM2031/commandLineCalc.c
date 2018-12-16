#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	
	int say1,say2;
	if (argc!=4)
	{
		printf("eksik parametre");
		exit(0);
	}
	
	say1=atoi(argv[2]);
	say2=atoi(argv[3]);
	
	if (!strcmp("topla",argv[1]))  //aynilarsa 0
		printf("%d\n",say1+say2);
	else
		printf("%d\n",say1-say2);

return 0;
}


