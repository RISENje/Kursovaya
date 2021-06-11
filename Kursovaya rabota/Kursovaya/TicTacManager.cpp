#include "TicTacManager.h"
#include "TicTacPlayer.h"
#include "TicTacHumanPlayer.h"
#include "TicTacComputerPlayer.h"

TicTacManager::TicTacManager()
{
}

TicTacManager::~TicTacManager()
{
	delete this->player1;
	delete this->player2;
	delete this->board;
}

//void TicTacManager::ShowBoard()
//{
//	//this->board->Show();
//}

bool TicTacManager::Init(string nameP1, string nameP2, bool BotP2)
{
	BotOn = BotP2;
	string playerName = nameP1;
	this->board = new TicTacBoard(10, 7);
	//cout << " Введите тип игрока #1 (1 - Человек, любое другое число - Компьютер) : ";
	//cin >> playerType;
	// бот для 1 игрока отключен
	//if (!BotOn)
		this->player1 = new TicTacHumanPlayer();
		player1->SetupPlayer(playerName, CellType_X);
		player1->SetBoard(this->board);
	//else
		//this->player1 = new TicTacComputerPlayer();
	//cout << " Введите тип игрока #2 (1 - Человек, любое другое число - Компьютер) : ";
	//cin >> playerType;
	playerName = nameP2;
	if (!BotOn)
		this->player2 = new TicTacHumanPlayer();
	else
		this->player2 = new TicTacComputerPlayer();
	//cin.ignore();
	//cout << " Введите имя игрока, играещего X : ";
	//getline(cin, playerName);
	
	//cout << " Введите имя игрока, играещего O : ";
	//getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);
	player2->SetBoard(this->board);
	currentPlayer = player1;
	return true;
}

bool TicTacManager::MakeMove(int Fx)
{
	//const string line = "\n---------------------------\n";
	//ShowBoard();
	if (!currentPlayer->MakeMove(Fx))
	{
		//cout << " Недопустимый ход попробуйте ещё раз\n\n";
		//ShowBoard();
		return false;
	}

	if (this->board->CheckEndCondition())
	{
		//ShowBoard();
		//if (this->board->isVictory())
			//cout << line << " Игрок " << currentPlayer->GetName() << " победил!" << line;
		//else
			//cout << line << " Ничья!" << line;
		this->bGameFinished = true;
		return true;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool TicTacManager::isbGameFinished()
{
	return bGameFinished;
}

CellType TicTacManager::CheckCellType(int x, int y)
{
	return this->board->CheckCellType(x, y);
}

void TicTacManager::CleanUp()
{
	if (player1 != nullptr)
	{
		delete player1;
		player1 = nullptr;
	}
	if (player2 != nullptr)
	{
		delete player2;
		player2 = nullptr;
	}
	if (board != nullptr)
	{
		delete board;
		board = nullptr;
	}
		currentPlayer = nullptr;
}
