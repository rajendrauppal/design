/*
The MIT License (MIT)

Copyright (c) 2013 Rajendra Kumar Uppal

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <iostream>
#include "Game.h"


using std::cout;
using std::cin;
using std::endl;


#define print(s) cout<<endl<<(s)<<endl


void Test_Game(size_t size)
{
    cout << "---------------------" << endl;
    cout << "Testing game size: " << size << endl;
    cout << "---------------------" << endl;

    Game * game = Game::getInstance();
    game->setBoard( size ); // allowed sizes are 8x8, 10x10 and 12x12 at present.
    game->setPlayer( "A" );
    game->setPlayer( "B" );
    
    game->play();
    
    string winnerName = game->getWinner();
    if ( !winnerName.empty() )
        cout << endl << endl << "Congratulations " << winnerName << ", You've won!" << endl;
    
    Game::releaseInstance();

    cout << "-------------------------" << endl;
    cout << "End testing game size: " << size << endl;
    cout << "-------------------------" << endl;
}


int main()
{
    Test_Game(8);
    Test_Game(10);
    Test_Game(12);

    print("Press any key to continue...");
    cin.get();
    return 0;
}

// ~EOF
