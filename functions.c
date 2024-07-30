#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Togado_header.h"

/*
	This function displays the Minipoly board.
	@param *bothPlayers - array of both players, displays 1 and 2 on the board
	@param *bothProperties - array of both properties, displays 'X' and 'Y' on the board
	@return - no return
*/ 

void displayBoard (char *bothPlayers, char *bothProperties)
{
		printf("\n");
			printf("       e   f   g   h\n");
			printf(" +---+---+---+---+---+---+"); 
			printf("\n"); 
			printf(" |%c V|%c %c|%c %c|%c %c|%c %c|%c P| ",
				bothPlayers[6],  bothPlayers[7], bothProperties[5], bothPlayers[8], bothProperties[6], bothPlayers[9], bothProperties[7],
				bothPlayers[10], bothProperties[8], bothPlayers[11]);
				
			printf("\n");
			printf(" +---+---+---+---+---+---+"); 
			printf("\n");
			
			printf("d|%c %c|\t\t     |%c %c|i",
				bothPlayers[5], bothProperties[4], bothPlayers[12], bothProperties[9]);
			
			printf("\n");
			printf(" +---+               +---+"); 
			printf("\n");
			
			printf("c|%c %c|\t\t     |%c %c|j",
				bothPlayers[4], bothProperties[3], bothPlayers[13], bothProperties[10]);
				
			printf("\n");
			printf(" +---+               +---+"); 
			printf("\n");
			
			printf("b|%c %c|\t\t     |%c %c|k",
				bothPlayers[3], bothProperties[2], bothPlayers[14], bothProperties[11]);
				
			printf("\n");
			printf(" +---+               +---+"); 
			printf("\n");
			
			printf("a|%c %c|\t\t     |%c %c|l",
				bothPlayers[2], bothProperties[1], bothPlayers[15], bothProperties[12]);
			
					
			printf("\n");
			printf(" +---+---+---+---+---+---+"); 
			printf("\n");
			
			printf(" |%c G|%c %c|%c T|%c %c|%c %c|%c J| ",
				bothPlayers[1],  bothPlayers[20], bothProperties[16], bothPlayers[19], bothPlayers[18], bothProperties[14],
				bothPlayers[17], bothProperties[13], bothPlayers[16]);
		
			printf("\n");
			printf(" +---+---+---+---+---+---+"); 
			printf("\n");	
				printf("       o       n   m\n");
								
}

/*
	This function generates a random number from 1 to 6.
	@param theMove - the variable that will be given the value of the random number
	@return theMove - random number generated
*/ 

int diceRoll(int theMove)
{
	srand(time(NULL)); // seeds the rand function; ensures a random number each time 
	 
	theMove = rand() % 6 + 1; // generates a random number from 1 to 6
	
	return theMove;
}

/*
	This function displays the title screen.
	Pre-condition: user only inputs numeric characters
	@param - no parameters
	@return nChoice - the choice chosen by the players
*/ 

int displayTitleScreen ()
{
	int nChoice; 
	
	printf("\n");
	printf("MINIPOLY\n");
	printf("Author: Dalrianne Francesca B. Togado\n");
	printf("Section: S21B\n");
	printf("\n");
	printf("Play Mode (1)\n");
	printf("Debug Mode (2)\n");
	printf("Quit (3)\n");
	printf("\n");
	printf("Enter mode of choice: ");
	scanf("%d", &nChoice);
	
	while (nChoice != 1 && nChoice != 2 && nChoice != 3)   // gets executed if the input is not among the given choices
	{
		printf("Invalid input. Please enter a valid input: ");
		scanf ("%d", &nChoice);
	}
	
	return nChoice; 
}

/*
	This gets the input roll of the players for debug mode.
	Pre-condition: move is less than or equal to 20 and greater than 0
	@param theMove - variable that will be given the value of the user input.
	@return theMove - input roll of the users
*/ 

int playerMove (int theMove)
{
	scanf ("%d", &theMove);
	
	while (theMove > 20 || theMove <= 0)   // gets executed if the input is greater than 20 and less than or equal to 0
	{
		printf("Invalid input. Please enter a valid input: ");
		scanf ("%d", &theMove);
	}
	
	return theMove;
}

