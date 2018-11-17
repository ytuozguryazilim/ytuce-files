#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "image_processing.cpp"
void rotateright(int **matrix, int m, int n);
void rotatedown(int **matrix, int m, int n);
int main(void){
	//Verilen isimdeki resim okunuyor.
	int M, N, Q;
    bool type;
    char resimadi[] = "lenasp.pgm";
	readImageHeader(resimadi, N, M,Q, type);
	int** matrix = resimOku(resimadi); 
	int** matrix2 = resimOku(resimadi); 
	//Okuma bitti
	int m=M,n=N;
	
    rotateright(matrix,m,n);
	char yeniresimadi[] = "Soru1_sag.pgm";
	
	resimYaz(yeniresimadi, matrix, M, N, Q);
	printf("Islem-1 basariyla tamamlandi :)\n");
	
	rotatedown(matrix2,m,n);
	char yeniresimadi2[] = "Soru1_alt.pgm";
	
	resimYaz(yeniresimadi2, matrix2, M, N, Q);
	printf("Islem-2 basariyla tamamlandi :)\n");
	
	system("PAUSE");
	return 0;
}

void rotateright(int **matrix, int m, int n){
	int i,j,tmp;
	for(i=0;i<n;i++)  {
		for(j=0;j<m/2;j++)  {
			tmp=matrix[i][m-1-j];
			matrix[i][m-1-j]=matrix[i][j];
			matrix[i][j]=tmp;
		}
	}
}

void rotatedown(int **matrix, int m, int n){
	int i,j,tmp;
	for(i=0;i<n/2;i++)  {
		for(j=0;j<m;j++)  {
			tmp=matrix[i][j];
			matrix[i][j]=matrix[m-1-i][n-1-j];
			matrix[m-1-i][n-1-j]=tmp;
		}
	}
}

