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


#include "Player.h"
#include "Board.h"
#include "GameData.h"
#include <iostream>


using std::cout;
using std::endl;


Player::Player():
    _position(0),
    _name(""),
    _reset(false),
    _winner(false)
{
    _boardsize = Board::getBoardSize();
}


Player::Player(string name):
    _position(0),
    _name(name),
    _reset(false),
    _winner(false)
{
    _boardsize = Board::getBoardSize();
}


Player::~Player()
{
}


void Player::move(size_t count)
{
    size_t candidate_pos = _position + count;

    if ( GameData::isSnakeMouth( candidate_pos ) ) {
        _position = GameData::getSnakeTail( candidate_pos );
        cout << endl << getName() << " got Snake bite!!! going down to... " << _position << endl;
    }
    else if ( GameData::isLadderTail( candidate_pos ) ) {
        _position = GameData::getLadderHead( candidate_pos );
        cout << endl << getName() << " hit Ladder!!! going up to... " << _position << endl;
    }
    else
        _position += count;

    // see if 'this' player is winning by current move.
    if ( _position >= (_boardsize * _boardsize) )
        _winner = true;
}


void Player::reset()
{
    _position = 1;
    _reset = true;
}


bool Player::hasWon() const
{
    return _winner;
}


Dice * Player::getDice() const
{
    return Dice::get();
}


string Player::getName() const
{
    return _name;
}


size_t Player::getCurrentPosition() const
{
    return _position;
}


// ~EOF