/*
	This function shows the account balance of the player and asks if they want to buy the property they landed on.
	Pre-condition: input is equal to 'Y' || 'y' and 'N' || 'n'
	@param yesNo - the choice of the player; 'Y' || 'y' and 'N' || 'n'
	@param bankAccount - bank account of the player
	@param nPlayer - prints '1' if player 1 landed on an unsold tile '2' if player 2 did 
	@return Y y or N n; choice of the players
*/ 

char buyOrNot (char yesNo, float bankAccount, int nPlayer, int forProperty)
{
	printf("\n");
	
	printf("Remaining Account Balance:\n ");
	printf("Player %d: %.2f \n", nPlayer, bankAccount);				// displays the account balance of the player
	
	printf("\n");
	
	printf("Would you like to buy this property?(y/n)\n");
	displayPrices (forProperty);
	scanf("%c", &yesNo);
	scanf("%c", &yesNo);
	
	while ((yesNo != 'y' && yesNo != 'Y') && (yesNo != 'n' && yesNo != 'N'))		// gets executed if the input is not 'y', 'Y', 'n', or 'N'
		{
		printf("Invalid input. Please try again.\n");
		printf("Would you like to buy this property?(y/n)\n");
		scanf("%c", &yesNo);
		scanf("%c", &yesNo);
	}
	
	return yesNo;
}
	
/*
	This function assigns a value from 1 to 4 to forProperty depending on which side of the board they landed on.
	@param arraySize - array size of the players
	@return forProperty - 1 if player landed on the left side of the board
						  2 if on the uppermost side 
						  3 if on the right side
						  4 if on the bottom
*/ 	
		
int buyProperty(int arraySize)
{
	int forProperty;

	if (arraySize  == 2 || arraySize  == 3 || arraySize  == 4 || arraySize  == 5)
		{
			forProperty = 1; 
		}
	
	else if (arraySize  == 7 || arraySize  == 8 || arraySize  == 9 || arraySize  == 10)
		{
			forProperty = 2; 
		}
	
	else if (arraySize  == 12 || arraySize  == 13 || arraySize  == 14 || arraySize  == 15)
		{
			forProperty = 3; 
		}
	
	else if (arraySize  == 17 || arraySize  == 18 || arraySize == 20)
		{
			forProperty = 4;	 
		}

	return forProperty;
}

/*
	This functions calculates the indices of the property array.
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@param arraySizePlayer - basically the tile the player landed on 
	@return the index of the property array the player landed on 
*/  

int markProperty(int forProperty, int arraySizePlayer)
{
	int arraySizeProperty;
	
	/*
		if player landed on property g (which is player[8])
		property array index = 8 - 2 (2 because player landed on the uppermost side)
		property[6] is the property player landed on 
	*/ 
	
	arraySizeProperty = arraySizePlayer - forProperty; 
	
	return arraySizeProperty; 		
}

/*
	This function subtracts the price of the property from player bought from their bank accounts. 
	Pre-condition: bankAccount is not less than 0
	@param bankAccount - account balance of the player
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@return remaining account balance of the players
*/  

float buyTile (float bankAccount, int forProperty)
{

	if (forProperty == 1)
		bankAccount -= 2000000.0;
	else if (forProperty == 2)
		bankAccount -= 4000000.0;
	else if (forProperty == 3)
		bankAccount -= 6000000.0;
	else if (forProperty == 4)
		bankAccount -= 8000000.0;	
	
	
	return bankAccount; 
}

/*
	This function deducts the rent payment from each player's bank accounts. 
	Pre-condition: bankAccount is not less than 0
	@param bankAccount - account balance of the player
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@return remaining account balance of the players
*/  

float payRent (float bankAccount, int forProperty)
{
	if (forProperty == 1)
		bankAccount -= 300000.00;

	else if (forProperty == 2)
		bankAccount -= 500000.00;
	
	else if (forProperty == 3)
		bankAccount -= 1000000.00;
	
	else if (forProperty == 4)
		bankAccount -= 2000000.00;
		
	if (bankAccount < 0)
		bankAccount = 0.0;
	
	return bankAccount; 
}

