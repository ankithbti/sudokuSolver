#include <SudukoBoard.hpp>
#include <iostream>
#include <cmath>

namespace sudukoSolver
{

SudukoBoard::SudukoBoard()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            SudukoValue val(0, false);
            _board[i][j] = val;
            if (i < 2 && j < 2)
            {
                _board[i][j]._block = 1;
            }
            else if (i < 2 && j >= 2)
            {
                _board[i][j]._block = 2;
            }
            else if (i >= 2 && j < 2)
            {
                _board[i][j]._block = 3;
            }
            else if (i >= 2 && j >= 2)
            {
                _board[i][j]._block = 4;
            }
        }
    }
    _smallBlockSize = std::sqrt(BOARD_SIZE);
    std::cout << " Small BoardSize : " << _smallBlockSize << std::endl;
}

void SudukoBoard::printBoard()
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

bool SudukoBoard::fill(int i, int j, SudukoValue val)
{
    if(_board[i][j]._fix){
        std::cout << " Can not change fix value. " << std::endl;
        return true;
    }
    for (int col = 0; col < BOARD_SIZE; ++col)
    {
        if (_board[i][col]._val != 0 &&  _board[i][col]._val == val._val)
        {
            std::cout << " Value: " << val._val << " Going to fill in : " << i << "," << j << " , Not unique in Row: " << i << std::endl;
            return false;
        }
    }
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        if (_board[row][j]._val != 0 && _board[row][j]._val == val._val)
        {
            std::cout << " Value: " << val._val << " Going to fill in : " << i << "," << j << ", Not unique in Column: " << j << std::endl;
            return false;
        }
    }

    for (int col = 0; col < BOARD_SIZE; ++col)
    {
        for (int row = 0; row < BOARD_SIZE; ++row)
        {

            if(_board[row][col]._block == _board[i][j]._block){
                std::cout << " Checking block : " << _board[row][col]._block << " for " << i << "," << j << " against " << row << "," << col << std::endl;
                if(_board[row][col]._val != 0 && _board[row][col]._val == val._val){
                    std::cout << " Value: " << val._val << " Going to fill in : " << i << "," << j << " , Not Unique in Small Block " << _board[row][col]._block << std::endl;
                    return false;
                }
            }
        }

    }
    _board[i][j]._val = val._val;
    _board[i][j]._fix = val._fix;
    return true;
}


}