// Matrix DYNAMIC RE - MEMORY ALLOCATION
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row,column,i,j,n,m;
	float **matrix,*p, **matrixNew, *dummy;
	printf("satir ve sutun sayisini veriniz\n");
	scanf("%d %d",&row,&column);
	matrix=(float **) calloc (row,sizeof(float*));
	//printf("adr matrix:%p adr in matrix:%p\n",&matrix,matrix);
	for (i=0;i<row;i++)
	{
		matrix[i]=(float*) calloc (column, sizeof(float));
		printf("adr matrix[%d]:%p adr in matrix[%d]:%p\n",i,&matrix[i],i,matrix[i]);
	}
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			matrix[i][j]=i+(float)j/10;

	printf("eklenecek satir ve sutun sayisini veriniz\n");
	scanf("%d %d",&n,&m);

 	matrixNew =  (float **) realloc(matrix, (row+n)*sizeof(float*) ); 
	for (i=0;i<row;i++)
	{
		dummy= (float*) realloc(matrixNew[i], (column+m)*sizeof(float) ); 
		if (!dummy) 
		{
			printf("yer genisletilemedi\n");
			exit (0);
		}
		matrixNew[i]=dummy;
	
	}
	for (i=row;i<row+n;i++)
		matrixNew[i]=(float*) calloc (column+m, sizeof(float));
	
	for(i=0;i<row+n;i++)
		for(j=0;j<column+m;j++)
			matrixNew[i][j]=i+(float)j/10;
			
	for(i=0;i<row+n;i++)
	{
		for(j=0;j<column+m;j++)
			printf("%1.1f  ",matrixNew[i][j]);
		printf("\n");
	}
	

	
}
