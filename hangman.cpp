#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <thread>

using namespace std;

void Play();
void MainTwo();

thread pl(Play);
thread mn(MainTwo);

void Play()
{
	while(true)
	{
		PlaySound(TEXT("Hymn_Of_Arstotzka.wav"), 0, SND_FILENAME);
	}
}


// Start screen
void hangman()
{
	cout << "                                            _____________________     "  << endl;
	cout << "                                             || /              }      "  << endl;
	cout << "                                             ||/               O      "  << endl;
	cout << "                                             ||               /|\\    "  << endl;
	cout << "                                             ||              / | \\   "  << endl;
	cout << "                                             ||\\               |     "  << endl;
	cout << "                                             || \\             / \\   "  << endl;
	cout << "                                             ||  \\           /   \\  "  << endl;
	cout << "                                             ||   \\                   "  << endl;
	cout << "                                            _||____\\_________________ "  << endl;
	// cout << "\nPress any key to start(and then 'Enter')\n" << endl;
}

void Game()
{
	HANDLE hOut;
	//The variable to check if a user had already guessed a letter
	int check = 0;
	
	//Adding the array which will count incorrect guessed letters
	char incorrectGuesses[8];
	incorrectGuesses[0] = '\0';
	for (int i = 1; i < 7; i++)
	{
		incorrectGuesses[i] = '-';
	}
	incorrectGuesses[7] = '\0';
	
	//The variable for check if players guess is correct
	bool CorrectGuess;
	
	//The variable with a guessed letter
	char GuessChar;
	
	//The number of players attempts
	int att = 7;
	
	//The variable with random word
	string Word;
	
	//The string array with 100 words from a file which we will encrupt with '*' later
	string secretWordsList[100];
	ifstream WordIn;
	
	srand(time(NULL));
	WordIn.open("secretWords.txt");

	// Filling the array with words	from the file
	for (int i = 0; i < 99; i++)
	{
		WordIn >> secretWordsList[i];
		// cout << secretWordList[i] << endl; FOR TESTS ONLY
	}
	
	//Searching for random word from the array with words
	int RanNum = rand() % 100;
	Word = secretWordsList[RanNum];
	// cout << Word << endl; FOR TESTS (or cheating) ONLY
	
	WordIn.close();
	string SecretWord(Word.length(), '*');
	// cout << SecretWord << endl; Also for tests
		
	//Game loop
	while (att >= 0)
	{
		//reset the bool variable
		CorrectGuess = false;
		
			
		//Starting the game, asking a user to guess a letter and receive it
		if (att > 0)
		{
			cout << "\n                                   The word that you have is: " << SecretWord << endl;
			cout << "          	                    There are " << SecretWord.length() << " letters in this word!\n";
			cout << "                                      Incorrect guesses: " << incorrectGuesses << endl;
			cout << "                              	           You have " << att << " misses!\n";
			cout << "                                            Enter a letter: \n";
			cin >> GuessChar;
			system("cls");
		}
		if (att <= 0)
		{
			break;
		}
		
		//Checking if the letter which a user gave us is coorect and if it is => switch(from SecretWord) star by this letter
		for (int i = 0; i < Word.length(); i++)
		{
			if (GuessChar == SecretWord[i])
			{
				cout << "                 Sorry, probably you've already guessed the letter '" << GuessChar << "' Try to guess another letter" << endl;
				check = 1;
				CorrectGuess = true;
				break;
			}
			if (Word[i] == GuessChar)
			{
				SecretWord[i] = GuessChar;
				CorrectGuess = true;
				check = 0;
							
			}
		}
		
		if (Word == SecretWord)
		{
			cout << "                       Congrats!!! You have guessed the word '" << SecretWord << "' and saved man's life!\n";
			cout << "" << endl;
			cout << "                                        (m) to play with your friend" << endl;
			cout << "                                            (s) to play single" << endl;
			cout << "                                                (q) to exit " << endl;
			cout << "" << endl;
			break;
		}
		
		//Subtract one of attempts if a user didn't guess a letter
		if (CorrectGuess == false)
		{
			cout << "                                 Oops! " << GuessChar << " doesn't exist in this word, sorry\n";
			att--;
		}
		else if (check == 0)
		{
			cout << "                                  Congrats! You have guessed the letter " << GuessChar << endl;
			
		}
		
		switch(att)
		{
			case 7:
				
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /                      " << endl;
					cout << "                                         ||/                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||\\                      " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					
				break;
				
			case 6:
			
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||\\                      " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[0] = GuessChar;
					}
					
				break;
				
			case 5:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||\\                      " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[1] = GuessChar;
					}
						
				break;
					
					
			case 4:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||                |      " << endl;
					cout << "                                         ||                |      " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[2] = GuessChar;
					}
						
				break;
					
					
					
			case 3:
				
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|      " << endl;
					cout << "                                         ||              / |      " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[3] = GuessChar;
					}
					
				break;
				
				
			case 2:
				
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|\\    " << endl;
					cout << "                                         ||              / | \\   " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[4] = GuessChar;
					}
						
				break;
					
					
			case 1:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|\\    " << endl;
					cout << "                                         ||              / | \\   " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\             /      " << endl;
					cout << "                                         ||  \\           /       " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[5] = GuessChar;
					}
						
				break;
					
					
			case 0:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|\\    " << endl;
					cout << "                                         ||              / | \\   " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\             / \\   " << endl;
					cout << "                                         ||  \\           /   \\  " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					cout <<"\n                                    You killed this man. Game over :(\n";
					cout << "                                       The correct word was: " << Word << endl;
					cout << "" << endl;
					cout << "                                        (m) to play with your friend" << endl;
					cout << "                                            (s) to play single" << endl;
					cout << "                                                (q) to exit " << endl;
					cout << "" << endl;
					
				break;
		}
	}
}

