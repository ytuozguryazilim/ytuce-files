// verilen bir paragraftaki küçük harflerin frekanslarýný bulan programý yazýnýz
#include <stdio.h>
int main()
{
	static int counter[26];
	int i,j,indis,sum=0,normalized;
	static char histmat[100][26];
	char text[100];
	printf("paragrafi giriniz\n");
	gets(text);
	i=0;
	while (text[i]!=0)
	{
		if ((text[i]<='z') && (text[i]>='a'))
		{
			indis=text[i]-'a';
			counter[indis]++;
		}
	i++;
	}
	for (i=0;i<26;i++)
	{
		printf("%c:%d\n",'a'+i,counter[i]);
		sum+=counter[i];
	}
	
	return 0;
}
