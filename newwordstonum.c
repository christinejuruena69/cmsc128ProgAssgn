

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
int zerotonine ( char[] );
int checkty(char[]);



main(){
	nd *head=NULL	, *temp;
		
	char input[256],  inputcopy[256],  word[20],  result[20];;
	int jump, cnt, numofDigits;
	char delim, *a, * token;
	char wordcopy[20], tempword[20], dashed[20], prev[20];
	int numdash;

	 	// ------
	int i, cnter, num, j, dash, hundflag=0, thouflag=0, hundthouone=0;


		printf("enter words :  ");

		fgets(input, sizeof(input), stdin);
		input[ strlen(input) - 1 ] = '\0';
		strncpy ( inputcopy, input, 256);
		
		a = strtok (input," -");
		strncpy( word, a, 20);
		

		 while(a!=NULL	){
		 	//loops throught the words
		 	// strncpy( word, a, 20);
		 	if (strcmp (word, "thousand") == 0 ){
		 		//ignores the word "thousand" but sets its flag; does not insert something in the list
		 			thouflag =1;
		 	}
		 	else if( strcmp (word, "hundred") == 0){
					hundflag =1;
		 		//ignores the word "hundred" but sets its flag; does not insert something in the list

		 	}else if( strcmp (word, "million") == 0){
		 		//ignores the word "million" but sets its flag; does not insert something in the list		 	
		 	}else{
		 		//if word is not thousand, hundred or million, it finds it in the fucntion 
		 		// zero to nine and returns its equivalent digit 

		 		if (numofDigits>1)	hundthouone =1;
		 		num = zerotonine(word);
		 		if ( num == 66){
		 			 printf("Wrong input. enter again.\n");
		 			exit(0);
		 		}else if (num == 69) exit(0);
				insert(&head, temp, num);
				numofDigits++;	 			 			
		 	}

		 	a = strtok (NULL	, " -");
		 
		 if (a!= NULL	) {
		 	//takes note of the prev and current word
		  	strncpy ( prev, word, 20);	 	
		 	strncpy( word, a, 20);
		 }
		 	num =0;

		}

		//checks of the last word is thousand, hundred or million to add the zeroes
		if (( strcmp (word, "thousand") == 0 || strcmp (word, "hundred") == 0 || strcmp (word, "million") == 0  )
			 && a==NULL	){
			int a, times;
			if (strcmp (word, "thousand") == 0){
				if (hundflag ==1 && thouflag ==1  ){//three hundred thousand 
				//300000
				times =5;
				}else { // 326 000
					// three hundred twenty-six thousand
					 //22 0000
					//thirty thousand
					times = 3;
				}
				
				if ( checkty(prev) == 1){
					times = times +1;
				}
			}else if (strcmp (word, "hundred") == 0){
				// printf("hundred diri \n");
				times= 2;
			}else if (strcmp (word, "million") == 0){
				times = 6;
			}
			
			
			for (a = 0; a < times; a++){
				insert(&head, temp, 0);				
			}	 	
		}

		//checks of last word ends in -ty
		if ( checkty(word) == 1 ||  (checkty(word) == 1 && strcmp (prev, "hundred") == 0)){
			insert(&head, temp, 0);				
		}		
		display(head);
		printf("\n\n");			
		free(head);
	
}


//structure definition

int checkty(char word[]){
	if ( strcmp(word, "twenty") == 0 || 
		strcmp(word, "thirty") == 0 || 
		strcmp(word, "forty") == 0 	|| 
		strcmp(word, "fifty") == 0 || 
		strcmp(word, "sixty") == 0 || 
		strcmp(word, "seventy") == 0 || 
		strcmp(word, "eighty") == 0 || 
		strcmp(word, "ninety") == 0 ) {
		return 1;
	}else{
		return 0;
	}
}

//fucntion for all the words
int zerotonine ( char word[] ){
	if ( strcmp(word, "one") == 0 ){
		return 1;
	}else if ( strcmp(word, "two") == 0  || strcmp(word, "twenty") == 0 ){
		return 2;
	}else if ( strcmp(word, "three") == 0 || strcmp(word, "thirty") == 0){
		return 3;
	}else if ( strcmp(word, "four") == 0 || strcmp(word, "forty") == 0){
		return 4;
	}else if ( strcmp(word, "five") == 0 || strcmp(word, "fifty") == 0){
		return 5;
	}else if ( strcmp(word, "six") == 0 || strcmp(word, "sixty") == 0){
		return 6;
	}else if ( strcmp(word, "seven") == 0 || strcmp(word, "seventy") == 0){
		return 7;
	}else if ( strcmp(word, "eight") == 0 || strcmp(word, "eighty") == 0){
		return 8;
	}else if ( strcmp(word, "nine") == 0 || strcmp(word, "ninety") == 0){
		return 9;
	}else if ( strcmp(word, "eleven") == 0 ){
		return 11;
	}else if ( strcmp(word, "twelve") == 0 ){
		return 12;
	}else if ( strcmp(word, "thirteen") == 0 ){
		return 13;
	}else if ( strcmp(word, "fourteen") == 0 ){
		return 14;
	}else if ( strcmp(word, "fifteen") == 0 ){
		return 15;
	}else if ( strcmp(word, "sixteen") == 0 ){
		return 16;
	}else if ( strcmp(word, "seventeen") == 0 ){
		return 17;
	}else if ( strcmp(word, "eighteen") == 0 ){
		return 18;
	}else if ( strcmp(word, "nineteen") == 0 ){
		return 19;
	}else if ( strcmp(word, "0")==0){
		return 69;
	}else{
		return 66;
	}
}


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
	

	//prints contest while temp is not at the end of file
	while(temp!=NULL	){
		 printf("%d", temp->x);
		temp = temp->next;
	}
	putchar('\n');
}

//function for inserting at tend of the list
void insert(nd **pHead, nd *temp, char num){
	nd *p;
	p = (*pHead);
	temp = (nd *)malloc (sizeof(nd));
	temp->x = num;
	if((*pHead)==NULL	){
		(*pHead)=temp;				//for the initial node
		temp -> next = NULL	;
	}
	else {
			while ((p->next!=NULL	)) p = p->next;
			temp -> next = p -> next;			//for inserting at the middle/end of the list
			p -> next = temp;
	
	}		
}
