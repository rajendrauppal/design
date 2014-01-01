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


#include "Board.h"


Board * Board::_board = (Board*)0;
size_t Board::_size = 0;


Board::Board(size_t size)
{
    _snakes = GameData::getInstance()->getSnakes(size);
    _ladders = GameData::getInstance()->getLadders(size);
    _size = size;
}


Board::~Board()
{
    GameData::releaseInstance();
}


Board * Board::getBoard(size_t size)
{
    if ( !_board )
        _board = new Board(size);
    return _board;
}


void Board::releaseBoard()
{
    if ( _board ) {
        delete _board;
        _board = (Board*)0;
    }
}


size_t Board::getBoardSize()
{
    return _size;
}


// ~EOF
