
/*
Author: Christine Mae Juruena
Date Created: Feb 12, 2015
Description: This program accepts a whole number from zero (0) to 1 million 
(1000000; without commas for example: 1,000,000) and prints on screen the 
number in word form
SAMPLE INPUT: 1234
output:   one  thousand  two 
hundred thirty four
*/

#include <stdio.h>
#include <math.h>
void ty(int );
void tens1f(int );
void onesf(int );

void numtowordsmain(){
	 int a,b,c,d,e;
	 int ones=66, tens=66, hund=66, thou=66, thou2=66, hthou=66, mil=66; 
	 int n;
	 printf("Enter the number: (Max. 1000000 / one million) \n");
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
			  printf("diri\n");

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

//fxn for Hundreds

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