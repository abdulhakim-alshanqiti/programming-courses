//#include <iostream>
//
//using namespace std;
//
//enum enRockPaperScissors {
//	Rock = 1, Paper = 2, Scissors = 3
//};
//
//enum enWinner {
//	Player = 1, Computer = 2, Draw = 3
//};
//
//struct stRoundInfo {
//	int number;
//	enRockPaperScissors playerChoice;
//	enRockPaperScissors computerChoice;
//	enWinner winner;
//};
//struct stGameResults {
//	int rounds;
//	int playerWinTimes;
//	int computerWinTimes;
//	int draws;
//	enWinner winner;
//};
//
//int RandomNumber(int from, int to) {
//	return rand() % (to - from + 1) + from;
//}
//int ReadNumberInRange(string message, int from, int to) {
//	int number = 0;
//	do {
//		cout << message << endl;
//
//		cin >> number;
//	} while (number < from || number > to);	return number;
//
//}
//string Tabs(int number) {
//	string tabs = "";
//	for (int i = 1; i < number; i++)
//	{
//		tabs += "\t";
//	}
//	return tabs;
//}
//string ChoiceName(enRockPaperScissors choice) {
//
//	string choiceNames[3] = { "Rock","Paper","Scissors" };
//
//	return choiceNames[choice - 1];
//}
//string WinnerName(enWinner winner) {
//
//	string winnerNames[3] = { "Player","Computer","No Winner" };
//
//	return winnerNames[winner - 1];
//}
//enRockPaperScissors PlayerChoice() {
//	int choice = ReadNumberInRange("Your Choice: \n[1]: Rock\n[2]: Paper\n[3]: Scissors", 1, 3);
//
//	return (enRockPaperScissors)choice;
//}
//enRockPaperScissors ComputerChoice() {
//	return (enRockPaperScissors)RandomNumber(1, 3);
//}
//
//enWinner WhoWonTheGame(stGameResults GameResults) {
//	if (GameResults.playerWinTimes > GameResults.computerWinTimes)
//		return Player;
//	else if (GameResults.playerWinTimes < GameResults.computerWinTimes)
//		return Computer;
//	else
//		return Draw;
//}
//enWinner WhoWonTheRound(enRockPaperScissors playerChoice, enRockPaperScissors computerChoice) {
//	if ((playerChoice == computerChoice)) {
//		return Draw;
//	}
//
//	switch (playerChoice)
//	{
//	case  Rock:
//		switch (computerChoice)
//		{
//		case Paper: return Computer;
//		case Scissors: return Player;
//		}
//
//	case  Paper:
//		switch (computerChoice)
//		{
//		case Rock: return Player;
//		case Scissors: return Computer;
//		}
//
//	case  Scissors:
//		switch (computerChoice)
//		{
//		case Rock: return Computer;
//		case Paper: return Player;
//		}
//
//	}
//
//}
//void SetWinnerScreenColor(enWinner winner) {
//
//	switch (winner) {
//
//	case Player: system("color 2F"); break;
//
//
//	case Computer: system("color 4F"); cout << "\a"; break;
//
//
//	case Draw: system("color 6F"); break;
//
//
//
//	}
//
//}
//void PrintRoundInfo(stRoundInfo Round) {
//
//	cout << "____________Round[" << Round.number << "]_____________\n\n";
//
//	cout << "Player Choice: " << ChoiceName(Round.playerChoice) << endl;
//	cout << "Computer Choice: " << ChoiceName(Round.computerChoice) << endl;
//
//	SetWinnerScreenColor(Round.winner);
//	cout << "Round Winner: [" + WinnerName(Round.winner) + "]\n\n";
//
//	cout << "_________________________________\n\n";
//}
//stRoundInfo PlayRound(int roundNumber) {
//	stRoundInfo Round;
//
//	Round.number = roundNumber;
//	Round.playerChoice = PlayerChoice();
//	Round.computerChoice = ComputerChoice();
//	Round.winner = WhoWonTheRound(Round.playerChoice, Round.computerChoice);
//
//	return Round;
//}
//
//void AddRoundToGameResults(stGameResults& GameResults, stRoundInfo Round) {
//	switch (Round.winner)
//	{
//	case Player:
//		GameResults.playerWinTimes++;
//		break;
//
//	case Computer:
//		GameResults.computerWinTimes++;
//		break;
//
//	case Draw:
//		GameResults.draws++;
//		break;
//
//	}
//}
//
//void PrintGameOverScreen() {
//
//	cout << Tabs(2) + "--------------------------------\n\n" << endl;
//	cout << Tabs(2) + "    +++ G a m e O v e r +++ " << endl;
//	cout << Tabs(2) + "--------------------------------\n\n" << endl;
//	cout << Tabs(2) + "--------[ Game Results ]--------\n\n" << endl;
//	cout << Tabs(2) + "--------------------------------\n\n" << endl;
//}
//void ShowFinalGameResults(stGameResults GameResults) {
//
//
//	SetWinnerScreenColor(GameResults.winner);
//
//
//
//	cout << Tabs(2) << "Game Rounds : " << GameResults.rounds << " \n\n";
//	cout << Tabs(2) << "Player has won : " << GameResults.playerWinTimes << " times \n\n";
//	cout << Tabs(2) << "Computer has won : " << GameResults.computerWinTimes << " times \n\n";
//	cout << Tabs(2) << "Draw has happened : " << GameResults.draws << " times \n\n";
//	cout << Tabs(2) << "Final Winner : [" << WinnerName(GameResults.winner) << "] \n\n";
//
//	cout << Tabs(2) << "--------------------------------\n\n";
//
//}
//
//void ResetScreen() {
//	system("cls");
//	system("color 0F");
//}
//stGameResults PlayGame(int rounds) {
//
//	stGameResults GameResults;
//	GameResults.rounds = rounds;
//
//	for (int i = 1; i <= rounds; i++)
//	{
//		cout << "Round [" << i << "] begins" << endl;
//
//		stRoundInfo Round = PlayRound(i);
//
//		PrintRoundInfo(Round);
//		AddRoundToGameResults(GameResults, Round);
//
//	}
//	GameResults.winner = WhoWonTheGame(GameResults);
//	return GameResults;
//}
//int ReadHowManyRounds() {
//	return ReadNumberInRange("How Many Rounds? pick from 1 to 10", 1, 10);
//}
//void StartGameLoop() {
//	char playAgain = 'Y';
//	do {
//
//		ResetScreen();
//		stGameResults GameResults = PlayGame(ReadHowManyRounds());
//		PrintGameOverScreen();
//		ShowFinalGameResults(GameResults);
//
//
//		cout << "Do you Want To Play Again? y/n" << endl;
//		cin >> playAgain;
//
//	} while (playAgain == 'y' || playAgain == 'Y');
//
//}
//int main() {
//	srand((unsigned)time(NULL));
//	StartGameLoop();
//
//	return 0;
//}