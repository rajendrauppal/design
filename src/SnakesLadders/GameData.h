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


#ifndef GameData_INCLUDED
#define GameData_INCLUDED


#include <map>
#include <vector>


class GameData
{
public:
    typedef std::map<size_t, std::vector<std::pair<size_t, size_t> > > SnakesMap;
    typedef std::map<size_t, std::vector<std::pair<size_t, size_t> > > LaddersMap;
    typedef std::vector<std::pair<size_t, size_t> > Snakes;
    typedef std::vector<std::pair<size_t, size_t> > Ladders;
    typedef std::pair<size_t, size_t> Snake;
    typedef std::pair<size_t, size_t> Ladder;

    static GameData * getInstance();
    static void releaseInstance();

    static Snakes& getSnakes(size_t size);
    static Ladders& getLadders(size_t size);

private:
    static GameData * _gamedata;

    static SnakesMap _snakesMap;
    static LaddersMap _laddersMap;
    static Snakes _snakes;
    static Ladders _ladders;

    GameData();
    ~GameData();
    GameData(const GameData&);
    GameData& operator = (const GameData&);
};


#endif // GameData_INCLUDED
