

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node{
	int x;
	struct node *next;
}nd;
int count(const char*);

//function prototypes
void  insert(nd **, nd *, char);
void display(nd *);

main(){
	nd *head=NULL, *temp;
		
	char input[256];
	 int jump, cnt;
	 char delim;
	 char result[20];
	 char *a;

	 
	 printf("Enter number: ");
	 fgets(input, sizeof(input), stdin);
	 printf("Enter delmiter: ");
	 scanf("%c", &delim);
	 getchar();
	 printf("Enter character jumps: ");
	 scanf("%d", &jump);
	 cnt = count(input);
	 printf("cnt: %d ", cnt);
	 printf("jump: %d ", jump);


	int i;
	 for (i= 1; i<cnt+1; i++){
	 	printf("%c ", input[i-1] );
		insert(&head, temp, input[i-1]);
		printf("huy: %d, k %d\n", cnt-i , (cnt-i) % jump );
	   
	    if ((cnt-i) % jump == 0 && (i !=cnt) ){
	        insert(&head, temp, delim);
	    }
	    
	}
	display(head);
		
	free(head);
}


//structure definition


// 

int count(const char* str)
{
 int count = 0;
 while(*str)
 {
  if(!isspace(*str++))
   count++;
 }
 return count;
}

//displays the contents of the list
void display(nd *head){
	nd *temp = head;
	
	printf("\nThe contents are: ");

	//prints contest while temp is not at the end of file
	// while(temp->next != NULL ){
	
	while(temp!=NULL){
		printf("%c ", temp->x);
		temp = temp->next;
	}
	putchar('\n');
}

//function for inserting
void insert(nd **pHead, nd *temp, char num){
	nd *p;

	p = (*pHead);

	temp = (nd *)malloc (sizeof(nd));
	// printf("\nEnter integer to be inserted: ");
	// scanf("%d", &num);
	temp->x = num;

	if((*pHead)==NULL){
		(*pHead)=temp;				//for the initial node
		temp -> next = NULL;
	}

	else {
		
			while ((p->next!=NULL)) p = p->next;
			temp -> next = p -> next;			//for inserting at the middle/end of the list
			p -> next = temp;
	
	}		
}
