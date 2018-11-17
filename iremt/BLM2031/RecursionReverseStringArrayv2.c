#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Bir string dizisini ters çeviren recursive function 
void reverse(char **ar,int i,int n) 
{ 
   if (i<n) 
   { 
       reverse(ar,i+1,n); 
       printf("%s ", ar[i]); 
   } 
} 
  
int main() 
{ 
   char** a;
   int n,i,m; 
   char dummy[30];
   printf("kelime dizisinin eleman sayisini veriniz?");
   scanf("%d",&n);
   a=(char**) calloc (n,sizeof(char*));
   printf("elemanlari veriniz\n");
   for (i=0;i<n;i++)
   {
        scanf("%s",dummy); 
        m=strlen(dummy);
        a[i]=(char*) calloc (m+1,sizeof(char)); 
        strcpy(a[i],dummy);
        //tum bu iþlemler yerine a[i]=dummy deseydim olur muydu? 
	}
   reverse(a,0,n); 
   return 0; 
} 
