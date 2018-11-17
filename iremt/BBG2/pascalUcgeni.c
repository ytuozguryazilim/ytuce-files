// n dereceli pascal ucgenini olusturan program
#include <stdio.h>
int main()
{
	int n,m,i,j,bas,son;
	static int mat[50][100];
	printf("Ucgenin derecesi?\n");
	scanf("%d",&n);
	m=2*n-1;
	mat[0][n-1]=1;
	bas=son=n-1;
	for (i=1;i<=n-1;i++)
	{
		bas--;
		son++;
		for (j=bas;j<=son;j=j+2)
		{
			mat[i][j]=mat[i-1][j-1]+mat[i-1][j+1];
		}
	}
	for (j=bas+1;j<=son-1;j=j+2)
		mat[i][j]=mat[i-1][j-1]+mat[i-1][j+1];
	mat[n-1][0]=1;
	mat[n-1][m-1]=1;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			printf("%4d ",mat[i][j]);
		printf("\n");
	}
	return 0;
}
