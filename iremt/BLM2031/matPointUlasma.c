#include <stdio.h>
int main()
{
	int i,j,*p;
	int ar[2][3]={{0,1,2},{3,4,5}};
	for (i=0;i<2;i++)
		for (j=0;j<3;j++)
	printf("value:%d valuev2:%d\n", *(*(ar+i)+j) , *((int*)ar+i*3+j  )  );
    
	for (i=0;i<2;i++)
		for (j=0;j<3;j++)
		printf("adre:%p value:%d\n",&ar[i][j],ar[i][j]);
    
    p=(int *)*ar; //p=(int *)ar; ayni sonucu verir
    for (i=0;i<6;i++)
	printf("adre:%p pvalue:%d\n",p+i,*(p+i));
	
	for (i=0;i<2;i++)
		for (j=0;j<3;j++)
			printf("1:%d 2:%d 3:%d 4:%d 5:%d\n",ar[i][j],*(ar[i]+j),*(*(&ar[0]+i)+j),*(*(ar+i)+j), *((int *)ar+i*3+j) );
	
	printf("%d %d %d %d\n",ar[1][2],*(ar[1]+2),*(*(ar+1)+2), *((int *)ar+1*3+2 ));
	printf("%p %p %p %d",ar,ar[0],&ar[0][0],ar[0][0]);
	
	
	return 0;
}
