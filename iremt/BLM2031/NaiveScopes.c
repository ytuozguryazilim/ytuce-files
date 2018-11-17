#include <stdio.h>
int i=15;					//Program Scope
static int j=3;					//File Scope
void funkA (void);
void printfi();
void fixDuration();

int main ()
{
	int k=5, i;				//Block Scope - the value of global i is protected
	for (i=0;i<3;i++)
	{	
		k++;
		goto printAgain;
	}

	printAgain:					//Function Scope
	printf("%d %d %d\n",i,j,k);
	
	
	funkA();
	//printfi();
	
	fixDuration();
	fixDuration();


}

void funkA ()
{
	int k=10,i;					//Block Scope
	for (i=0;i<3;i++)
	{	
		int a=4;
		printf("funka-k:%d -a:%d  -i:%d\n",k,a,i);
		printfi();
	}
	// illegal
	/*				
	if (a==4)					
		printf("esit");
	*/
}

void printfi()
{
	printf("i with program scope:%d\n",i);	//the value of global i is protected
}

void fixDuration()
{
	static int fix=2;
	fix++;
	printf("fix:%d\n",fix);
}
