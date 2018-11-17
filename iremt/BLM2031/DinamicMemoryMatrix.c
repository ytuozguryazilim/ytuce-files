// dinamic memory allocation
#include <stdio.h>
#include <stdlib.h>
int main()
{		
	int row,column,i,j;
	float **matrix,*p;
	printf("1-9 araliginda olmak uzere satir ve sutun sayisini veriniz\n");
	scanf("%d %d",&row,&column);
	matrix=(float **) calloc (row,sizeof(int*));
	for (i=0;i<row;i++)
	{
		matrix[i]=(int*) calloc (column, sizeof(int));
	}
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			matrix[i][j]=i+(float)j/10;
			
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
			printf("%f  ",matrix[i][j]);
		printf("\n");
	}
	
	for (i=0;i<row;i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;		
}	
