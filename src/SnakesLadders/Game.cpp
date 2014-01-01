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
using std::endl;


Game * Game::_game = (Game*)0;


Game::Game()
{
}


Game::~Game()
{
}


Game * Game::getInstance()
{
    if ( !_game )
        _game = new Game();
    return _game;
}


void Game::releaseInstance()
{
    if ( _game ) { // just to avoid double deletes
        delete _game;
        _game = (Game*)0;
    }
}


void Game::setBoard(size_t size)
{
    _board = Board::getBoard( size );
}


void Game::setPlayer(string name)
{
    Player * player = new Player( name );
    _players.push_back( player );
}


string Game::getWinner() const
{
    string ans;
    Players::const_iterator start = _players.begin();
    Players::const_iterator end = _players.end();

    while ( start != end ) {
        if ( (*start)->hasWon() ) {
            ans = (*start)->getName();
            break;
        }
        ++start;
    }

    return ans;
}


void Game::play()
{
    Player * first = toss();
    cout << "First player to start: " << first->getName() << endl;

    Players::const_iterator start = _players.begin();
    Players::const_iterator end = _players.end();

    while ( (*start) != first )
        start++;

    while ( true ) {
        for ( ; start != end; ++start ) {
            cout << "Now playing: " << (*start)->getName() << endl;
            size_t newpos = (*start)->getDice()->roll();
            size_t sixcount = 0;

            if ( 6 == newpos ) {
                while ( (6 == newpos) && (3 != sixcount) ) {
                    (*start)->move( newpos );
                    newpos = (*start)->getDice()->roll();
                    ++sixcount;
                }
                if ( 3 == sixcount )
                    (*start)->reset();
            }
            else {
                (*start)->move( newpos );
            }

            if ( (*start)->hasWon() )
                return;
        }
        start = _players.begin();
    }
}


Player * Game::toss() const
{
    Players::const_iterator start = _players.begin();
    Players::const_iterator end = _players.end();

    while ( true ) {
        for ( ; start != end; ++start ) {
            size_t face = (*start)->getDice()->roll();
            if ( 6 == face )
                return (*start);
        }
        start = _players.begin();
    }

    return (Player*)0;
}

// ~EOF
