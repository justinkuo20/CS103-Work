/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Justin Kuo
 * USC email: kuojusti@usc.edu 
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = { 'H', 'S', 'D', 'C' };
const char *type[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q",
		"K", "A" };
const int value[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */

void shuffle(int cards[]) {
	/******** You complete ****************/
	for (int i = NUM_CARDS - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int temp;
		temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}
/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id) {
	/******** You complete ****************/
	if (id%13 == 0) {
		cout << "2-";
	}
	if (id%13 == 1) {
		cout << "3-";
	}
	if (id%13 == 2) {
		cout << "4-";
	}
	if (id%13 == 3) {
		cout << "5-";
	}
	if (id%13 == 4) {
		cout << "6-";
	}
	if (id%13 == 5) {
		cout << "7-";
	}
	if (id%13 == 6) {
		cout << "8-";
	}
	if (id%13 == 7) {
		cout << "9-";
	}
	if (id%13 == 8) {
		cout << "10-";
	}
	if (id%13 == 9) {
		cout << "J-";
	}
	if (id%13 == 10) {
		cout << "Q-";
	}
	if (id%13 == 11) {
		cout << "K-";
	}
	if (id%13 == 12) {
		cout << "A-";
	}
	if (id/13 == 0) {
		cout << "H";
	}
	if (id/13 == 1) {
		cout << "S";
	}
	if (id/13 == 2) {
		cout << "D";
	}
	if (id/13 == 3) {
		cout << "C";
	}
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id) {
	/******** You complete ****************/
	int valueOfCard = id % 13;
	return value[valueOfCard];
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards) {
	/******** You complete ****************/
	for (int i = 0; i < numCards; i++) {
		printCard(hand[i]);
		cout << " ";
	}
	cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards) {
	/******** You complete ****************/
    int aces = 0;
	int score = 0;
	for (int i = 0; i < numCards; i++) {
		score += cardValue(hand[i]);
	}
    for(int j=0;j<numCards;j++){
        if(hand[j] % 13 == 12){  
            aces++;
        }
    }
    while(score > 21 && aces > 0){
        score -= 10;
        aces--;
    }
    
	return score;

}
/**
 * Main program logic for the game of 21
 */
int main(int argc, char *argv[]) {
	//---------------------------------------
	// Do not change this code -- Begin
	//---------------------------------------
	if (argc < 2) {
		cout << "Error - Please provide the seed value." << endl;
		return 1;
	}
	int seed = atoi(argv[1]);
	srand(seed);
	int cards[52];
	int dhand[9];
	int phand[9];
	//---------------------------------------
	// Do not change this code -- End
	//---------------------------------------

	/******** You complete ****************/
    
	bool play = true;
    while(play) {
        char choice;
        int sizeOfPhand = 2;
        int sizeOfDhand = 2;
        
        for(int i=0; i<NUM_CARDS;i++){
            cards[i] = i;
        }
        shuffle(cards);
        for(int i=0; i<2;i++){
            phand[i] = cards[i*2];
            dhand[i] = cards[i*2+1];
        }
        cout << "Dealer: ? ";
        printCard(dhand[1]);
        cout << endl;
        cout << "Player: ";
        printHand(phand, sizeOfPhand);
            
        while(getBestScore(phand, sizeOfPhand) < 21) {
            cout << "Type 'h' to hit and 's' to stay: ";
            cin >> choice;
            if(choice == 'h') {
                phand[sizeOfPhand] = cards[2 + sizeOfPhand];
                sizeOfPhand++;
                cout << "Player: ";
                printHand(phand, sizeOfPhand);
            } else {
                break;
            }
        }
       // cout << getBestScore(phand, sizeOfPhand) << endl;
            
        if(getBestScore(phand, sizeOfPhand) > 21) {
            cout << "Player busts " << endl;
            cout << "Lose " << getBestScore(phand, sizeOfPhand) << " ";
            cout << getBestScore(dhand, sizeOfDhand) << endl;
         } else if (getBestScore(phand, sizeOfPhand <= 21)) {
		        while (getBestScore(dhand, sizeOfDhand) < 17) {
				dhand[sizeOfDhand] = cards[sizeOfDhand + sizeOfPhand];
				sizeOfDhand++;
			}
         
         cout << "Dealer: ";
         printHand(dhand, sizeOfDhand);
         cout << endl;
         if(getBestScore(dhand, sizeOfDhand) > 21) {
             cout << "Dealer busts" << endl;
             cout << "Win " << getBestScore(phand, sizeOfPhand) << " ";
             cout << getBestScore(dhand, sizeOfDhand) << endl;
         } else {
                 if(getBestScore(phand, sizeOfPhand) 
                    > getBestScore(dhand, sizeOfDhand)) {
                     cout << "Win " << getBestScore(phand, sizeOfPhand) << 
                         " " << getBestScore(dhand, sizeOfDhand) << endl;
                 } else if (getBestScore(phand, sizeOfPhand) 
                            < getBestScore(dhand, sizeOfDhand)){
                     cout << "Lose " << getBestScore(phand, sizeOfPhand) << 
                         " " << getBestScore(dhand, sizeOfDhand) << endl;
                 } else {
                     cout << "Tie " << getBestScore(phand, sizeOfPhand) << 
                         " " << getBestScore(dhand, sizeOfDhand) << endl;
                     }
                 }
            }           
         cout << "Play again? (y/n)";
         cin >> choice;
                      
         if(choice == 'y') {
             play = true;
         } else {
             play = false;
             break;
         }
    }
  return 0;         
                            
}
                   

