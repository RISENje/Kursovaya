#pragma once
#include "TicTacBoard.h"
#include "pch.h"

class TicTacPlayer
{
protected:
	TicTacBoard* board;
	CellType cellType;
	string name;
public:
	void SetupPlayer(string name, CellType cellType);
	void SetBoard(TicTacBoard* board);
	virtual bool MakeMove(int Fx) = 0;
	string GetName();
};

