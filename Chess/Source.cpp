#include <iostream>
#include "Parser_declaration.h"
#include "Chess_declaration.h"
#include <io.h>    
#include <fcntl.h> 

int main() 
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    Chess& chess = Chess::getInstance();

    chess.gameOn();


    return 0;
}