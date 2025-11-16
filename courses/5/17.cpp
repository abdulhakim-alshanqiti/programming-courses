#include <iostream>
#include <cmath>
#include <string>

using namespace std;
string Read3LetterPassword(string message) {
	string password = "";
	do {
		cout << message << endl;

		cin >> password;
	} while (password.length() != 3);


	return password;

}

void TryAllLettersFromAAAtoZZZ(string password)
{
	string letters = "";
	int counter = 0;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				counter++;
				letters = { char(i)  ,char(j) , char(k) };
				cout << "Try Number " << counter << " : " << letters << endl;

				if (letters == password)
				{
					cout << "After (" << counter << ") tries I have found the password it's " << letters << endl;
					return;
				}




			}
		}

	}
}

int main()
{
	string password = Read3LetterPassword("Enter a 3 Letter Password");
	TryAllLettersFromAAAtoZZZ(password);
	return 0;
}