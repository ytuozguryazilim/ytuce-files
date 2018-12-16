#include <stddef.h>
#include <stdio.h> 
#define FAIL 0 
#define SUCCESS 1 
#define LINESIZE 100
int copyfileLinebyLine(char * infile, char * outfile)
{ 
	FILE *fp1, *fp2; 
	char line [LINESIZE] ; 
	int lineNum=0;
	if ((fp1 = fopen( infile, "r"  ))== NULL) return FAIL; 
	if ((fp2 = fopen( outfile, "w" )) == NULL)
	{ 
		fclose ( fp1 ); 
		return FAIL; 
	}
	while (fgets( line, LINESIZE, fp1 ) != NULL) 
	{
		fputs( line, fp2 ); 
		lineNum++;
	}
	fprintf(fp2,"dosyada %d line var\n",lineNum);
	fclose( fp1 ); 
	fclose( fp2 ); 
	return SUCCESS; 
}

int copyfileCharbyChar(char * infile, char * outfile)
{ 
	FILE *fp1, *fp2; 
	char ch,ch2; 
	int charNum=0;
	if ((fp1 = fopen( infile, "r"  ))== NULL) return FAIL; 
	if ((fp2 = fopen( outfile, "w" )) == NULL)   // w modda açýlsaydi ayni kopya bir daha olusurdu. a modda acilirsa altina yazar
	{ 
		fclose ( fp1 ); 
		return FAIL; 
	}
	fscanf(fp1,"%c",&ch2);					// burada tek char okundugu icin ikinci dosyaya ilk char yazilamaz
	ch=getc(fp1);						
	while (!feof(fp1))   //dosya sonu ise 1, degilse 0
	{
		putc(ch,fp2);   //or fputc(ch,fp2);
		ch=getc(fp1);   //or ch=fgetc(fp1); 
		charNum++;
	}

	fclose( fp1 ); 
	fprintf(fp2,"dosyada %d char var\n",charNum);
	fclose( fp2 ); 
	return SUCCESS; 
}

int main()
{
	char file1[20],file2[20];
	printf("input ve output dosyalarini veriniz\n");
	scanf("%s %s",file1,file2);
	if (copyfileLinebyLine(file1,file2)==SUCCESS) 
		printf("dosya line line kopyalandi\n");
	else
		printf("dosya kopyalanamadi\n");

	if (copyfileCharbyChar(file1,file2)==SUCCESS)
		printf("dosya char char kopyalandi\n");
	else
		printf("dosya kopyalanamadi\n");
	return 0;
}
