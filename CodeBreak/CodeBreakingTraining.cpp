#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{

	srand(time(NULL));

	int Replay = false;

	while (Replay == false)
	{
	int AgentNum = rand() % 1000 + 1;
	string RetryInput;

	cout << "Greetings, Agent in training. We would like you to take a test." << endl;
	cout << "This particular test is meant to train your brain to understand important words through the use of scrambling it." << endl;
	cout << "There will be 3 words to unscramble. Good luck." << endl << endl;


	for (int a = 0; a < 3; a++) {

		enum field { Word, Hint, NumFields };
		const int Rando = rand() % 10 + 1;
		const string WordGroup[10][NumFields] =
		{
			{"ESPIONAGE", "To spy and gain information."},
			{"ASSASSINATION", "To take down a person of interest."},
			{"INTERROGATION", "To obtain information from a person of interest."},
			{"PROTECTION", "To ensure the safety of something."},
			{"RENDEZVOUS", "To meet at an agreed time and place."},
			{"CENSORSHIP", "To suppress or prohibit something."},
			{"NEGOTIATION", "To discuss or make arrangements with something."},
			{"ANALYZATION", "To examine information."},
			{"PREPARATION", "To put in proper condition/readiness."},
			{"OPERATION", "Organized and concerted activity."}
		};

		string JumbleWord = WordGroup[Rando][Word];
		string JumbleHint = WordGroup[Rando][Hint];

		string Jumble = JumbleWord;
		int WordLength = Jumble.size();

		for (int b = 0; b < WordLength; ++b)
		{
			int Letter1 = (rand() % WordLength);
			int Letter2 = (rand() % WordLength);
			char temp = Jumble[Letter1];
			Jumble[Letter1] = Jumble[Letter2];
			Jumble[Letter2] = temp;
		}

		cout << endl << "Word  #" << a+1 << ": " << Jumble << endl;
		string Guess;

		cout << "Input the unscrambled word (type /'hint/' for a hint, or /'quit/' to quit):" << endl;
		cin >> Guess;

		while ((Guess != JumbleWord) && (Guess != "quit"))
		{
			if (Guess == "hint")
			{
				cout << JumbleHint;
			}
			else
			{
				cout << endl << "The Input was incorrect." << endl;
			}

			cout << endl << "Input the unscrambled word (type /'hint/' for a hint, or /'quit/' to quit):" << endl;
			cin >> Guess;
		}

		if (Guess == JumbleWord)
		{
			cout << "The Input was correct." << endl;
		}

	}

	cout << endl << "Congratulations. You passed the Scramble test." << endl;
	cout << "Welcome aboard, Agent #" << setfill('0') << setw(4) << AgentNum << "." << endl;

	while (!(RetryInput == "Y") && !(RetryInput == "y") && !(RetryInput == "N") && !(RetryInput == "n"))
	{
		cout << endl << "Would you like to try again?" << endl << "Y/N" << endl;
		cin >> RetryInput;
		cout << RetryInput << endl;
	}

	if (RetryInput == "Y" || RetryInput == "y")
	{
		cout << "Reloading..." << endl << endl << endl;
	}
	else if (RetryInput == "N" || RetryInput == "n")
	{
		cout << "Shutting down..." << endl;
		Replay = true;
	}
	}

	system("pause");
	return 0;
}