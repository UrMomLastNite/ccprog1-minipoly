/*
	Description: This program is a minimized and simpler version of the board game Minipoly using C language. 
	Programmed by: Dalrianne Francesca Togado - S21B
	Last modified: 12/5/2022
	Version: 16
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Togado_header.h"

// gcc -Wall -std=c99 Togado_Main.c functions.c -o main && main

int main ()
{
	// variable declarations
	
	int nChoice; 
	
	int arrSize = 20; 				// array size for player 1
	int arrSize2 = 20; 				// array size for player 2
	char bothPlayers[arrSize];
			
	int arrSize3 = 16; 				// array size for properties
	char bothProperties[arrSize3];
			
	int nMove; 						// input roll 

	do
	{
		for(int i = 0; i < 20; i++) 		// clears the bothPlayers array so no garbage value 
		{
			bothPlayers[i] = ' ';
		}
	
		for(int i = 0; i < 16; i++) 		// clears the bothProperties array so no garbage values
		{
			bothProperties[i] = ' ';
		}
	
			arrSize = 1; 					// starting point of the players
			arrSize2 = 1; 
			int forProperty; 				// for buyProperty and buyTile function 
			char yesNo; 					// for buyOrNot function
			
			float bankOne = 10000000.00;
			float bankTwo = 10000000.00;
			
			int nJail = 0;					// for Jail tile
			int nJail2;						// for Jail tile
			
			int oneBuySmth;					// becomes 1 if player 1 bought a property
			int twoBuySmth; 				// becomes 2 if player 2 bought a property
			
			int onePayRent;					// becomes 1 if player 1 paid rent
			int twoPayRent; 				// becomes 2 if player 2 paid rent
			
			int playOne = 1;                // player One's turn gets executed if this is equal to 1
			int playTwo = 1;				// player Two's turn gets executed if this is equal to 2
			
			int passGTile; 					// becomes 1 if player 1 passed by the Go Tile and 2 if player 2 passed by the Go tile 
						
			int isInJail = 5;				// becomes 0 if player 1 is not in jail and 1 if in jail 
			
			int isInJail2 = 5;				// becomes 0 if player 2 is not in jail and 1 if in jail
			
			int doubleJail;					// becomes 1 if both players went to jail
			
			int playerOne = 1;				// prints 1
			int playerTwo = 2;				// prints 2
			
			int noMoney = 0;				// becomes equal to 1 
		
		
		
		
		nChoice = displayTitleScreen();			// displays the title screen
		
	if (nChoice == 2 || nChoice == 1)
	{			
		do	
		 {	 					 	
			displayBoard (bothPlayers, bothProperties);	
				
				printf("Account Balance: \n");
				printf("Player 1: %.2f \n", bankOne);
				printf("Player 2: %.2f \n", bankTwo);
				printf("\n");

			/* 
				this gets executed if playOne is == 2 and nJail is equal to 0
				it also gets executed if nJail2 == 2 or 1 (means that player 2 is stalled for two turns)
			*/
		
			if ((playOne == 1 && nJail == 0) || nJail2 != 0)
			{															
				isInJail = 0;
				noMoney = 0;
				
				/*
					displays the movement of both players
				
				*/
				
				forPlayerOneTurn (arrSize, arrSize2, nJail2, 
					   doubleJail, nMove, forProperty, 
					   playerTwo, playerOne, nJail, 
					   passGTile, oneBuySmth, twoPayRent, 
					   twoBuySmth, onePayRent, isInJail2);      // displays player movement

		
				passGTile = 0;															// set back to 0 after printing player moves
				oneBuySmth = 0;															// sets this back to zero for new turn
				onePayRent = 0;		
							
				if (bothPlayers[arrSize] == '1')										// clears previous tile
					bothPlayers[arrSize] = ' ';
					
				else if (bothPlayers[arrSize] == '3')									// leaves 2 on the tile if both players were on the same tile
					bothPlayers[arrSize] = '2';
					
				bothPlayers[arrSize2] = '2';
				nMove = playOrDebug (nChoice, playerOne);
																	
				arrSize += nMove;														// calculates the new position of the player 
							
				if (arrSize > 20)
				{
					arrSize = arrSize - 20; 											// calculates the position of the player and subtracts it with 20 if it arrSize exceeds 20
					
					bankOne = gTile(bankOne);
					
					if (bothPlayers[arrSize] == '2')
						bothPlayers[arrSize] = '3';
					else
						bothPlayers[arrSize] = '1';	
															
					passGTile = 1;											// becomes == 1 if player 1 passed by G Tile
				}
				
				else 																	// places '1' on the tile player One landed
				{ 
					if (bothPlayers[arrSize] == '2')
						bothPlayers[arrSize] = '3';
					else 
						bothPlayers[arrSize] = '1';										// leaves '1' on the tile 
				}
				
				displayBoard (bothPlayers, bothProperties);			// displays the board
				
									// places 2 on the G tile after the first turn
												
				forProperty = buyProperty(arrSize); 										// to check which side of the board the player landed on
				
				arrSize3 = markProperty(forProperty, arrSize);								// calculates the array size of the bothProperties array
				
				
				if ((arrSize >= 2 && arrSize <=5) || (arrSize >= 7 && arrSize <= 10) ||       // checks the if the tile player one landed on is a property that can be bought
					(arrSize >= 12 && arrSize <= 15) || arrSize == 17 || arrSize == 18 
					|| arrSize == 20)
					{					
						if (bothProperties[arrSize3] == ' ')								 // checks if the property is unowned
						{											
							yesNo = buyOrNot (yesNo, bankOne, playerOne, forProperty);					// asks the player if they want to buy the property
					
							if (yesNo == 'y' || yesNo == 'Y')								// if player says "yes", the tile is marked with 'X'
							{	
								noMoney = cannotBuy (forProperty, bankOne);		
								
								if (noMoney == 1)
									printf("Invalid purchase. Not enough money.\n");
									
								else 
								{
									bankOne = buyTile(bankOne, forProperty);
																						
									bothProperties[arrSize3] = 'X';
								
									oneBuySmth = 1;								// gets the value of '1' if player one buys a property
								}
																			
							}			
						}
						else if (bothProperties[arrSize3] == 'Y') 							// checks if tile is owned already  
						{
							bankOne = payRent (bankOne, forProperty);						// player 1 pays rent
							bankTwo = getRent (bankTwo, forProperty);						// player 2 receives rent
							
							onePayRent = 1;													// becomes == 1 if player 1 paid rent
						}
						
			 		}
			 	else if (arrSize == 16 || arrSize == 19)									// gets executed if player lands on T or J tile
			 		{
			 			if (arrSize == 19)
			 				bankOne = getTax(bankOne);										// landing on T tile subtracts 1,000,000 from bank account
			 			else if (arrSize == 16)
			 			{	
			 				bothPlayers[16] = ' ';
			 				arrSize = 6;
			 				bothPlayers[arrSize] = '1';										// player gets moved to V tile and is stalled for the next two turns
			 						if (arrSize2 == 6)
			 					{
			 						bothPlayers[arrSize] = '3';
								}
								
			 				nJail = 2;														// nJail is given the value of 2
			 				isInJail = 1;													// becomes 1 if player 1 went to  jail
						}
							
					}

				if (nJail == 0 && nJail2 == 0)								// if there are no players in jail playTwo is set to 2 to execute player two's turn 
					{
						playOne = 0;
						playTwo = 2;
					}
					else if (nJail2 == 2)
						{
							if (nJail == 0)								 // if player two is in jail but one isn't , 1 is sbutracted from nJail2 then playOne is set to 1 to execute their turn
								{
									nJail2--;
									playTwo = 0;
									playOne = 1;
								}
						}
					else if (nJail2 == 1)								// player 2 is stalled for another turn
						{
							nJail2--;
							playTwo = 0;
							playOne = 1;
						}
					else if (nJail2 == 0)								// player two can finally roll again
						{
							playTwo = 2;
							playOne = 0;
						}
						
			doubleJail = 0;												// is set back to zero once both players are out of jail
					
			} // player one's turn
			
			
			/* 
				this gets executed if playTwo == 2 and nJail2 is equal == 0
				it also gets executed if nJail == 2 or 1 (means that player 1 is stalled for two turns)
			*/
						
			else if ((playTwo == 2 && nJail2 == 0) || nJail != 0)
			{
				isInJail2 = 0;										// set back to 0
				noMoney = 0;
				
				forPlayerTwoTurn (isInJail, nJail, nJail2, doubleJail, 
					   nMove, arrSize, arrSize2, playerOne, 
					   playerTwo, forProperty, passGTile, 
					   oneBuySmth, onePayRent, twoBuySmth, twoPayRent);
				
				passGTile = 0;										// set back to 0 after printing player moves
				twoBuySmth = 0;										// clears all Values
				twoPayRent = 0;
				
			
				if (bothPlayers[arrSize2] == '2')											// clears previous tiles
					bothPlayers[arrSize2] = ' '; 
					
				else if (bothPlayers[arrSize2] == '3')										// leaves 1 on the tile if both players were on the same tile
					bothPlayers[arrSize2] = '1'; 
						
				nMove = playOrDebug (nChoice, playerTwo);
			
				arrSize2 += nMove;															// caclulates new position of the player
				
				if (arrSize2 > 20)															// calculates new position of the tile and subtracts 20 if arrsize2 exceeds 20
				{
							
					arrSize2 = arrSize2 - 20; 
					
					bankTwo = gTile(bankTwo);
					
					
					
					if (bothPlayers[arrSize2] == '1')
						bothPlayers[arrSize2] = '3';
					else
						bothPlayers[arrSize2] = '2';	
						
					passGTile = 2;							// becomes == 2 if player 2 passed by G Tile	
									
				}
				
				else 																		// places 2 on the tile player 2 landed on 
				{ 
					if (bothPlayers[arrSize2] == '1')
						bothPlayers[arrSize2] = '3';
					else 
						bothPlayers[arrSize2] = '2';
				}	
				
					
				
				forProperty = buyProperty(arrSize2); 										// to check which side of the board the player landed on
				
				arrSize3 = markProperty(forProperty, arrSize2);								// calculates the array size of the bothProperties array
				
			
				
				if ((arrSize2 >= 2 && arrSize2 <=5) || (arrSize2 >= 7 && arrSize2 <= 10) ||       // checks the if the tile player one landed on is a property that can be bought
						(arrSize2 >= 12 && arrSize2 <= 15) || arrSize2 == 17 || arrSize2 == 18 
						|| arrSize2 == 20)
					{					
						if (bothProperties[arrSize3] == ' ')								 // checks if the property is unowned
						{			
							displayBoard (bothPlayers, bothProperties);						// displays updated board
										
								yesNo = buyOrNot (yesNo, bankTwo, playerTwo, forProperty);					// asks the player if they want to buy the property
					
							if (yesNo == 'y' || yesNo == 'Y')								// if player says "yes", the tile is marked with 'X'
							{
								noMoney = cannotBuy (forProperty, bankTwo);
								
								if (noMoney == 1)
									printf("Invalid purchase. Not enough money.\n");
								
								else 
								{
									bankTwo = buyTile(bankTwo, forProperty);
								
									bothProperties[arrSize3] = 'Y';
								
									twoBuySmth = 2; 											// is given the value of 2 if player 2 buys a property
								}
								
							}			
						}
						else if (bothProperties[arrSize3] == 'X') 							// checks if tile is owned already  
						{	
							
							bankTwo = payRent (bankTwo, forProperty);
							bankOne = getRent (bankOne, forProperty);
							
							twoPayRent = 2;													// becomes == 2 if player 2 paid rent
						}
						
			 		}
			 	else if (arrSize2 == 16 || arrSize2 == 19)
			 		{
			 			if (arrSize2 == 19)
			 				bankTwo = getTax(bankTwo);										// gets tax
			 			else if (arrSize2 == 16)
			 			{	
			 				bothPlayers[16] = ' ';										// J tile becomes empty
			 				arrSize2 = 6;
			 				bothPlayers[arrSize2] = '2';								// player is transferred to V tile
			 					if (arrSize == 6)
			 					{
			 						bothPlayers[arrSize2] = '3';
								}
			 				nJail2 = 2;									// if nJail2 == 0, it means player two is in jail and stalled for two turns 
			 				isInJail2 = 2;								// becomes == 2 if player 2 went to jail
						}
					}
				
					if (nJail == 0 && nJail2 == 0)						// if there are no players in jail, playOne is set two 1 which execites player one's turn 
					{
						playTwo = 0;
						playOne = 1;
					}				
					else if (nJail == 2)
						{
							if (nJail2 == 0)							// if player one is in jail but player two isnt, 1 is subtracted from nJail and playTwo is set to 2 which executes player 2's turn
							{
								nJail--;
								playOne = 0;
								playTwo = 2;
							}
						}
					else if (nJail == 1)					// if nJail is == 1 , 1 is subtracted again from nJail
					{
							nJail--;
							playOne = 0;
							playTwo = 2;
					}
					else if (nJail == 0)					// if player one is finally out of jail playOne is set to 1 to execute their turn
					{
						playOne = 1;
						playTwo = 0;
					}
					
				doubleJail = 0;
				
				} // if for else 
				
				
					if (nJail == 2 && nJail2 == 2)
						{
							if (playOne == 1 && playTwo == 0)				// player two first got into jail before player one 
								{
									nJail2 = 0;
									nJail = 0;
									playTwo = 2;			// everything is set back to normal; next turn is player two's turn
									playOne = 0;
									doubleJail = 1;			// becomes == 1 because both players are in jail
								}
							else if (playTwo == 2 && playOne == 0)			// player one first got into jail before player two 
								{
									nJail = 0;
									nJail2 = 0;	
									playOne = 1;			// everything is set back to normal; next turn is player one's turn
									playTwo = 0;
									doubleJail = 1;			// becomes == 1 because both players are in jail
								}		
						}
			
		 			   
				

			}  while (bankOne > 0 && bankTwo > 0); // do while bracket
			
			displayBoard (bothPlayers, bothProperties);					// prints the final board
				
				printf("Account Balance: \n");
				printf("Player 1: %.2f \n", bankOne);
				printf("Player 2: %.2f \n", bankTwo);
				printf("\n");
				
				
				if ((playOne == 1 && nJail == 0) || nJail2 != 0)
				{
						forPlayerOneTurn (arrSize, arrSize2, nJail2, 
					   doubleJail, nMove, forProperty, 
					   playerTwo, playerOne, nJail, 
					   passGTile, oneBuySmth, twoPayRent, 
					   twoBuySmth, onePayRent, isInJail2);
				}
			 
				else if (((playTwo == 2 && nJail2 == 0) || nJail != 0))
				{
				 	forPlayerTwoTurn (isInJail, nJail, nJail2, doubleJail, 
					   nMove, arrSize, arrSize2, playerOne, 
					   playerTwo, forProperty, passGTile, 
					   oneBuySmth, onePayRent, twoBuySmth, twoPayRent);
				}			
		
			if (bankTwo <= 0)
				printf("Player 2 has no more money left. Player 1 wins! \n");
				
			else if (bankOne <= 0)
				printf("Player 1 has no more money left. Player 2 wins! \n");
				
		} // else if bracket 
				
	} while (nChoice == 2 || nChoice == 1);
	

	return 0; 
}
