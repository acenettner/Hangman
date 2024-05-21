#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;
int main() {
	srand(time(NULL));
	cout << "HANGMAN" << '\n';
	
	char guess;
	int totalGuesses = 6;
	int guessesLeft = 6;
	while(guessesLeft > 0) {
		cout << "\nNumber of guess left: " << totalGuesses << '\n';
		cout << "Please input a letter: ";
		cin >> guess;
		cout << guess;
	}
	
	return 0;
}
