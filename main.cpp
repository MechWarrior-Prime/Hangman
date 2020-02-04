#include <iostream>
#include <string>
#include "..\common\technolib.h"
//#define nonDynamicArrayElementCount ( sizeof(nonDynamicArray) / sizeof(nonDynamicArray[ 0 ]) ) //code by par

using namespace std;

const char gcUnknown = '_';

bool IsSolved(string Guessed){
	for (int j = 0; j < Guessed.length(); j++) {
		if (Guessed[j] == gcUnknown) {
			return false;
		}
	}
	return true;
} //IsSolved

int main() {
	cout << "Hangman (Uebung 7), 22-JAN-2020 to 23-JAN-2020" << endl; 
	cout << "" << endl;

	printf("You have 10 tries to guess the word. Only lowercase letters allowed.");

	string lsWords[] = {
		"hangman",
		"predator",
		"authority",
		"somnambulist",
		"disruptor",
		"vampire",
		"xylophone",
		"saxophone",
		"computer",
		"hammer"
	};

	//cout << sizeof(lsWords) / sizeof(lsWords[0]) << endl;

	InitRNG();
	string lsHiddenWord = lsWords[rollAD_D_Die(sizeof(lsWords) / sizeof(lsWords[0]))];// putting the element count into a function is very difficult
	string lsGuessed = FillString(gcUnknown, lsHiddenWord.length());

	//cout << lsHiddenWord << " " << lsGuessed << endl;

	const int MAXTRIES = 10;
	char lcGuess = ' ';

	for (int i = 1; i <= MAXTRIES; i++) {

		printf("\nEnter try #%d: ", i);
		cin >> lcGuess;

		for (int j = 0; j < lsHiddenWord.length(); j++) {
			if (lsHiddenWord[j] == lcGuess) {
				lsGuessed[j] = lcGuess;
			}
			if (IsSolved(lsGuessed)) {
				printf("Great job! You needed %d tries.\n", i);
				return 1;
			}
		}//scan loop
		cout << lsGuessed << endl;
	}// tries loop 

	cout << "\nYou've been hung. The solution was: " << lsHiddenWord << endl;

	system("pause"); //Windows command line
	return 0;
}