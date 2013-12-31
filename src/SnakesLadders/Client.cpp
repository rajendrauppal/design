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
#include "Dice.h"
#include "Player.h"
#include "Board.h"


using std::cout;
using std::cin;
using std::endl;


#define print(s) cout<<endl<<(s)<<endl


void Test_Dice()
{
    Dice * d = Dice::get();
    for ( size_t i = 0; i < 1000; ++i )
        cout << d->roll() << " ";
    cout << endl;
    cout << d->face() << endl;
    cout << d->count() << endl;

    d->put();
}


void Test_Player()
{
    Player p1, p2;

    size_t face = p1.getDice()->roll();
    p1.move(face);
    
    face = p2.getDice()->roll();
    p2.move(face);
}


void Test_Board()
{
    Board * board = Board::getBoard(8);
    Board::releaseBoard();
    cout << board << endl;
}


int main()
{
    Test_Dice();
    Test_Player();
    Test_Board();

    print("Press any key to continue...");
    cin.get();
    return 0;
}


// ~EOF
