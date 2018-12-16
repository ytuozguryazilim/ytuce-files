#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 20

typedef struct vitalstat
{ 
 	char vs_name[NAME_LEN]; 
	char vs_ssnum[NAME_LEN]; 
	int vs_day;
	int vs_year;
	int vs_month;
} VITALSTAT; 

void printf_file(char filename[])
{
	int nb,i,day,month,year;
	VITALSTAT vs;
	FILE *fs=fopen (filename,"wb");
	if (fs==NULL)
	{
		printf("not opened\n");
		exit(0);
	}
	
	printf("kac kayit var\n");
	scanf("%d",&nb);
	printf("bilgilerini veriniz\n");
	for (i=0;i<nb;i++)
	{
		scanf("%s %s %d %d %d",vs.vs_name,vs.vs_ssnum, &vs.vs_day, &vs.vs_month, &vs.vs_year);
		fwrite (&vs,sizeof(VITALSTAT),1,fs);	
	}
	
	fclose(fs);
}

void list_file(FILE *fs)
{
	VITALSTAT vs;
	printf("kisi listesi:\n");
	fseek( fs, 0, SEEK_SET);
	fread(&vs,sizeof(VITALSTAT),1,fs);
	while(!feof(fs))	
	{
	printf("%s %s %d %d %d\n",vs.vs_name,vs.vs_ssnum, vs.vs_day, vs.vs_month, vs.vs_year);
	fread(&vs,sizeof(VITALSTAT),1,fs);
    }
}


int main()
{
	char filename[20];
	FILE *data_file; 
	int k=0,stat=0;
	long offset=0,boyut;
	VITALSTAT vs;
	printf("dosya ismini veriniz\n");
	scanf( "%s", filename ); 
	printf_file(filename);
	data_file = fopen( filename, "r+b" ); 
	if (data_file == NULL) 
	{ 
		printf( "Error opening file %s.\n", filename ); 
		exit ( 1 ); 
	}
 	
	list_file(data_file);
    
	printf("kacinci kisiye ulasmak istiyorsunuz? \n");
    scanf("%d",&k);
    offset=k*sizeof(VITALSTAT);
    stat=fseek( data_file, offset, SEEK_SET);
    fread(&vs,sizeof(VITALSTAT),1,data_file);
    printf("ilgili kisinin bilgileri:\n");
    printf("%s %s %d %d %d\n",vs.vs_name,vs.vs_ssnum, vs.vs_day, vs.vs_month, vs.vs_year);
    printf("yeni dogum yili?\n");
    scanf("%d",&vs.vs_year);
    stat=fseek( data_file, offset, SEEK_SET);  	//stat=fseek( data_file, -sizeof(VITALSTAT), SEEK_CUR);  
    fwrite(&vs,sizeof(VITALSTAT),1,data_file);
    list_file(data_file);
	
}
