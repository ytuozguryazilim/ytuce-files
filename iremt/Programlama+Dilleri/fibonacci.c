// ilk n fibonacci sayýsýný bulan program
#include <stdio.h>
int main()
{
	int f1=1,f2=1,fn,i,n,f[50];
	printf("n sayisini veriniz\n");
	scanf("%d",&n);
	printf("%d %d ",f1,f2);
	/*dizisiz 3 deðiþkenli çözüm */
	for (i=3;i<=n;i++)
	{
		fn=f1+f2;
		printf("%d ",fn);
		f1=f2;
		f2=fn;
	}
	printf("dizili cozum:\n");
	/*dizili çözüm*/
	f[0]=f[1]=1;
	printf("%d %d ",f[0],f[1]);
	for (i=2;i<n;i++)
	{
		f[i]=f[i-1]+f[i-2];
		printf("%d ",f[i]);
	}
		
	return 0;
}
