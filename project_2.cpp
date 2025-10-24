#include <iostream>
#include <string>
using namespace std;

enum enPassFail {
	Pass = 1, Fail = 2
};
enum enOpType {
	Add = 1, Subtract = 2, Multiply = 3, Divide = 4, MixOpType = 5
};
enum enDifficulty {
	Easy = 1, Medium = 2, Hard = 3, MixDifficulty = 4
};
struct stGameSettings {
	int totalQuestions = 0;
	enOpType opType = MixOpType;
	enDifficulty difficulty = MixDifficulty;
};
struct stQuestionInfo {
	int number = 0;
	int playerAnswer = 0;
	int correctAnswer = 0;
	int number1 = 0;
	int number2 = 0;
	enOpType opType = MixOpType;
	enPassFail PassFail = Pass;
};
struct stGameResults {
	int totalQuestions = 0;
	int playerWinTimes = 0;
	int playerLoseTimes = 0;
	enPassFail PassFail = Pass;
};
void ResetScreen() {
	system("cls");
	system("color 0F");
}
int RandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}
int ReadNumberInRange(string message, int from, int to) {
	int number = 0;
	do {

		cout << message << endl;

		cin >> number;
	} while (number < from || number > to);	return number;

}
string Tabs(int number) {
	string tabs = "";
	for (int i = 1; i < number; i++)
	{
		tabs += "\t";
	}
	return tabs;
}
string PassedOrFailed(enPassFail winner) {

	string winnerNames[2] = { "You Have Passed","You Have Failed" };

	return winnerNames[winner - 1];
}
void PrintQuestionExpression(stQuestionInfo Question) {
	switch (Question.opType)
	{
	case Add:
		cout << Question.number1 << " + " << Question.number2 << endl; break;
	case Subtract:
		cout << Question.number1 << " - " << Question.number2 << endl; break;
	case Multiply:
		cout << Question.number1 << " * " << Question.number2 << endl; break;
	case Divide:
		cout << Question.number1 << " + " << Question.number2 << endl; break;

	}
}
int PlayerAnswer(stQuestionInfo question) {
	PrintQuestionExpression(question);

	int answer = ReadNumberInRange("Whats the result of this expression?", INT_MIN, INT_MAX);

	return answer;
}
int CorrectAnswer(enOpType OperationType, int number1, int number2) {

	if (OperationType == Add)
		return number1 + number2;
	else if (OperationType == Subtract)
		return number1 - number2;
	else if (OperationType == Multiply)
		return number1 * number2;
	else
		return number1 / number2;

}

enPassFail WhoWonTheGame(stGameResults GameResults) {
	if (GameResults.playerWinTimes > GameResults.playerLoseTimes)
		return Pass;
	else if (GameResults.playerWinTimes < GameResults.playerLoseTimes)
		return Fail;
	else
		return Pass;
}
enPassFail IsTheAnswerCorrect(int playerAnswer, int correctAnswer) {
	if (playerAnswer == correctAnswer) {
		return Pass;
	}

	return Fail;

}
void SetWinnerScreenColor(enPassFail PassOrFail) {
	if (PassOrFail == Pass)
		system("color 2F");
	else
		system("color 4F"); cout << "\a";
}


void PrintQuestionInfo(stQuestionInfo Question) {

	cout << "____________Question[" << Question.number << "]_____________\n\n";
	PrintQuestionExpression(Question);
	cout << "Player Answer: " << Question.playerAnswer << endl;
	cout << "Correct Answer: " << Question.correctAnswer << endl;

	SetWinnerScreenColor(Question.PassFail);

	cout << "_________________________________\n\n";
}
int GenerateNumberByDifficulty(enDifficulty difficulty) {
	if (difficulty == Easy)
		return RandomNumber(1, 10);
	else if (difficulty == Medium)
		return RandomNumber(10, 50);
	else
		return RandomNumber(50, 100);

}
enDifficulty GetDifficulty(enDifficulty difficulty) {

	if (difficulty == enDifficulty::MixDifficulty) {
		return (enDifficulty)RandomNumber(1, 3);
	}
	else {
		return difficulty;
	}

}
enOpType GetOperationType(enOpType OpType) {

	if (OpType == enOpType::MixOpType) {
		return (enOpType)RandomNumber(1, 4);
	}
	else {
		return OpType;
	}

}
string PrintQuestion(stQuestionInfo Question) {
	switch (Question.opType)
	{
	case Add:
		return Question.number1 + " + " + Question.number2;
	case Subtract:
		return Question.number1 + " - " + Question.number2;
	case Multiply:
		return Question.number1 + " * " + Question.number2;
	case Divide:
		return Question.number1 + " / " + Question.number2;

	}
}
stQuestionInfo PlayQuestion(stGameSettings GameSettings, int number) {
	stQuestionInfo Question;
	enDifficulty difficulty = GetDifficulty(GameSettings.difficulty);
	Question.opType = GetOperationType(GameSettings.opType);

	Question.number1 = GenerateNumberByDifficulty(difficulty);
	Question.number2 = GenerateNumberByDifficulty(difficulty);




	Question.number = number;
	Question.playerAnswer = PlayerAnswer(Question);
	Question.correctAnswer = CorrectAnswer(Question.opType, Question.number1, Question.number2);

	Question.PassFail = IsTheAnswerCorrect(Question.playerAnswer, Question.correctAnswer);

	return Question;
}

