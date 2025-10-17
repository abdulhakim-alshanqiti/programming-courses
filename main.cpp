#include <iostream>

using namespace std;

enum enRockPaperScissors {
	Rock = 1, Paper = 2, Scissors = 3
};

enum enWinner {
	Player = 1, Computer = 2, Draw = 3
};

struct stRound {
	int number;
	enRockPaperScissors playerChoice;
	enRockPaperScissors computerChoice;
	enWinner result;
};
struct stGameInfo {
	int rounds = 0;
	int player = 0;
	int computer = 0;
	int draws = 0;
	enWinner winner;
};

int RandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}
int ReadNumberInRange(string message, int from, int to) {
	int number = 0;
	do {
		cout << message << endl;

		cin >> number;
	} while (number < from && number > to);	return number;

}

string ChoiceToString(enRockPaperScissors choice) {
	switch (choice)
	{
	case Rock: return "Rock";
	case Paper: return "Paper";
	case Scissors: return "Scissors";
	}
}
string WinnerToString(enWinner winner) {
	switch (winner)
	{
	case Player: return "The Player";
	case Computer: return "The Computer";
	case Draw: return "No Winner";
	}
}
enRockPaperScissors ChooseAnItem() {
	int choice = ReadNumberInRange("Your Choice: \n[1]: Rock\n[2]: Paper\n[3]: Scissors", 1, 3);

	return (enRockPaperScissors)choice;
}

enWinner PlayRound(enRockPaperScissors playerChoice, enRockPaperScissors computerChoice) {
	if ((playerChoice == computerChoice)) {
		return Draw;
	}

	switch (playerChoice)
	{
	case  Rock:
		switch (computerChoice)
		{
		case Paper: return Computer;
		case Scissors: return Player;
		}

	case  Paper:
		switch (computerChoice)
		{
		case Rock: return Player;
		case Scissors: return Computer;
		}

	case  Scissors:
		switch (computerChoice)
		{
		case Rock: return Computer;
		case Paper: return Player;
		}

	}

}

void PrintRoundInfo(stRound round) {

	cout << "____________Round[" << round.number << "]_____________" << endl;

	cout << "Player Choice: " << ChoiceToString(round.playerChoice) << endl;
	cout << "Computer Choice: " << ChoiceToString(round.computerChoice) << endl;

	switch (round.result) {
		{
	case Player:

	{
		system("color 2F");
		cout << "Round Winner: [Player]" << endl;

		break;
	}

	case Computer:

	{
		system("color 4F");
		cout << "Round Winner: [Computer]\a" << endl;

		break;
	}

	case Draw: {
		system("color 6F");
		cout << "Round Winner: [No Winner]" << endl;
		break;

	}
		}
	}
}
stRound StartRound(int roundNumber) {
	stRound round;

	round.number = roundNumber;
	round.playerChoice = ChooseAnItem();
	round.computerChoice = (enRockPaperScissors)RandomNumber(1, 3);
	round.result = PlayRound(round.playerChoice, round.computerChoice);

	return round;
}

void AddRoundToGameInfo(stGameInfo& gameResult, stRound round) {
	switch (round.result)
	{
	case Player:
		gameResult.player++;
		break;

	case Computer:
		gameResult.computer++;
		break;

	case Draw:
		gameResult.draws++;
		break;

	}
}

enWinner CheckWinner(stGameInfo gameInfo) {
	if (gameInfo.player == gameInfo.computer) {
		return Draw;
	}
	else if (gameInfo.player > gameInfo.computer) {
		return Player;
	}
	else {
		return Computer;
	}
}
void PrintGameInfo(stGameInfo gameInfo) {
	cout << "\t\t--------------------------------\n\n" << endl;
	cout << "\t\t    +++ G a m e O v e r +++ " << endl;
	cout << "\t\t--------------------------------\n\n" << endl;
	cout << "\t\t--------[ Game Results ]--------\n\n" << endl;

	cout << "\t\t--------------------------------\n\n" << endl;

	cout << "\t\tGame Rounds : " << gameInfo.rounds << " \n\n" << endl;
	cout << "\t\tPlayer has won : " << gameInfo.player << " times \n\n" << endl;
	cout << "\t\tComputer has won : " << gameInfo.computer << " times \n\n" << endl;
	cout << "\t\tDraw has happened : " << gameInfo.draws << " times \n\n" << endl;
	cout << "\t\tFinal Winner : " << WinnerToString(gameInfo.winner) << "\n\n" << endl;

	cout << "\t\t--------------------------------\n\n" << endl;
}

void StartGameLoop() {
	system("cls");
	system("color 0F");

	int rounds = ReadNumberInRange("How Many Rounds? pick from 1 to 10", 1, 10);
	stGameInfo GameInfo;
	GameInfo.rounds = rounds;

	for (int i = 1; i <= rounds; i++)
	{
		cout << "Round [" << i << "] begins" << endl;

		stRound Round = StartRound(i);

		PrintRoundInfo(Round);
		AddRoundToGameInfo(GameInfo, Round);

	}
	GameInfo.winner = CheckWinner(GameInfo);
	PrintGameInfo(GameInfo);

	char YesOrNo;
	cout << "Do you Want To Play Again? y/n" << endl;
	cin >> YesOrNo;

	if (YesOrNo == ('y' || 'Y')) {
		StartGameLoop();
	}

}
int main() {
	srand((unsigned)time(NULL));
	StartGameLoop();

	return 0;
}