void multiGame()
{
	//The variable to check if a letter was already guessed
	int check = 0;
	
	//The array with incorrect guessed letters
	char incorrectGuesses[8];
	incorrectGuesses[0] = '\0';
	for (int i = 1; i < 7; i++)
	{
		incorrectGuesses[i] = '-';
	}
	incorrectGuesses[7] = '\0';
	
	//The variable for check if players guess is correct
	bool CorrectGuess;
	
	//The variable with a guessed letter
	char GuessChar;
	
	//The number of pllayers attempts
	int att = 7;
	
	//The variable with random word
	string Word;
	
	cout << "                                               Guess a word: \n";
	cin >> Word;
	system("cls");
	//cout << Word << endl;
	string SecretWord(Word.length(), '*');
	//cout << SecretWord << endl; //Also for tests
	
	//Game loop
	while (att >= 0)
	{
		//reset the bool variable
		CorrectGuess = false;
		
			
		//Starting the game, asking a user to guess a letter and receive it
		if (att > 0)
		{
			cout << "\n                                   The word that you have is: " << SecretWord << endl;
			cout << "               	                    There are " << SecretWord.length() << " letters in this word!\n";
			cout << "                                      Incorrect guesses: " << incorrectGuesses << endl;
			cout << "                                   	   You have " << att << " misses!\n";
			cout << "                                             Enter a letter: \n";
			cin >> GuessChar;
			system("cls");
		}
		if (att <= 0)
		{
			break;
		}
		
				//Checking if the letter which a user gave us is coorect and if it is => switch(from SecretWord) star by this letter
		for (int i = 0; i < Word.length(); i++)
		{
			if (GuessChar == SecretWord[i])
			{
				cout << "                 Sorry, probably you've already guessed the letter '" << GuessChar << "' Try to guess another letter" << endl;
				check = 1;
				CorrectGuess = true;
				break;
			}
			if (Word[i] == GuessChar)
			{
				SecretWord[i] = GuessChar;
				CorrectGuess = true;
				check = 0;
							
			}
		}
		
		if (Word == SecretWord)
		{
			cout << "                       Congrats!!! You have guessed the word '" << SecretWord << "' and saved man's life!\n";
			cout << "" << endl;
			cout << "                                        (m) to play with your friend" << endl;
			cout << "                                            (s) to play single" << endl;
			cout << "                                                (q) to exit " << endl;
			cout << "" << endl;
			break;
		}
		
		//Subtract one of attempts if a user didn't guess a letter
		if (CorrectGuess == false)
		{
			cout << "                                 Oops! " << GuessChar << " doesn't exist in this word, sorry\n";
			att--;
		}
		else if (check == 0)
		{
			cout << "                                  Congrats! You have guessed the letter " << GuessChar << endl;
			
		}
		
		switch(att)
		{
			case 7:
				
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /                      " << endl;
					cout << "                                         ||/                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||\\                      " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					
				break;
				
			case 6:
			
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||\\                      " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[0] = GuessChar;
					}
					
				break;
				
			case 5:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||                        " << endl;
					cout << "                                         ||\\                      " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[1] = GuessChar;
					}
						
				break;
					
					
			case 4:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||                |      " << endl;
					cout << "                                         ||                |      " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[2] = GuessChar;
					}
						
				break;
					
					
					
			case 3:
				
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|      " << endl;
					cout << "                                         ||              / |      " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[3] = GuessChar;
					}
					
				break;
				
				
			case 2:
				
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|\\    " << endl;
					cout << "                                         ||              / | \\   " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\                     " << endl;
					cout << "                                         ||  \\                    " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[4] = GuessChar;
					}
						
				break;
					
					
			case 1:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|\\    " << endl;
					cout << "                                         ||              / | \\   " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\             /      " << endl;
					cout << "                                         ||  \\           /       " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					if (CorrectGuess == false)
					{
						incorrectGuesses[5] = GuessChar;
					}
						
				break;
					
					
			case 0:
					
					cout << "                                        _____________________     " << endl;
					cout << "                                         || /              }      " << endl;
					cout << "                                         ||/               O      " << endl;
					cout << "                                         ||               /|\\    " << endl;
					cout << "                                         ||              / | \\   " << endl;
					cout << "                                         ||\\               |     " << endl;
					cout << "                                         || \\             / \\   " << endl;
					cout << "                                         ||  \\           /   \\  " << endl;
					cout << "                                         ||   \\                   " << endl;
					cout << "                                        _||____\\_________________ " << endl;
					cout <<"\n                                    You killed this man. Game over :(\n";
					cout << "                                       The correct word was: " << Word << endl;
					cout << "" << endl;
					cout << "                                        (m) to play with your friend" << endl;
					cout << "                                            (s) to play single" << endl;
					cout << "                                                (q) to exit " << endl;
					cout << "" << endl;
					
				break;
		}
	}
}