void AddQuestionToGameResults(stGameResults& GameResults, stQuestionInfo Question) {
	if (Question.PassFail == Pass)
		GameResults.playerWinTimes++;
	else
		GameResults.playerLoseTimes++;
}

void PrintGameOverScreen() {

	cout << Tabs(2) + "--------------------------------\n\n" << endl;
	cout << Tabs(2) + "    +++ G a m e O v e r +++ " << endl;
	cout << Tabs(2) + "--------------------------------\n\n" << endl;
	cout << Tabs(2) + "--------[ Game Results ]--------\n\n" << endl;
	cout << Tabs(2) + "--------------------------------\n\n" << endl;
}
void ShowFinalGameResults(stGameResults GameResults) {


	SetWinnerScreenColor(GameResults.PassFail);



	cout << Tabs(2) << "How Many Questions In The Quiz : " << GameResults.totalQuestions << " \n\n";
	cout << Tabs(2) << "Player has Answered : " << GameResults.playerWinTimes << " questions \n\n";
	cout << Tabs(2) << "Player has Failed : " << GameResults.playerLoseTimes << " questions \n\n";
	cout << Tabs(2) << "The Result Of The Exam : " << PassedOrFailed(GameResults.PassFail) << " \n\n";

	cout << Tabs(2) << "--------------------------------\n\n";

}


stGameResults PlayGame(stGameSettings GameSettings) {

	stGameResults GameResults;
	GameResults.totalQuestions = GameSettings.totalQuestions;


	for (int i = 1; i <= GameSettings.totalQuestions; i++)
	{
		cout << "Question [" << i << "/" << GameSettings.totalQuestions << "] " << endl;

		stQuestionInfo Question = PlayQuestion(GameSettings, i);

		PrintQuestionInfo(Question);
		AddQuestionToGameResults(GameResults, Question);

	}
	GameResults.PassFail = WhoWonTheGame(GameResults);
	return GameResults;
}
int ReadHowManyQuestions() {
	return ReadNumberInRange("How Many Questions?", 1, INT_MAX);
}

enDifficulty ReadDifficultyOfQuestions() {

	string message = "Enter The Difficulty Of The Questions \n[1] Easy , [2] Medium ,[3] Hard,[4] Mix";

	return (enDifficulty)ReadNumberInRange(message, 1, 4);
}

enOpType ReadOpTypeOfQuestions() {
	string message = "Enter The Operation Type Of The Questions \n[1] Add ,[2] Subtract ,[3] Multiply ,[4] Divide ,[5] Mix";

	return (enOpType)ReadNumberInRange(message, 1, 5);
}
void StartGameLoop() {
	char playAgain = 'Y';

	do {
		ResetScreen();
		stGameSettings GameSettings;
		GameSettings.totalQuestions = ReadHowManyQuestions();
		GameSettings.difficulty = ReadDifficultyOfQuestions();
		GameSettings.opType = ReadOpTypeOfQuestions();
		stGameResults GameResults = PlayGame(GameSettings);

		PrintGameOverScreen();
		ShowFinalGameResults(GameResults);


		cout << "Do you Want To Play Again? y/n" << endl;
		cin >> playAgain;

	} while (playAgain == 'y' || playAgain == 'Y');

}
int main() {
	srand((unsigned)time(NULL));
	StartGameLoop();

	return 0;
}