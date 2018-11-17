// 0 ve 1 lerden olusan bir matriste takip edilebilecek rotayi bulan program
// mat[][] -> 	1 1 0 0
//				0 1 1 1
//				0 0 0 1
//				0 0 0 1
// rota[]  ->	1 2 1 1 2 2
// Kullanilabilecek maximum oyun alani (row-1) * (col-1) olur
// Daha az kontrol ile cozulebilir

#include <stdio.h>
#define row 5
#define col 5
int main(void)
{
 int i,j,n,m,k,cikis=0;
 int mat[row][col],yol[20];
 do 
 {
 printf("Gezilecek matris boyutunu veriniz. Maximum satir ve sutun sayisi sirasiyla %d ve %d olabilir\n",row-1,col-1); 
 scanf("%d %d",&n,&m);
 } while (n>=row || m>=col);
  
 printf("matris elemanlari?\n"); 
 for (i=0;i<n;i++) 
	for (j=0;j<m;j++)  
        scanf("%d",&mat[i][j]);
 
 i=0; j=0; k=0;
 while (cikis==0)
 {
       if (mat[i+1][j]==1)
       {
          yol[k]=2;
          i++;
          k++;
       }
	   else
       		if (mat[i][j+1]==1)
       		{
          		yol[k]=1;
          		j++;
          		k++;
       		}
       		else
                cikis=1;
       
 }
printf("yol dizisi:\n");
for (i=0;i<k;i++) 
    printf("%d",yol[i]);
return 0;
}

