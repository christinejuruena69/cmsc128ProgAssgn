#include "library.h"

int main(){
	int choice, x,i;
	
	while((choice=menu())!=0){
		switch(choice){
			case 1: numtowordsmain();
			break;
			case 2: wordstonummain();
			break;
			case 3: wordstocurrmain();
			break;
			case 4: delimmain();
			break;
		}

	}
}

int menu(){
	int choice;
	printf("\n   MENU     ");
	printf("\n[1] - numToWords ");
	printf("\n[2] - wordsToNum");
	printf("\n[3] - wordsToCurrency");
	printf("\n[4] - numberDelimited");
	printf("\n[0] - EXIT");

	printf("\nYour choice: ");
	scanf("%d",&choice);
	return choice;
}
