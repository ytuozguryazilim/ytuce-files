// Verilen bir n sayýsý için aþaðýdaki þekilde görülen bir kare matris bastýran program. Ýþlem tek for ile yapýlmaktadýr.
// n=3 x x
//		x
//	   x x
#include <stdio.h>
int main()
{
	static char mat[100][100];
	int i,j,n,x,y;
	printf("Boyutu veriniz\n");
	scanf("%d",&n);
	for (i=0;i<n*n;i++)
	{
		x=i/n;
		y=i%n;
		if ((x+y)%2==0)
			mat[x][y]='x';
		else
			mat[x][y]=' ';
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%c ",mat[i][j]);
		printf("\n");
	}
	return 0;
}