/*
	This function adds the rent payment to the owner of the property's account balance. 
	@param bankAccount - account balance of the player
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@return remaining account balance of the players
*/  

float getRent (float bankAccount, int forProperty)
{
	if (forProperty == 1)
		bankAccount += 300000.00;
	
	else if (forProperty == 2)
		bankAccount += 500000.00;
	
	else if (forProperty == 3)
		bankAccount += 1000000.00;

	else if (forProperty == 4)
		bankAccount += 2000000.00;

	return bankAccount; 
}

/*
	This function adds 1000000.00 to the player's bank account. 
	@param bankAccount - account balance of the player
	@return remaining account balance of the players
*/  

float gTile(float bankAccount)
{
	bankAccount += 1000000.00;
	
	return bankAccount;
}

/*
	This function displays the property the player landed on. 
	@param arraySize - the index of the players array.
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	doesn't return anything
*/  

void displayTile (int arraySize, int forProperty)
{	
	
		if (forProperty == 1)
		{
			if (arraySize == 2)
			{
				printf("- landed on property a \n");
			}
			else if (arraySize == 3)
			{
				printf("- landed on property b \n");
			}
			else if (arraySize == 4)
			{
				printf("- landed on property c \n");
			}
			else if (arraySize == 5)
			{
				printf("- landed on property d \n");
			}
		}
		else if (forProperty == 2)
		{
			if (arraySize == 7)
			{
				printf("- landed on property e \n");
			}
			else if (arraySize == 8)
			{
				printf("- landed on property f \n");
			}
			else if (arraySize == 9)
			{
				printf("- landed on property g \n");
			}
			else if (arraySize == 10)
			{
				printf("- landed on property h \n");
			}
		}
		else if (forProperty == 3)
		{
			if (arraySize == 12)
			{
				printf("- landed on property i \n");
			}
			else if (arraySize == 13)
			{
				printf("- landed on property j \n");
			}
			else if (arraySize == 14)
			{
				printf("- landed on property k \n");
			}
			else if (arraySize == 15)
			{
				printf("- landed on property l \n");
			}
		}
		else if (forProperty == 4)
		{
			if (arraySize == 17)
			{
				printf("- landed on property m \n");
			}
			else if (arraySize == 18)
			{
				printf("- landed on property n \n");
			}
			else if (arraySize == 20)
			{
				printf("- landed on property o \n");
			}
		}
		
}

/*
	This function displays the property the player bought. 
	@param arraySize - the index of the players array.
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	doesn't return anything
*/  

void displayPurchase(int arraySize, int forProperty)
{
	
		if (forProperty == 1)
		{
			if (arraySize == 2)
			{
				printf("- bought property a \n");
			}
			else if (arraySize == 3)
			{
				printf("- bought property b \n");
			}
			else if (arraySize == 4)
			{
				printf("- bought property c \n");
			}
			else if (arraySize == 5)
			{
				printf("- bought property d \n");
			}
		}
		else if (forProperty == 2)
		{
			if (arraySize == 7)
			{
				printf("- bought property e \n");
			}
			else if (arraySize == 8)
			{
				printf("- bought property f \n");
			}
			else if (arraySize == 9)
			{
				printf("- bought property g \n");
			}
			else if (arraySize == 10)
			{
				printf("- bought property h \n");
			}
		}
		else if (forProperty == 3)
		{
			if (arraySize == 12)
			{
				printf("- bought property i \n");
			}
			else if (arraySize == 13)
			{
				printf("- bought property j \n");
			}
			else if (arraySize == 14)
			{
				printf("- bought property k \n");
			}
			else if (arraySize == 15)
			{
				printf("- bought property l \n");
			}
		}
		else if (forProperty == 4)
		{
			if (arraySize == 17)
			{
				printf("- bought property m \n");
			}
			else if (arraySize == 18)
			{
				printf("- bought property n \n");
			}
			else if (arraySize == 20)
			{
				printf("- bought property o \n");
			}
		}
}

