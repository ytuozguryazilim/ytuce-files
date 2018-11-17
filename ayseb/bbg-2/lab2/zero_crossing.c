#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

int getSign(int data);

int main()
{
int i, sign1, sign2;

int zero_crossing[n];
time_t t;

/* Intializes random number generator */
    srand((unsigned) time(&t));
   /* Print 10 random numbers from -25 to 25 */
   for( i = 0 ; i < n ; i++ ) {
	/* +25 -0 - (-25) = 51 */
       zero_crossing[i] = rand() % 51 - 25;
       printf("%d, ", zero_crossing[i]);
   }
    printf("\n");

    //5, -2, 8, 9
    for(i=0; i<n-1; i++)     /* loop over data  */
	{
		sign1 = getSign(zero_crossing[i]);
		sign2 = getSign(zero_crossing[i+1]);
		if(sign1!=sign2)  /* set zero crossing location */
			printf("%d, %d noktalarında zero crossing olusmustur: %d, %d\n", i, (i+1), zero_crossing[i], zero_crossing[i+1]);
 }  
   return(0);

}
int getSign(int data)
{
    if(data>0)      /* positive data */
        return (1);
    else            /* negative data */
        return (0);
}
