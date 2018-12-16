#include <stdio.h> 
#include <string.h>
#define TRUE 1
#define FALSE 0 

struct vitalstat
{ 
	char name [19] , ssnum[11];
	unsigned int vs_day: 5, vs_month : 4, vs_year : 11; 
	unsigned UScitizen : 1; /* Bit field for U.S. citizenship */
	union
	{ 	
		char nationality[20]; 
		char city_of_birth[20];
	}location;
};

int is_yes()
{ 
	char answer[64]; 
	while(1)
	{
		scanf("%s",answer);
		switch (answer[0]) 
		{ 
			case 'y': 
			case 'Y': return TRUE; 
			case 'n':
 			case 'N': 
			return FALSE; 
			default: printf( "Please answer Y or N\n");
		}
	}
}

int double_check( char *s)
{ 
	printf( "Is '%s' correct? (Y or N) ", s); 
	return is_yes(); 
}

void get_city_info( struct vitalstat *pvs) 
{
	int answered = FALSE; 
	printf("Are you a U.S. citizen? "); 
	pvs->UScitizen = is_yes(); 
	while (!answered) 
	if (!pvs->UScitizen)
	{ 
		printf("What is your nationality?"); 
		scanf("%s",pvs->location.nationality);
		answered = double_check( pvs->location.nationality); 
	}
	else /* UScitizen */ 
	{ 
		printf("Enter city of birth: "); 
		scanf("%s",pvs->location.city_of_birth);
		answered = double_check( pvs->location.city_of_birth ); 
	}
}

void write_person_info(struct vitalstat pvs) 
{
	printf("name surname:%s %s\n",pvs.name, pvs.ssnum);
	printf("day:%d %d %d\n",pvs.vs_day,pvs.vs_month,pvs.vs_year);
	if (pvs.UScitizen==1)	// This condition is redundant 
		printf("%s\n",pvs.location.city_of_birth);
	else
		printf("%s\n",pvs.location.nationality);


	// printf("%s\n",pvs.location.nationality);  /* or  */
	// printf("%s\n",pvs.location.city_of_birth);  /* is enough  */
	
}

int main()
{
	struct vitalstat person;
	int day,month,year;
	printf("give name and surname\n");
	scanf("%s %s",person.name,person.ssnum);
	printf("give date of birth\n");
	scanf("%d %d %d",&day,&month,&year);
	person.vs_day=day;
	person.vs_month=month;
	person.vs_year=year;
	get_city_info(&person);
	write_person_info(person);
	return 0;
}
