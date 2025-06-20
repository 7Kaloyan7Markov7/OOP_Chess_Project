#include "Drawer_declaration.h"

void Drawer::clearCMD() const
{
	system("cls");
}

void Drawer::stalemateMessage() const
{
	std::wcout << L"Stalemate\n";
}

void Drawer::drawBoard(const Board& board) const
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    clearCMD();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 8; ++i)
    {
        std::wcout << (wchar_t)(L'0' + (8 - i)) << L" ";

        for (int j = 0; j < 8; ++j)
        {
            bool isLightSquare = ((i + j) % 2 == 0);
            int bgColor = isLightSquare ? 4 : 8;

            int fgColor = 15; // default white

            if (auto fig = board.getFigure(i, j)) 
            {
                // Detect piece color (change as needed for your code)
                if (fig->getColor() == ColorType::WHITE) 
                {
                    fgColor = 15; // White pieces
                }
                else 
                {
                    fgColor = 0;  // Black pieces (or 8 for dark gray)
                }
                SetConsoleTextAttribute(hConsole, fgColor | (bgColor << 4));
                std::wcout << fig->getIcon();
            }
            else 
            {
                SetConsoleTextAttribute(hConsole, fgColor | (bgColor << 4));
                std::wcout << L' ';
            }
            std::wcout << L' ';
        }

        // Reset color after each row, optional
        SetConsoleTextAttribute(hConsole, 15 | (0 << 4)); // White on black
        std::wcout << L"\n";
    }

    // Draw letters
    std::wcout << L"  ";
    for (int i = 0; i < 8; ++i)
    {
        std::wcout << (wchar_t)(L'a' + i) << L' ';
    }
    std::wcout << L"\n";

    // Reset color to normal at end
    SetConsoleTextAttribute(hConsole, 15 | (0 << 4));
}

void Drawer::invalidFigureMessage() const
{
	std::wcout << L"You've chosen an invalid piece or its not your turn yet.\n";
}

void Drawer::invalidSquareMessage() const
{
	std::wcout << L"You've chosen an invalid move.\n";
}

void Drawer::displayTurnColor(bool turn) const
{
	std::wcout << (turn ? L"Black's turn\n" : L"White's turn\n");
}

void Drawer::displayCheckmated(bool turn) const
{
	std::wcout << (turn ? L"Black" : L"White") << L" is checkmated!\n";
}