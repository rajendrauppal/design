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


#include "GameData.h"


using std::vector;
using std::pair;


GameData * GameData::_gamedata = 0;
GameData::SnakesMap GameData::_snakesMap;
GameData::LaddersMap GameData::_laddersMap;
GameData::Snakes GameData::_snakes;
GameData::Ladders GameData::_ladders;


GameData::GameData()
{
    // 8
    Snakes snakes;
    snakes.push_back( Snake(24, 7) );
    snakes.push_back( Snake(31, 16) );
    snakes.push_back( Snake(38, 6) );
    snakes.push_back( Snake(47, 33) );
    snakes.push_back( Snake(54, 20) );
    snakes.push_back( Snake(62, 4) );
    _snakesMap[8] = snakes;

    Ladders ladders;
    ladders.push_back( Ladder(15, 30) );
    ladders.push_back( Ladder(21, 60) );
    ladders.push_back( Ladder(23, 56) );
    ladders.push_back( Ladder(35, 49) );
    ladders.push_back( Ladder(43, 55) );
    _laddersMap[8] = ladders;

    // 10
    snakes.clear();
    snakes.push_back( Snake(17, 7) );
    snakes.push_back( Snake(54, 34) );
    snakes.push_back( Snake(62, 19) );
    snakes.push_back( Snake(64, 60) );
    snakes.push_back( Snake(87, 24) );
    snakes.push_back( Snake(93, 73) );
    snakes.push_back( Snake(95, 75) );
    snakes.push_back( Snake(99, 78) );
    _snakesMap[10] = snakes;

    ladders.clear();
    ladders.push_back( Ladder(4, 14) );
    ladders.push_back( Ladder(9, 31) );
    ladders.push_back( Ladder(20, 38) );
    ladders.push_back( Ladder(40, 49) );
    ladders.push_back( Ladder(51, 67) );
    ladders.push_back( Ladder(63, 81) );
    ladders.push_back( Ladder(28, 84) );
    _laddersMap[10] = ladders;

    // 12
    snakes.clear();
    snakes.push_back( Snake(19, 9) );
    snakes.push_back( Snake(54, 36) );
    snakes.push_back( Snake(66, 23) );
    snakes.push_back( Snake(69, 63) );
    snakes.push_back( Snake(91, 27) );
    snakes.push_back( Snake(95, 79) );
    snakes.push_back( Snake(99, 71) );
    snakes.push_back( Snake(105, 68) );
    snakes.push_back( Snake(119, 65) );
    snakes.push_back( Snake(143, 10) );
    _snakesMap[12] = snakes;

    ladders.clear();
    ladders.push_back( Ladder(6, 18) );
    ladders.push_back( Ladder(9, 35) );
    ladders.push_back( Ladder(17, 39) );
    ladders.push_back( Ladder(45, 54) );
    ladders.push_back( Ladder(59, 67) );
    ladders.push_back( Ladder(69, 81) );
    ladders.push_back( Ladder(31, 64) );
    ladders.push_back( Ladder(71, 101) );
    ladders.push_back( Ladder(93, 129) );
    _laddersMap[12] = ladders;
}


GameData::~GameData()
{
}


GameData * GameData::getInstance()
{
    if ( !_gamedata )
        _gamedata = new GameData();
    return _gamedata;
}


void GameData::releaseInstance()
{
    if ( !_gamedata ) { // just to avoid double deletes
        delete _gamedata;
        _gamedata = 0;
    }
}


GameData::Snakes& GameData::getSnakes(size_t size)
{
    _snakes = _snakesMap[size];
    return _snakes;
}


GameData::Ladders& GameData::getLadders(size_t size)
{
    _ladders = _laddersMap[size];
    return _ladders;
}


// ~EOF
