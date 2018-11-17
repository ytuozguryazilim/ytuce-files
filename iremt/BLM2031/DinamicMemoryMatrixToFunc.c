// Dynamic Memory Allocation and functions
#include <stdio.h>
#include <stdlib.h>
float **yerAc(int, int);
void Doldur(float **,int,int);
int main()
{		
	int row,column,i,j;
	float **matrix,*p;
	printf("1-9 araliginda olmak uzere satir ve sutun sayisini veriniz\n");
	scanf("%d %d",&row,&column);
	
	matrix=yerAc(row,column);
	Doldur(matrix,row,column);
				
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

float ** yerAc(int row, int column)
{
	int i;
	float ** matrix;
	matrix=(float **) calloc (row,sizeof(float*));
	for (i=0;i<row;i++)
	{
		matrix[i]=(float*) calloc (column, sizeof(float));
	}
	return matrix;
}

void Doldur (float** matrix,int row, int column)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			matrix[i][j]=i+(float)j/10;
			// *(*(matrix+i)+j)=i+(float)j/10;   //boyutlar bilindigi icin bu kullanim da LEGAL
			//*((float *)matrix+i*column+j)=i+(float)j/10;  //dinamik memory allocation ile elemanlar iteratif yerleþmeyebileceði için bu kullaným ILLEGAL
}
