#include <stdio.h>
int main()
{
	int mat[20][20][3],no,x,y,i,hastaNum,ambulansNum,hastanex,hastaney,uzaklik,xh,yh,n;
	float factor,maxfactor=0;
	printf("hasta koordinatlari x y?"); scanf("%d %d",&xh,&yh);
	printf("hastane sayisi?");			scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("hastane x y?"); scanf("%d %d",&x,&y);
		printf("hastane no?"); scanf("%d",&mat[x][y][0]);
		printf("hasta sayisi?"); scanf("%d",&mat[x][y][1]);
		printf("ambulans sayisi?"); scanf("%d",&mat[x][y][2]);
		uzaklik=(x-xh)*(x-xh)+(y-yh)*(y-yh);
		factor=(float)mat[x][y][2]/(mat[x][y][1]*uzaklik);
		if (factor>maxfactor)
		{
			maxfactor=factor;
			printf("%f",maxfactor);
			hastanex=x;
			hastaney=y;
		}
	}
	
	mat[hastanex][hastaney][1]++;
	mat[hastanex][hastaney][2]--;
	printf("hasta %d nolu hastaneye yerlestirildi\n",mat[hastanex][hastaney][0]);
	
}
