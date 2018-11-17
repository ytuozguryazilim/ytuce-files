#include <stdio.h>
#define MAX 50
void rotateright(int matrix[][MAX], int m, int n);
void matrisWrite(int matrix[][MAX], int m, int n);
void rotatedown(int matrix[][MAX], int m, int n);
int matrix[MAX][MAX];
int main(void){
	//Verilen isimdeki resim okunuyor.
	int m, n, i,j,k=0;
	printf("M ve N giriniz");
	scanf("%d %d",&m,&n);
	
	//grup1 ve 2
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matrix[i][j]=k++;
		}
	}
    //grup1 ve 2
	printf("\n Mirror Oncesi\n");
	matrisWrite(matrix,m,n);
	
	//Grup-1
    
	rotateright(matrix,m,n);
	printf("\n Saga Mirror Sonrasi\n");
	matrisWrite(matrix,m,n);
	
	// Grup-2
    
	rotatedown(matrix,m,n);
	printf("\n Asagi Mirror Sonrasi\n");
	matrisWrite(matrix,m,n);

	return 0;
}

void matrisWrite(int matrix[][MAX], int m, int n){ //grup1 ve 2
	int i,j;
	for(i=0;i<m;i++)  {
		for(j=0;j<n;j++)  {
			printf("%d  ",matrix[i][j]);
		}
		printf("\n");
	}
}

void rotateright(int matrix[][MAX], int m, int n){  //grup1 
	int i,j,tmp;
	for(i=0;i<n;i++)  {
		for(j=0;j<m/2;j++)  {
			tmp=matrix[i][m-j];
			matrix[i][m-j]=matrix[i][j];
			matrix[i][j]=tmp;
            
		}
	}
}

void rotatedown(int matrix[][MAX], int m, int n){ //grup 2
	int i,j,tmp;
	for(i=0;i<m/2;i++)  {
		for(j=0;j<n;j++)  {
			tmp=matrix[i][j];
			matrix[i][j]=matrix[m-1-i][j];
			matrix[m-1-i][j]=tmp;
		}
	}
}

