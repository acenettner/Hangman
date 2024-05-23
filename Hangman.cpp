#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

void draw(int guessesLeft);

const int LIST_LENGTH = 32;
const string WORD_LIST[LIST_LENGTH] = {
	"horse", "door", "song", "trip", "backbone", "bomb", "round", "treasure", "garbage", "pirate", "state", "whistle",
	"palace", "baseball", "coal", "queen", "dominoes", "photograph", "computer", "hockey", "aircraft", "lawnmower",
	"mattress", "cake", "skate", "battery", "circus", "thief", "teapot", "deep", "shallow", "outside"
	};
int main() {
	srand(time(NULL));
	cout << "HANGMAN" << '\n';
	
	while (1) {
		string word = WORD_LIST[rand() % LIST_LENGTH];
		string shownWord = word;
		for (int i = 0; i < shownWord.length(); i++) {
			shownWord[i] = '-';
		}
		
		char guess;
		int totalGuesses = 6;
		int guessesLeft = 6;
		int lettersLeft = word.length();
		bool gameWon = false;
		vector<char> usedLetters;
		draw(guessesLeft);
		cout << "word: " << shownWord << '\n';
		
		while(guessesLeft > 0 && !gameWon) {
			cout << "\nNumber of guess left: " << guessesLeft << '\n';
			cout << "Please input a letter: ";
			cin >> guess;
			
			if (!isalpha(guess)) {
				cout << "Invalid character." << '\n';
				continue;
			}
			
			
			bool alreadyGuessed = false;
			for (int i = 0; i < usedLetters.size(); i++) {
				if (guess == usedLetters[i]) {
					alreadyGuessed = true;
					break;
				}
			}
				
			if (alreadyGuessed) {
				cout << "Already guessed" << '\n';
				continue;
			}

			bool correctGuess = false;
			usedLetters.push_back(guess);
			
			// Check if letter is in word
			for (int i = 0; i < word.length(); i++) {
				if (tolower(guess) == word[i]) {
					shownWord[i] = tolower(guess);
					correctGuess = true;
					lettersLeft--;
				}
			}
			
			if (!correctGuess) {
				guessesLeft--;
			}
			draw(guessesLeft);
			cout << "word: " << shownWord << '\n';
			
			// Print used letters
			for (int i = 0; i < usedLetters.size(); i++) {
				cout << usedLetters[i] << " ";
			}
			
			
			if (lettersLeft == 0) {
				gameWon = true;
			}
			
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // If user types many chars remove extras
		}
		
		if (gameWon) {
			cout << "\nYou Win!" << '\n';
		} else {
			cout << "\nYou Lose\nWord was " << word << '\n';
		}
		cout << "Type q to quit. Anything else to play again." << '\n';
		cin >> guess;
		if (tolower(guess) == 'q') {
			break;
		}
	}
	
	
	return 0;
}

// Draws hangman and word
void draw(int guessesLeft) {
	// Draw the hangman
	switch (guessesLeft) {
		case 6:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << "       |" << '\n'
				 << "       |" << '\n'
				 << "       |" << '\n'
				 << "========" << '\n';
			break;
		case 5:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << " O     |" << '\n'
				 << "       |" << '\n'
				 << "       |" << '\n'
				 << "========" << '\n';
			break;
		case 4:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << " O     |" << '\n'
				 << " |     |" << '\n'
				 << "       |" << '\n'
				 << "========" << '\n';
			break;
		case 3:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << " O     |" << '\n'
				 << "/|     |" << '\n'
				 << "       |" << '\n'
				 << "========" << '\n';
			break;
		case 2:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << " O     |" << '\n'
				 << "/|\\    |" << '\n'
				 << "       |" << '\n'
				 << "========" << '\n';
			break;
		case 1:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << " O     |" << '\n'
				 << "/|\\    |" << '\n'
				 << "/      |" << '\n'
				 << "========" << '\n';
			break;
		case 0:
			cout << " _______" << '\n'
				 << " |     |" << '\n'
				 << " O     |" << '\n'
				 << "/|\\    |" << '\n'
				 << "/ \\    |" << '\n'
				 << "========" << '\n'
				 << "\nGAME OVER" << '\n';
			break;
	}
}
