
#include "pch.h"
#include "TicTacManager.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0)); //Чтобы компьютер не повторялся в новой сессии

    TicTacManager manager;
    while (!manager.isbGameFinished())
    {
        manager.MakeMove();
    }

}