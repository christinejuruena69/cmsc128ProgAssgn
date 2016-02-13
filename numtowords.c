#include <stdio.h>
#include <math.h>
void hundthouf(int );
void dthouf(int );
void dthou1f(int );
void thouf(int );
void hundf(int );
void tensf(int );
void tens1f(int );
void onesf(int );

void main(){
	 int a,b,c,d,e;
	 int ones, tens, hund, thou, thou2, hthou, mil; 
	 long n;
	 printf("Enter the number: (Max. 5 digits) \n");
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

		  if(hthou!=0){
		  		hundthouf(hthou);
		  }

		  if(thou2==1) {
		  	dthou1f(thou);
		  }else{
			  dthouf(thou2);
			  thouf(thou);
		  }

		  hundf(hund);
		  
		  if(tens!=1){
			   tensf(tens);
			   onesf(ones);
		  }
		  if(tens==1){
		   		tens1f(ones);
		  }
	 }
	 else{
	 		printf("Number limit exceeded\n");
	 }
	// getch();
	}

//fxn for Hundreds
void hundthouf(int num){
	if(num!=0){
	 switch(num) {
	  case 1:  printf("One Hundred  ");
	  break;
	  case 2:  printf("Two Hundred  ");
	  break;  
	  case 3:  printf("Three Hundred  ");
	  break;
	  case 4:  printf("Four Hundred  ");
	  break;
	  case 5:  printf("Five Hundred  ");
	  break;
	  case 6:  printf("Six  Hundred  ");
	  break;
	  case 7:  printf("Seven Hundred  ");
	  break;
	  case 8:  printf("Eight Hundred  ");
	  break;
	  case 9:  printf("Nine Hundred ");
	  break;
	   
	  
	 }
	}
}
//fxn for -ty
void dthouf(int num){
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
//fxn for thousands
void dthou1f(int num){
	 switch(num) {

	 case 0: printf("Ten Thousand ");
  break;
	 case 1: printf("Eleven Thousand ");
  break;
	 case 2: printf("Twelve Thousand ");
  break;
	 case 3: printf("Thirteen Thousand ");
  break;
	 case 4: printf("Forteen Thousand ");
  break;
	 case 5: printf("Fivteen Thousand ");
  break;
	 case 6: printf("Sixteen Thousand ");
  break;
	 case 7: printf("Seventeen Thousand ");
  break;
	 case 8: printf("Eighteen Thousand ");
  break;
	 case 9: printf("Nineteen Thousand ");
  break;
  
	}
}

void thouf(int num){
 if(num!=0){
	 switch(num) {

	  case 1:  printf("One Thousand ");
  break;
	  case 2:  printf("Two Thousand ");
  break;
	  case 3:  printf("Three Thousand ");
  break;
	  case 4:  printf("Four Thousand ");
  break;
	  case 5:  printf("Five Thousand ");
  break;
	  case 6:  printf("Six Thousand ");
  break;
	  case 7:  printf("Seven Thousand ");
  break;
	  case 8:  printf("Eight Thousand ");
  break;
	  case 9:  printf("Nine Thousand ");
  break;
  
	 }
	}
}
void hundf(int num){
	 if(num!=0){
		 switch(num) {
	  case 1:   printf("One Hundred ");
  break;
	  case 2:  printf("Two Hundred ");
  break;
	  case 3:  printf("Three Hundred ");
  break;
	  case 4:  printf("Four Hundred ");
  break;
	  case 5:  printf("Five Hundred ");
  break;
	  case 6:  printf("Six Hundred ");
  break;
	  case 7:  printf("Seven Hundred ");
  break;
	  case 8:  printf("Eight Hundred ");
  break;
	  case 9:  printf("Nine Hundred ");
		break;
	  
	 }
	}
}
void tensf(int num){
 if(num!=0){
		 switch(num) {
	  case 2:  printf("Twenty ");
  break;
	  case 3:  printf("Thirty ");
  break;
	  case 4:  printf("Forty ");
  break;
	  case 5:  printf("Fifty ");
  break;
  break;
	  case 6:  printf("Sixty ");
  break;
  break;
	  case 7:  printf("Seventy ");
  break;
	  case 8:  printf("Eighty ");
  break;
	  case 9:  printf("Ninety ");
  break;
  
	 }
	}
}
void tens1f(int num){
	switch(num) {
		case 0: printf("Ten\n");
	  break;
			 case 1: printf("Eleven\n");
	  break;
			 case 2: printf("Twelve\n");
	  break;
			 case 3: printf("Thirteen\n");
	  break;
			 case 4: printf("Fourteen\n");
	  break;
			 case 5: printf("Fifteen\n");
	  break;
			 case 6: printf("Sixteen\n");
	  break;
			 case 7: printf("Seventeen\n");
	  break;
			 case 8: printf("Eighteen\n");
	  break;
			 case 9: printf("Nineteen\n");
	  break;
  
	}
}
void onesf(int num){

 if(num!=0){
	switch(num) {
		  case 1:  printf("One\n");
  break;
		  case 2:  printf("Two\n");
  break;
		  case 3:  printf("Three\n");
  break;
		  case 4:  printf("Four\n");
  break;
		  case 5:  printf("Five\n");
  break;
		  case 6:  printf("Six\n");
  break;
		  case 7:  printf("Seven\n");
  break;
		  case 8:  printf("Eight\n");
  break;
		  case 9:  printf("Nine\n");
  break;
  
	 }
	}
}