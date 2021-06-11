#include "TicTacRandomPlayer.h"

TicTacRandomPlayer::TicTacRandomPlayer()
{

}

TicTacRandomPlayer::~TicTacRandomPlayer()
{

}

bool TicTacRandomPlayer::MakeMove(int Fx)
{
	unsigned int col;
	col = (unsigned int)(rand() % 7);

	if (this->board->CheckLegal(col))
	{
		this->board->SetCell(col, this->cellType);
		return true;
	}
	return false;
}