/*
	This function displays the number of rolls of the players 
	@param nMove - the rolls of the player
	doesn't return anything
*/  

void displayRoll (int nMove)
{
	printf("- rolled a %d \n", nMove);
}

/*
	This function deducts 1000000 from the player's bank account.
	Pre-condition: bankAccount is not less than 0
	@param bankAccount - account balance
	@return remaining account balance
*/  

float getTax (float bankAccount)
{
	bankAccount -= 1000000.00;
	
	if (bankAccount < 0)
		bankAccount = 0.0;
	
	return bankAccount;
}

/*
	This function displays amount player A paid to player B.
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@param otherPlayer - the player that receives the payment
	doesn't return anything
*/  

void displayRent(int forProperty, int otherPlayer)
{
 		if (forProperty == 1)
		{
			printf("- paid 300000.00 to Player %d \n", otherPlayer);
		}
		else if (forProperty == 2)
		{
			printf("- paid 500000.00 to Player %d \n", otherPlayer);
		}
		else if (forProperty == 3)
		{
			printf("- paid 1000000.00 to Player %d \n", otherPlayer);
		}
		else if (forProperty == 4)
		{
			printf("- paid 2000000.00 to Player %d \n", otherPlayer);
		}
}

/*
	This function displays the marker tile the player landed on.  
	@param arraySize - index of player array
	@param jail - becomes equal to 2 if player goes to jail
	@param playerToken - prints the player number (1/2)
	@param doubleJail - becomes == 1 if both players went to jail
	doesn't return anything
*/

void displayMarkerTile(int arraySize, int jail, int playerToken, int doubleJail)
{ 
	if (arraySize == 1)
	{
		printf("- landed on Go (G) tile \n");
		printf("- 1000000.00 shall be added to Player %d's account balance \n", playerToken);
	}
	
		
	else if (arraySize == 6)
		{
			if (jail == 0 && doubleJail != 1)
				printf("- landed on Just Visiting (V) tile \n");
				
			else if (jail == 2 || doubleJail == 1)
				{
					printf("- landed on Go To Jail (J) tile \n");
					printf("- transferred to Just Visiting (V) tile and shall skip (2) turns \n");
				}
		}

	else if (arraySize == 11)
		printf("- landed on Free Parking (P) tile \n");
	
	else if (arraySize == 19)
		{
			printf("- landed on Luxury Tax (T) tile \n");
			printf("- 1000000.00 shall be deducted from Player %d's account balance \n", playerToken);
		}
}

/*
	This function gets displayed if player passed by the Go tile
	@param playerToken - player number (1/2)
	doesn't return anything
*/

void displayPassGTile (int playerToken)
{
	printf("- passed by the Go (G) tile \n");
	printf("- 1000000.00 shall be added to Player %d's account balance \n", playerToken);
}

/*
	This function gets the player roll depending on whether it is in play or debug mode.
	Pre-condition: input roll is less than 21 and greater than 0
	@param nMove - the rolls of the player
	@param nPlayer - is equal to player number
	@return the player roll
*/

int playOrDebug (int nChoice, int nPlayer)
{	
	int theMove = 0;
	char nDice;
	
	if (nChoice == 1)
	{	
		printf("Enter 'D' or 'd' to roll dice for Player %d: ", nPlayer);
		scanf(" %c", &nDice);
		
		theMove = diceRoll(theMove);
		
		while (nDice != 'd' && nDice != 'D')
		{
			printf("Invalid input. Please try again: ");
			scanf(" %c", &nDice);
		}
		
		printf("Player %d roll: %d \n", nPlayer, theMove);
	}
	
	else if (nChoice == 2)
	{
		printf("Input roll for Player %d: ", nPlayer);
		theMove = playerMove (theMove);
	}
	
	return theMove;
}


