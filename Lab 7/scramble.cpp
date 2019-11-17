// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

// Scramble the letters of this string randomly
void permute(char items[], int len);
int main(int argc, char*argv[]) {
    //checks if user gave enough inputs
    if(argc < 2) {
        cout << "Not enough arguments entered" << endl;
        return 1;
    }
    
    //creates a stream in order to read a file
    ifstream inputFile(argv[1]);
    
    //checks if file can be opened
    if(inputFile.fail()){
        cout << "File could not be opened" << endl;
        return 1;   
    }
    
    int numWords;
    
    //read number in file
    inputFile >> numWords;
    
    //checks if number was able to be read
    //closes file if integer is not read
    if(inputFile.fail()){
        cout << "Failed to read integer" << endl;
        inputFile.close();    
    }
    
    //a dynamically allocated array of char*'s
    char** wordBank = new char*[numWords];
    
    //character array of 41 character used to hold strings that are read in
    char buffer[41]; 
    
    //reads each word from file into chracter array
    for(int i=0;i<numWords;i++){
        inputFile >> buffer;
        char* word = new char[strlen(buffer) + 1];
        strcpy(word, buffer);
        wordBank[i] = word;
    }
    inputFile.close();
    
  
  srand(time(0));
  char guess[80];

  bool wordGuessed = false;
  int numTurns = 10;
    
  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (!wordGuessed && numTurns > 0) {
    cout << "Scrambled word: " << word << endl;
    cout << "What do you guess the original word is? ";
    cin >> guess;
    
   //checks if guess is corrrect
    wordGuessed = strcmp(guess, wordBank[target]) == 0;
    numTurns--;   // Every guess counts as a turn
  }
  if (wordGuessed) {
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  /* Free up any necessary memory */
    
  delete[] word;
  for (int i = 0; i < numWords; ++i){
    delete[] wordBank[i];
  }
  delete[] wordBank;
  return 0;
}

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}

