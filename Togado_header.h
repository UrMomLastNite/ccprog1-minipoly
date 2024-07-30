#ifndef HEADERFILE_H
#define HEADERFILE_H

void displayBoard (char *bothPlayers, char *bothProperties);

int diceRoll(int theMove);

int displayTitleScreen ();

int playerMove (int theMove);

char buyOrNot (char yesNo, float bankAccount, int nPlayer, int forProperty);

int buyProperty(int arraySize);

int markProperty(int forProperty, int arraySizePlayer);

float buyTile (float bankAccount, int forProperty);

float payRent (float bankAccount, int forProperty);

float getRent (float bankAccount, int forProperty);

float gTile(float bankAccount);

void displayRoll (int nMove);

void displayPurchase(int arraySize, int forProperty);

void displayTile (int arraySize, int forProperty);

float getTax (float bankAccount);

void displayRent(int forProperty, int otherPlayer);

void displayMarkerTile(int arraySize, int jail, int playerToken, int doubleJail);

void displayPassGTile (int playerToken);

int playOrDebug (int nChoice, int nPlayer);

void forPlayerOneTurn (int arrSize, int arrSize2, int nJail2, 
					   int doubleJail, int nMove, int forProperty, 
					   int playerTwo, int playerOne, int nJail, 
					   int passGTile, int oneBuySmth, 
					   int twoPayRent, 
					   int twoBuySmth, 
					   int onePayRent, int isInJail2);
					   
void forPlayerTwoTurn (int isInJail, int nJail, int nJail2, int doubleJail, 
					   int nMove, int arrSize, int arrSize2, int playerOne, 
					   int playerTwo, int forProperty, int passGTile, 
					   int oneBuySmth, int onePayRent, int twoBuySmth, int twoPayRent);
					   
void displayPrices (int forProperty);

int cannotBuy (int forProperty, float bankAccount);

#endif