/*
	This function displays the moves of player one when player two is in jail and player 2 when player is not in jail/first arrived in jail.
	@param arrSize - array size for player 1
	@param arrSize2 - array size for player 2
	@param nJail2 - becomes equal to 2 if player 2 goes to jail (used for stalling turns)
	@param doubleJail - becomes equal to 1 if both players are in jail
	@param nMove - player rolls  
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@param playerTwo - is equal to 2 
	@param playerOne - is equal to 1 
	@param nJail - becomes equal to 2 if player 1 goes to jail (used for stalling turns)
    @param passGTile - becomes equal to 1 if player 1 passed by G tile and equal to 2 if player 2 did
	@param oneBuySmth - becomes equal to one if player 1 purchased a property  
	@param twoPayRent - becomes equal to 2 if player 2 landed on an owned property 
	@param twoBuySmth - becomes equal to 2 if player 2 bought a property 
	@param onePayRent - becomes equal to 1 if player 1 landed on an owned property 
	@param isInJail2  - becomes equal to 2 if player 2 is in jail

	@return nothing
*/


void forPlayerOneTurn (int arrSize, int arrSize2, int nJail2, 
					   int doubleJail, int nMove, int forProperty, 
					   int playerTwo, int playerOne, int nJail, 
					   int passGTile, int oneBuySmth, 
					   int twoPayRent, int twoBuySmth, 
					   int onePayRent, int isInJail2)
{
		
					if  (isInJail2 == 0 || nJail2 == 2 || doubleJail == 1)    			// gets executed if player 2 is not in jail or first arrived in jail 
			{				
					printf("Player 2 turn: \n");
					displayRoll(nMove);													// displays the input roll of player 2
					
					if (arrSize2 == 1 || arrSize2 == 6 || arrSize2 == 11 || arrSize2 == 19)
					{
						displayMarkerTile(arrSize2, nJail2, playerTwo, doubleJail);               // displays the marker tile player 2 landed on 
					}					
					else
					{
						displayTile (arrSize2, forProperty);							// displays the normal tile player 2 landed on 
						
						if (passGTile == 2)												// passGTile becomes equal to 2 when player 2 passes by Go tile
							displayPassGTile(playerTwo);								// prints player 2 passed by go tile 
					}
					
					if (twoBuySmth == 2)												// this means that player 2 bought a property 
					{
						displayPurchase(arrSize2, forProperty);							// prints the property player 2 bought 
					}
					else if (twoPayRent == 2)											// this means that player 2 landed on a purchased property 
					{
						displayRent(forProperty, playerOne);						// prints the amount player 2 paid to player 1
					}
					
					printf("\n");
			}
					
					
				else if	(isInJail2 == 2)												// gets displayed when player 2 is in jail
				{				
					printf("Player 1 turn: \n");
					displayRoll(nMove);													// displays input roll of player 1
					
					if (arrSize == 1 || arrSize == 6 || arrSize == 11 || arrSize == 19)
					{
						displayMarkerTile(arrSize, nJail, playerOne, doubleJail);					// displays the marker tile player 1 landed on 
					}					
					else
					{
						displayTile (arrSize, forProperty);								// displays the normal tile player 1 landed on 
						
						if (passGTile == 1)
							displayPassGTile(playerOne);								// prints player 1 passed by go tile 
					}
					
					if (oneBuySmth == 1)
					{
						displayPurchase(arrSize, forProperty);							// prints the property player 1 bought
					}
					else if (onePayRent == 1)
					{
						displayRent(forProperty, playerTwo);						// prints the rent player 1 paid for
					}
					
					printf("\n");
				}
}

/*
	This function displays the moves of player one when player two is in jail and player 2 when player is not in jail/first arrived in jail.
	@param arrSize - array size for player 1
	@param arrSize2 - array size for player 2
	@param nJail2 - becomes equal to 2 if player 2 goes to jail (used for stalling turns)
	@param doubleJail - becomes equal to 1 if both players are in jail
	@param nMove - player rolls  
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@param playerTwo - is equal to 2 
	@param playerOne - is equal to 1 
	@param nJail - becomes equal to 2 if player 1 goes to jail (used for stalling turns)
    @param passGTile - becomes equal to 1 if player 1 passed by G tile and equal to 2 if player 2 did
	@param oneBuySmth - becomes equal to one if player 1 purchased a property  
	@param twoPayRent - becomes equal to 2 if player 2 landed on an owned property 
	@param twoBuySmth - becomes equal to 2 if player 2 bought a property 
	@param onePayRent - becomes equal to 1 if player 1 landed on an owned property 
	@param isInJail  - becomes equal to 1 if player 1 is in jail
	@return nothing
*/


