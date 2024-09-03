#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

string Tabs(unsigned short n)
{
	string tabs = "";
	for (unsigned short i = 0; i <= n; i++)
		tabs += "\t";

	return tabs;
}

string Separator(string unit, size_t n)
{
	string separator = "";
	for (unsigned short i = 0; i <= n; i++)
		separator += unit;

	return separator;
}

void DisplaySectionTitle(string SectionTitle)
{
	cout << SectionTitle << "\n";
	cout << Separator("=", SectionTitle.length()) << "\n";
}

void DisplayTitleScreen()
{
	system("Color 0F");		// BG: Black, FG: Bright White

	cout << "Hello and Welcome to \"Math Game\"!" << "\n";
	cout << "No need for unnecessary introductions - just proceed with the instructions provided below:" << "\n";

	cout << endl;
}

void ResetScreen()
{
	system("cls");
	system("Color 0F");		// BG: Black, FG: Bright White
}

int ReadNumberBet(int start, int end, string prompt)
{
	int Number = 0;
	do
	{
		cout << prompt << "\n";
		cin >> Number;
		cout << endl;
	} while (Number < start || Number > end);

	return Number;
}

int ReadNumberofQuestions()
{
	int NumberofQuestions = ReadNumberBet(1, INT_MAX, "Please enter the number of questions you wish to answer in the quiz (maximum " + to_string(INT_MAX) + " questions):");

	return NumberofQuestions;
}

enum DifficultyLevel { Easy = 1, Medium = 2, Hard = 3, All = 4 };
string DifficultyLevels[4] = { "Easy", "Medium", "Hard", "Mix" };

DifficultyLevel ReadDifficultyLevel()
{
	DifficultyLevel Level = DifficultyLevel::All;

	DisplaySectionTitle("Select Difficulty Level");

	cout << endl;

	for (unsigned short i = 0; i < 4; i++)
		cout << "[" << i + 1 << "]" << " " << DifficultyLevels[i] << "\n\n";
	cout << "* The fourth option makes the quiz have a random variation of easy, medium, and hard-level questions." << endl;

	int SelectedLevel = ReadNumberBet(1, 4, "Please enter the number corresponding to the desired difficulty level of the quiz from the list above.");

	cout << endl;

	return DifficultyLevel(SelectedLevel);
}

enum ArithmeticOperation { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, All_ = 5 };
string ArithmeticOperations[5] = { "Addition", "Subtraction", "Multiplication", "Division", "All" };
char ArithOps[4] = { '+', '-', '*', '/' };

ArithmeticOperation ReadArithmeticOperation()
{
	ArithmeticOperation Operation = ArithmeticOperation::All_;

	DisplaySectionTitle("Select Arithmetic Operation");

	cout << endl;

	for (unsigned short i = 0; i < 5; i++)
		cout << "[" << i + 1 << "]" << " " << ArithmeticOperations[i] << "\n\n";
	cout << "* For division operations, round the result up to the nearst integer." << "\n";
	cout << "* The fifth option makes the quiz have a random variation of addition, subtraction, multiplication and division." << endl;

	int SelectedOperation = ReadNumberBet(1, 5, "Please enter the number corresponding to the desired arithmetic operation for the quiz from the list above.");

	cout << endl;

	return ArithmeticOperation(SelectedOperation);
}

int GenerateRandomNumberBet(int start, int end)
{
	return (rand() % (end - start + 1)) + start;
}

struct MGQuiz
{
	int NumberofQuestions;
	DifficultyLevel Level;
	ArithmeticOperation Operation;
	int CorrectAnswers = 0, IncorrectAnswers = 0;
	bool HasBeenPassed;
};

struct MGQuestion
{
	DifficultyLevel Level;
	int Operand1, Operand2;
	ArithmeticOperation Operation;
	int OperationResult, UserResult;
	bool IsAnswerCorrect;
};

void ApplyDifficultyLevel(MGQuestion& Question)
{
	int start, end = 0;

	switch (Question.Level)
	{
	case DifficultyLevel::Easy:
		start = 1; end = 10;
		break;
	case DifficultyLevel::Medium:
		start = 11; end = 50;
		break;
	case DifficultyLevel::Hard:
		start = 50; end = 100;
		break;
	}

	Question.Operand1 = GenerateRandomNumberBet(start, end);
	Question.Operand2 = GenerateRandomNumberBet(start, end);
}

void ApplyArithmeticOperation(int Operand1, int Operand2, MGQuestion& Question)
{
	switch (Question.Operation)
	{
	case ArithmeticOperation::Addition:
		Question.OperationResult = (Operand1 + Operand2);
		return;
	case ArithmeticOperation::Subtraction:
		Question.OperationResult = (Operand1 - Operand2);
		return;
	case ArithmeticOperation::Multiplication:
		Question.OperationResult = (Operand1 * Operand2);
		return;
	case ArithmeticOperation::Division:
		Question.OperationResult = round(Operand1 / double(Operand2));
		return;
	}
}

