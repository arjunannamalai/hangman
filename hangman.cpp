#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
 
int tries=3;
string message = "Play!";

void menu()
{
    system("clear");
    cout<<"\tHangman Game!"<<endl;
    cout << "You have " << tries << " tries"<<endl;
    cout<<"Try and guess the day."<<endl;
	cout<<message;
}

int guessCheck (char guess, string secretday, string &guessday)
{
	int i;
	int matches=0;
	int len=secretday.length();
	for (i = 0; i< len; i++)
	{
		
		if (guess == guessday[i])
			return 0;
		
		if (guess == secretday[i])
		{
			guessday[i] = guess;
			matches++;
		}
	}
	return matches;
}
 
int main(int argc, char *argv[])
{
	string name;
	char letter;
	string day;
    string days[] =
	{
		"monday",
		"tuesday",
		"wednesday",
		"thursday",
		"friday",
		"saturday",
		"sunday"
	};
	srand(time(NULL));
	int n=rand()% 7;
	day=days[n];
	string hide_m(day.length(),'?');
	while (tries!=0)
	{
		menu();
		cout << "\n\t" << hide_m;
		cout << "\n\tGuess a letter: ";
		cin >> letter;
		
		if (guessCheck(letter, day, hide_m)==0)
		{
			message = "Incorrect letter.";
			tries = tries - 1;
		}
		else
			message = "NICE! You guess a letter";
		if (day==hide_m)
		{
			message = "Congratulations! You got it!";
			menu();
			cout << "\n\tThe day is : " << day << endl;
			break;
		}
	}
	if(tries == 0)
	{
		message = "Nooooo... you've been hanged.";
		menu();
		cout << "\n\tThe day was : " << day << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}