void StartScreen()
{
cout << "	 ____________________________________________________________________________________________________ " << endl;
cout << "	|   ________  ________   __  _____    _   __________  ______    _   __   _________    __  _________  |" << endl;
cout << "	|  /_  __/ / / / ____/  / / / /   |  / | / / ____/  |/  /   |  / | / /  / ____/   |  /  |/  / ____/  |" << endl;
cout << "	|   / / / /_/ / __/    / /_/ / /| | /  |/ / / __/ /|_/ / /| | /  |/ /  / / __/ /| | / /|_/ / __/     |" << endl;
cout << "	|  / / / __  / /___   / __  / ___ |/ /|  / /_/ / /  / / ___ |/ /|  /  / /_/ / ___ |/ /  / / /___     |" << endl;
cout << "	| /_/ /_/ /_/_____/  /_/ /_/_/  |_/_/ |_/\\____/_/  /_/_/  |_/_/ |_/   \\____/_/  |_/_/  /_/_____/     |" << endl;
cout << "	|____________________________________________________________________________________________________|" << endl;
cout << "                                                                                                      " << endl;
cout << "		                    _________________________________________                                     " << endl;
cout << "          	                   |                                         |                                    " << endl;
cout << "              		           |    Press (M) to play with your friend   |                                    " << endl;                                                                                                 
cout << "              	     	           |      Press (S) to play single mode      |                                    " << endl;
cout << "              		           |            Press (Q) to exit            |                                    " << endl;
cout << "              		           |_________________________________________|                                    " << endl;
}

void MainTwo(){
	const int NotUsed = system( "color 9F" );
	StartScreen();
	hangman();
	while (true)
	{
		
		
		
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'm')
			{
				system("cls");
				multiGame();
			}
			else if (key == 's')
			{
				system("cls");
				Game();
			}
			else if (key == 'q')
			{				
				pl.detach();
				system("CLS");
				exit(0);
			}
		}
	}
}


int main()
{
	
	mn.join();
	pl.join();
	
	return 0;
}