void DisplayArithmeticOperation(MGQuestion& Question)
{
	printf("  %3i\n", Question.Operand1);
	cout << ArithOps[Question.Operation - 1];
	printf(" %3i\n", Question.Operand2);
	cout << Separator("-", 10) << "\n";
	cout << endl;
	cin >> Question.UserResult;

	/*
	cout << setw(4) << Question.Operand1 << "\n";
	cout << ArithOps[Question.Operation - 1];
	cout << setw(4) << Question.Operand2 << "\n";
	cout << Separator("-", 10) << "\n";
	cout << endl;
	cin >> Question.UserResult;
	*/
}

void IsAnswerCorrect(MGQuestion& Question)
{
	Question.IsAnswerCorrect = (Question.UserResult == Question.OperationResult);
}

void DisplayQuestionResult(MGQuestion& Question)
{
	cout << endl;

	IsAnswerCorrect(Question);

	if (Question.IsAnswerCorrect)
	{
		system("Color 20");
		cout << "Correct Answer :-)" << "\n";
	}
	else
	{
		cout << "\a";
		system("Color 4F");
		cout << "Incorrect Answer :-(" << "\n";
		cout << "Correct Answer: " << Question.OperationResult << "\n";
	}

	cout << endl;
}

void AskQuestion(MGQuestion& Question, MGQuiz& Quiz)
{
	Question.Level = Quiz.Level;

	if (Quiz.Level == DifficultyLevel::All)
		Question.Level = DifficultyLevel(GenerateRandomNumberBet(int(DifficultyLevel::Easy), int(DifficultyLevel::Hard)));

	ApplyDifficultyLevel(Question);

	Question.Operation = Quiz.Operation;

	if (Quiz.Operation == ArithmeticOperation::All_)
		Question.Operation = ArithmeticOperation(GenerateRandomNumberBet(int(ArithmeticOperation::Addition), int(ArithmeticOperation::Division)));

	ApplyArithmeticOperation(Question.Operand1, Question.Operand2, Question);

	DisplayArithmeticOperation(Question);
	DisplayQuestionResult(Question);
}

void IsQuizPassed(MGQuiz& Quiz)
{
	Quiz.HasBeenPassed = (Quiz.CorrectAnswers >= Quiz.IncorrectAnswers);
}

void ResetQuizStats(MGQuiz& Quiz)
{
	Quiz.CorrectAnswers = Quiz.IncorrectAnswers = 0;
}

void DisplayQuizResult(MGQuiz& Quiz)
{
	cout << endl;

	IsQuizPassed(Quiz);

	if (Quiz.HasBeenPassed)
	{
		cout << "\a";
		system("Color 20");
		cout << "Congratulations! You have passed the quiz! :-)" << "\n";
	}
	else
	{
		system("Color 4F");
		cout << "Sorry, You have failed the quiz... :-(" << "\n";
	}

	string h_sep = Separator("-", 51);

	cout << h_sep << "\n";
	cout << setw(30) << left << "Number of Questions" << "|" << setw(20) << left << Quiz.NumberofQuestions << "|" << "\n";
	cout << setw(30) << left << "Difficulty Level" << "|" << setw(20) << left << DifficultyLevels[Quiz.Level - 1] << "|" << "\n";
	cout << setw(30) << left << "Arithmetic Operation(s)" << "|" << setw(20) << left << ArithmeticOperations[Quiz.Operation - 1] << "|" << "\n";
	cout << setw(30) << left << "No. of Correct Answer(s)" << "|" << setw(20) << left << Quiz.CorrectAnswers << "|" << "\n";
	cout << setw(30) << left << "No. of Incorrect Answer(s)" << "|" << setw(20) << left << Quiz.IncorrectAnswers << "|" << "\n";
	cout << h_sep << "\n";

	cout << endl;
}

void AskQuiz(MGQuestion& Question, MGQuiz& Quiz)
{
	Quiz.NumberofQuestions = ReadNumberofQuestions();
	Quiz.Level = ReadDifficultyLevel();
	Quiz.Operation = ReadArithmeticOperation();

	for (int i = 1; i <= Quiz.NumberofQuestions; i++)
	{
		DisplaySectionTitle("Question " + to_string(i) + " of " + to_string(Quiz.NumberofQuestions));
		cout << endl;
		AskQuestion(Question, Quiz);
		if (Question.IsAnswerCorrect)
			Quiz.CorrectAnswers++;
		else
			Quiz.IncorrectAnswers++;
	}

	DisplayQuizResult(Quiz);
}

void MathGame(MGQuestion& Question, MGQuiz& Quiz)
{
	DisplayTitleScreen();

	bool StartNewQuiz = true;

	do
	{
		AskQuiz(Question, Quiz);

		cout << endl;

		cout << "Do you wish to start a new quiz?" << "\n";
		cin >> StartNewQuiz;

		if (StartNewQuiz)
		{
			ResetQuizStats(Quiz);
			ResetScreen();
		}
	} while (StartNewQuiz);
}

int main()
{
	srand(unsigned int(time(NULL)));

	MGQuestion Question;
	MGQuiz Quiz;

	MathGame(Question, Quiz);

	return 0;
}
