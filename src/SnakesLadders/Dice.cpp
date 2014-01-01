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


#include "Dice.h"
#include <cstdlib>
#include <ctime>


Dice * Dice::_dice = (Dice*)0;


Dice::Dice():
    _face(0),
    _range(1, 6)
{
}


Dice::~Dice()
{
}


Dice * Dice::get()
{
    if ( !_dice )
        _dice = new Dice();
    return _dice;
}


void Dice::put()
{
    if ( _dice ) { // just to avoid double deletes
        delete _dice;
        _dice = (Dice*)0;
    }
}


size_t Dice::roll()
{
    srand( (unsigned int)time(NULL) );
    _face = (rand() % 6) + 1;
    return _face;
}


size_t Dice::face() const
{
    return _face;
}


// ~EOF
