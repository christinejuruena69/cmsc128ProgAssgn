/*
Author: Christine Mae Juruena
Date Created: Feb 12, 2015
Description: Accepts three arguments: the first is the number from zero to 1 miliion, the 
second is the delimiter to be used (single character only) and third, the 
number of jumps when the delimiter will appear (from right most going to left most digit).
sample input: 
1234
,
3 
output:  1,234
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>


typedef struct node{
	int x;
	struct node *next;
}nd;
int count(const char*);

//function prototypes
//delims
void  insert(nd **, nd *, char);
void display(nd *);

// wordstocurr
int zerotonine ( char[] );
int checkty(char[]);

//numtowords
void ty(int );
void tens1f(int );
void onesf(int );

//wordstonum
void deletenode(nd **);
int getlast(nd ** );

// main fxns
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delimmain(){
	nd *head=NULL, *temp;
		
	char input[256];
	 int jump, cnt;
	 char delim;
	 char result[20];
	 char *a;

	 
	 printf("Enter number: ");
	 fgets(input, sizeof(input), stdin); //gets the input 
	 // getchar();
	 printf("Enter delmiter: ");
	 scanf("%c", &delim);
	 // getchar();
	 printf("Enter character jumps: ");
	 scanf("%d", &jump);
	 cnt = count(input); //counts number of charcters
	 
	int i;
	 for (i= 1; i<cnt+1; i++){ //itirates thru the characrters of the input
		insert(&head, temp, input[i-1]);
	   
	    if ((cnt-i) % jump == 0 && (i !=cnt) ){ //cnt%jump will give the place of where the delimiter will be placed
	        insert(&head, temp, delim);
	    }
	    
	}
	printf("Result: \n");
	display(head);
		
	free(head);
	printf("\n\n");
}


void wordstocurrmain(){
	nd *head=NULL, *temp;
		
	char input[256],  inputcopy[256],  word[20],  result[20];;
	int jump, cnt, numofDigits;
	char delim, *a, * token;
	char wordcopy[20], tempword[20], dashed[20], prev[20], currency[10];
	int numdash;

	 	// ------
	int i, cnter, num, j, dash, hundflag=0, thouflag=0, hundthouone=0;


		printf("enter words :  ");

		fgets(input, sizeof(input), stdin);
		
		// int c;
// while ( (c==getchar()) != EOF && c != '\n') { }

		input[ strlen(input) - 1 ] = '\0';
		strncpy ( inputcopy, input, 256);
		printf("enter currency (JPY, UsD, PHP): ");
		fgets(currency, sizeof(currency), stdin);
		currency[ strlen(currency) - 1 ] = '\0';
		printf("%s ", currency );

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


void numtowordsmain(){
	 int a,b,c,d,e;
	 int ones=66, tens=66, hund=66, thou=66, thou2=66, hthou=66, mil=66; 
	 int n;
	 printf("Enter the number without comma or space: (Max. 1000000 / One Million digits) \n");
	 scanf("%d",&n);
	 if(n<=1000000){
	 	//modulo gives the rightmost number. we will start to divide the input number with the ones place
	 	// to check if the number has a result. that is, it is != null. 
	 	//if the number is less than 1, the result will be zero
	 		ones=n%10;
		  n=n/10;
		  tens=n%10;
		  n=n/10;
		  hund=n%10;
		  n=n/10;
		  thou=n%10;
		  n=n/10;
		  thou2=n%10; 
		  n=n/10;
		  hthou=n%10; 
		  n=n/10;
		  mil=n%10; 
		  if (mil == 1 && ( ones == 0 && tens == 0 && hund == 0 && thou == 0 && thou2 == 0  && hthou == 0  )){
  				//filters if equals to 1 million 
  				printf("One Million");
  				exit(0);
		  }else if( mil != 0 && ( ones != 0 || tens != 0 || hund != 0 || thou != 0 || thou2 != 0  || hthou != 0  )){
	 				//checks if number exceeded the proper input 
		  	printf("Number limit exceeded\n");

		  }

		  if(hthou!=66 && hthou!=0){
			   onesf(hthou);
			   printf("Hundred ");
		  }

		  if(thou2==1) {
		  	tens1f(thou);
			   printf("Thousand ");		  	
		  }else{
			  ty(thou2);
			  onesf(thou);
			  printf("Thousand ");
		  }

		  if (hund!=66 && hund!=0){
			  onesf(hund);
				printf("Hundred ");	  	
		  }

		  if(tens!=1){
			   ty(tens);
			   onesf(ones);
		  }
		  if(tens==1){
		   		tens1f(ones);
		  }else if ( tens == 0){

		  }
	 }
	 else{
	 		printf("Number limit exceeded\n");
	 }
	// getch();
	}


void wordstonummain(){

	nd *head=NULL, *temp;
		
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
				times= 2;
			}else if (strcmp (word, "million") == 0){
				times = 6;
			}
			
			
			for (a = 0; a < times; a++){
				insert(&head, temp, 0);	
				numofDigits++;	 			 										
			}	 	
		}
		//checks of 1001 801 or the like, if the number has zeroes between it
		if ( strcmp (prev, "hundred") == 0 || strcmp (prev, "thousand") == 0 ){
			int b, x, tempnum;
			tempnum = getlast(&head);

			deletenode(&head);
			if (strcmp (prev, "thousand") == 0 ) x=2;
		 	if (strcmp (prev, "hundred") == 0 ) x=1;
		 	for (b= 0;b < x; b++){
				insert(&head, temp, 0);
				numofDigits++;	 			 			
		 	}	
			insert(&head, temp, tempnum);	
		}
		//checks of last word ends in -ty
		if ( checkty(word) == 1 ||  (checkty(word) == 1 && strcmp (prev, "hundred") == 0)){
			insert(&head, temp, 0);	
			numofDigits++;	 			 			
		}		
		display(head);
		printf("\n\n");			
		free(head);
	
}
// function for the main stuff
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//delims fxns
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

//wordstocurr fxns
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

//numtowrds fxns
//fxn for -ty
void ty(int num){
	 switch(num) {
	 case 2: printf("Twenty ");
  break;
	 case 3: printf("Thirty ");
  break;
	 case 4: printf("Forty ");
  break;
	 case 5: printf("Fifty ");
  break;
	 case 6: printf("Sixty ");
  break;
	 case 7: printf("Seventy ");
  break;
	 case 8: printf("Eighty ");
  break;
	 case 9: printf("Ninety ");
  break;
  
	}
}


void tens1f(int num){
	switch(num) {
		case 0: printf("Ten ");
	  break;
			 case 1: printf("Eleven ");
	  break;
			 case 2: printf("Twelve ");
	  break;
			 case 3: printf("Thirteen ");
	  break;
			 case 4: printf("Fourteen ");
	  break;
			 case 5: printf("Fifteen ");
	  break;
			 case 6: printf("Sixteen ");
	  break;
			 case 7: printf("Seventeen ");
	  break;
			 case 8: printf("Eighteen ");
	  break;
			 case 9: printf("Nineteen ");
	  break;
  
	}
}
void onesf(int num){

 if(num!=0){
	switch(num) {
		  case 1:  printf("One ");
  break;
		  case 2:  printf("Two ");
  break;
		  case 3:  printf("Three ");
  break;
		  case 4:  printf("Four ");
  break;
		  case 5:  printf("Five ");
  break;
		  case 6:  printf("Six ");
  break;
		  case 7:  printf("Seven ");
  break;
		  case 8:  printf("Eight ");
  break;
		  case 9:  printf("Nine ");
  break;
  
	 }
	}
}

//words to num fxns
void deletenode(nd ** pHead)
{
    nd * prev = NULL;
    nd * current = *pHead;

    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    free (current);

    if (prev != NULL)
    {
        prev->next = NULL;
    }
}

int getlast(nd ** pHead)
{
    nd * prev = NULL;
    nd * current = *pHead;

    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    return current->x;
}
