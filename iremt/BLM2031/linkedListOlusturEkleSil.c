#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void push(struct node *, int);
struct node * pushFront(struct node *, int);
void list(struct node *);
void deleteNode(struct node *, int);

int main()
{
	struct node *head, *newHead, *dummy;
	int num;
	head = malloc(sizeof(struct node));
	if (head == NULL) {
    	return 0;
	}	
	
	printf("listenin sonuna eklenmek uzere eleman veriniz\n");
    scanf("%d",&num);
	head->val = num;
	head->next = NULL;
	
	printf("listenin sonuna eklenmek uzere eleman veriniz\n");
    scanf("%d",&num);
	push(head,num);
	
	printf("listenin sonuna eklenmek uzere eleman veriniz\n");
    scanf("%d",&num);
	push(head,num);
	
	printf("listenin sonuna eklenmek uzere eleman veriniz\n");
    scanf("%d",&num);
	push(head,num);
	
	list(head);
	
	printf("listenin basina eklenmek uzere eleman veriniz\n");
    scanf("%d",&num);
	newHead=pushFront(head,num);
	list(newHead);
	
	printf("listeden silinecek elemani veriniz\n");
	scanf("%d",&num);
	if (num==newHead->val)
	{
		dummy=newHead->next;
		free(newHead);
		newHead=dummy;
	}
	else
		deleteNode(newHead,num);
	list(newHead);
	
	
	return 0;

}

// listenin sonuna node ekler
void push(struct node *head, int val) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));  	
    current->next->val = val;					
    current->next->next = NULL;					
}

// elemanlarý listeler
void list(struct node *head)
{
	struct node* current = head;
    printf("liste elemanlari:\n");
	while (current->next != NULL) {
    	printf("-%d-",current->val);
        current = current->next;
    }
    printf("-%d-\n",current->val);
}

// listenin baþýna node ekler
struct node* pushFront(struct node *head, int val) {
    struct node* newN;
	newN=malloc(sizeof(struct node)); 
	newN->next =head;
	newN->val =val;
    return newN;
}

// elemanlarý listeler
void deleteNode(struct node *head, int val)
{
	struct node* current = head, *before=NULL;
    
    while ((current->val != val)&&(current->next != NULL))
	{
	    before=current;
		current = current->next;
	}
    
    if (current->next == NULL)
    	printf("silinmek istenen eleman listede yok\n");
    else
    {
    	before->next=current->next;
    	free (current);
	}
        
}

