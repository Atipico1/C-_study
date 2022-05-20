#include <stdio.h>
#include "TicTacToe.h"

int main()
{
	#define COMPUTER 1 
	#define HUMAN 2
	#define LENG 3
	TicTacToe TicTacToe;
	printf("\n---------------------------------------------------\n\n");
	printf("\t\t\t Tic-Tac-Toe\n"); 
	printf("\n---------------------------------------------------\n\n");
	char cont='y';
	do {

		char choice;
	 	printf("Do you want to start first?(y/n) : ");
	 	scanf(" %c", &choice);
		
        if(choice=='n')
			TicTacToe.playTicTacToe(COMPUTER);
		else if(choice=='y')
			TicTacToe.playTicTacToe(HUMAN);
		else
			printf("Invalid choice\n"); 
        
		printf("\nDo you want to quit?(y/n) : ");
       		scanf(" %c", &cont);
	} while(cont=='n');
	return (0); 
}