void forPlayerTwoTurn (int isInJail, int nJail, int nJail2, int doubleJail, 
					   int nMove, int arrSize, int arrSize2, int playerOne, 
					   int playerTwo, int forProperty, int passGTile, 
					   int oneBuySmth, int onePayRent, int twoBuySmth, int twoPayRent)
{
			if (isInJail == 0 || nJail == 2 || doubleJail == 1)					// gets displayed when player 1 is not in jail or first arrived in jail or if both players went to jail with player 2 going in first
				{
					printf("Player 1 turn: \n");
					displayRoll(nMove);																// displays number of rolls
					
					if (arrSize == 1 || arrSize == 6 || arrSize == 11 || arrSize == 19)				
					{
						displayMarkerTile(arrSize, nJail, playerOne, doubleJail); 				// displays the marker tile player 1 landed on
					}					
					else
					{
						displayTile (arrSize, forProperty);											// displays the normal tile player 1 landed on 
						
						if (passGTile == 1)
							displayPassGTile(playerOne);											// prints player 1 passed by go tile + money 
					}
					
					if (oneBuySmth == 1)
					{
						displayPurchase(arrSize, forProperty);										// prints player 1's purchase
					}
					else if (onePayRent == 1)
					{
						displayRent(forProperty, playerTwo);									// prints player 1's rent payment
					}
					
					printf("\n");
				}
				
			else if (isInJail == 1)  												// gets displayed when player 1 is in jail 
			{					
					printf("Player 2 turn: \n");
					displayRoll(nMove);												// prints player 2's number of rolls 
					
					if (arrSize2 == 1 || arrSize2 == 6 || arrSize2 == 11 || arrSize2 == 19)
					{
						displayMarkerTile(arrSize2, nJail2, playerTwo, doubleJail);		// prints the marker tile player 2 landed on 
					}					
					else
					{
						displayTile (arrSize2, forProperty);						// displays the tile player 2 landed on 
						
						if (passGTile == 2)
							displayPassGTile(playerTwo);							// prints player 2 passed by g tile + money
					}
					
					if (twoBuySmth == 2)
					{
						displayPurchase(arrSize2, forProperty);						// prints player 2's purchase
					}
					else if (twoPayRent == 2)
					{					
						displayRent(forProperty, playerOne);					// prints player 2's rent payment
					}
					
					printf("\n");
			}
}

/*
	This function displays the cost of the property the player landed on.
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@return nothing
*/

void displayPrices (int forProperty)
{
	if (forProperty == 1)
		printf("Cost: 2000000.00 \n");
	
	else if (forProperty == 2)
		printf("Cost: 4000000.00 \n");
		
	else if (forProperty == 3)
		printf("Cost: 6000000.00 \n");
		
	else if (forProperty == 4)
		printf("Cost: 8000000.00 \n");
}


/*
	This function determines whether the player's account balance has sufficient money to buy property.
	@param forProperty - 1 if player landed on the left side of the board
						 2 if on the uppermost side 
						 3 if on the right side
						 4 if on the bottom
	@bankAccount - player's remaining balance
	@return nothing
*/

int cannotBuy (int forProperty, float bankAccount)
{
	int noMoney;
	
	if (forProperty == 1)
	{
		if (bankAccount < 2000000.00)
			noMoney = 1;
	}
	
	else if (forProperty == 2)
	{
		if (bankAccount < 4000000.0)
			noMoney = 1;
	}
	
	else if (forProperty == 3)
	{
		if (bankAccount < 6000000.0)
			noMoney = 1;
	}
	
	else if (forProperty == 4)
	{
		if (bankAccount < 8000000.0)
			noMoney = 1;
	}

	return noMoney;
}
