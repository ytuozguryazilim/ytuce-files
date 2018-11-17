// string dizisini Bubble sort ile sýralayan program
#include <stdio.h> 
#include <string.h> 
  
void swap(char *ar[], int i, int j) 
{ 
    char * temp; 
    temp=ar[i];
    ar[i]=ar[j];
    ar[j] = temp; 
} 

void swapV2(char** p1, char** p2) 
{ 
    char * temp; 
    temp=*p1;
    *p1=*p2;
    *p2 = temp; 
} 
  
// bubble sort fonksiyonu
void bubbleSort(char * arr[], int n) 
{ 
   int i, j;
   char *temp; 
   for (i = 0; i < n-1; i++)       
  
       for (j = 0; j < n-i-1; j++)  
           if (strcmp(arr[j],arr[j+1])==1)   //ilk kelime buyukse 1,eþitlerse 0, ikinci kelime buyukse -1
           {
              //swap(arr,j,j+1); // bu þekilde de kullanýlabilir
              swapV2(&arr[j],&arr[j+1]); 
              
          }
} 
  
// diziyi yazdýrmak icin kullanýlan fonksiyon
void printArray(char* arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%s ", arr[i]); 
    printf("\n");
    
} 
  
int main() 
{ 
    char* arr[5] = {"zarf", "mektup", "at", "haber", "bebek"}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printArray(arr, n); 
    
	bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
}
