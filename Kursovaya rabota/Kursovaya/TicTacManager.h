#pragma once
#include "pch.h"
#include "TicTacBoard.h"
#include "TicTacPlayer.h"

class TicTacManager
{
private:
	TicTacBoard* board;
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	bool bGameFinished = false;
	bool BotOn;
public:
	TicTacManager();
	virtual ~TicTacManager();
	//void ShowBoard();
	bool Init(string nameP1, string nameP2, bool BotP2);
	bool MakeMove(int Fx);
	bool isbGameFinished();
	CellType CheckCellType(int x, int y);
	bool GetbGameFinished() { return bGameFinished; };
	string GetWinnerName() { return this->currentPlayer->GetName(); };
	void CleanUp();
};


