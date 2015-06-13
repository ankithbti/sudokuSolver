#include <Board.hpp>
#include <iostream>
#include <boost/foreach.hpp>
#include <math.h>

namespace sudukoSolver
{

Board::Board() : _smallBlockSize(sqrt(BOARD_SIZE))
{
    for (int i = 1; i <= BOARD_SIZE; ++i)
    {
        _blocks[i] = i;
    }

    int rowBlock = 0;
    int colBlock = 0;
    for (int i = 0; i < _smallBlockSize; ++i)
    {
        static int start = 0;
        _rowStopPoints.push_back(StopPoint(start, start + _smallBlockSize - 1, ++rowBlock));
        _colStopPoints.push_back(StopPoint(start, start + _smallBlockSize - 1, colBlock++));
        start = start + _smallBlockSize;
    }

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            SudukoValue val(0);
            _board[i][j] = val;
            fillBlock(i, j);
        }
    }
}

void Board::fillBlock(int i, int j)
{

    BOOST_FOREACH(StopPoint rowStop, _rowStopPoints)
    {

        BOOST_FOREACH(StopPoint colStop, _colStopPoints)
        {
            if ((i >= rowStop._start && i <= rowStop._end) && (j >= colStop._start && j <= colStop._end))
            {
                _board[i][j]._block = rowStop._bCount + _smallBlockSize * colStop._bCount;
            }
        }
    }
}

void Board::printBoard()
{
    std::cout << " ***** Printing your board ******" << std::endl;
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        std::cout << " --- --- --- ---" << std::endl;
        for (int i = 0; i < BOARD_SIZE; ++i)
        {

            std::cout << "|" << _board[j][i]._val << _board[j][i]._fix << _board[j][i]._block;
        }
        std::cout << std::endl;
    }
    std::cout << " *****  ******" << std::endl;
}

bool Board::solveProblem()
{

    int row, col = 0;
    bool finished = true;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (_board[i][j]._val == 0)
            {
                finished = false;
                row = i;
                col = j;
            }
        }
    }
    if (finished)
    {
        return true;
    }

    std::cout << " Checking for " << row << "," << col << std::endl;
    for (int v = 1; v <= BOARD_SIZE; ++v)
    {
        if (verifyAndFill(row, col, v))
        {
            if (solveProblem())
            {
                return true;
            }
            // Backtrack
            if (!_board[row][col]._fix)
            {
                _board[row][col]._val = 0;
            }
        }
    }
    return false;
}

bool Board::verifyAndFill(int i, int j, int num)
{
    if (_board[i][j]._fix)
    {
        std::cout << " Can not change fix value at " << i << "," << j << std::endl;
        return true;
    }


    if (verify(i, j, SudukoValue(num)))
    {
        _board[i][j]._val = num;
        return true;
    }

    return false;
}

bool Board::verify(int i, int j, const SudukoValue& val)
{
    for (int col = 0; col < BOARD_SIZE; ++col)
    {
        if (_board[i][col]._val != 0 && _board[i][col]._val == val._val)
        {
            //std::cout << " Value: " << val._val << " Going to fill in : " << i << "," << j << " , Not unique in Row: " << i << std::endl;
            return false;
        }
    }
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        if (_board[row][j]._val != 0 && _board[row][j]._val == val._val)
        {
            //std::cout << " Value: " << val._val << " Going to fill in : " << i << "," << j << ", Not unique in Column: " << j << std::endl;
            return false;
        }
    }

    for (int col = 0; col < BOARD_SIZE; ++col)
    {
        for (int row = 0; row < BOARD_SIZE; ++row)
        {

            if (_board[row][col]._block == _board[i][j]._block)
            {
                //std::cout << " Checking block : " << _board[row][col]._block << " for " << i << "," << j << " against " << row << "," << col << std::endl;
                if (_board[row][col]._val != 0 && _board[row][col]._val == val._val)
                {
                    //std::cout << " Value: " << val._val << " Going to fill in : " << i << "," << j << " , Not Unique in Small Block " << _board[row][col]._block << std::endl;
                    return false;
                }
            }
        }

    }
    return true;
}


}
