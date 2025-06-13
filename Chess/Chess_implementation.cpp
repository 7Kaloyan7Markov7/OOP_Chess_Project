#include <iostream>
#include "Chess_declaration.h"
#pragma warning (disable : 4996)

void Chess::gameOn()
{
    String currentPlayerFromInput;
    String currentPlayerToInput;

    while (handler.getIsRunning())
    {
        board.printBoard();

       



        currentPlayerFromInput = handler.getTurn() ? black.readFromInput() : white.readFromInput();

        if (!handler.validateInputFrom(currentPlayerFromInput,board))
        {   
            std::wcout << L"Invalid figure\n";
            continue;
        }

        handler.setFigureSelection(true);
        while (handler.getIsFigureSelected())
        {
          

            currentPlayerToInput = handler.getTurn() ? black.readToInput() : white.readToInput();
            if (!handler.validateInputTo(currentPlayerFromInput, currentPlayerToInput, board))
            {
                std::wcout << L"invalid cell\n";
            }
            board.move(currentPlayerFromInput, currentPlayerToInput);

            handler.setFigureSelection(false);
        }

        handler.setTurn(!handler.getTurn());
    }
}

Chess::Chess() : white(ColorType::WHITE), black(ColorType::BLACK)
{

}

Chess::~Chess() = default;

Chess& Chess::getInstance()
{
	static Chess instance;

	return instance;
}