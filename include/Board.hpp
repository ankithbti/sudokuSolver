/* 
 * File:   Board.hpp
 * Author: ankithbti
 *
 * Created on 13 June, 2015, 7:21 PM
 */

#ifndef BOARD_HPP
#define	BOARD_HPP

#include <vector>

namespace sudukoSolver {

    const int BOARD_SIZE = 9;

    struct StopPoint {
        int _start;
        int _end;
        int _bCount;

        StopPoint(int s, int e, int count) : _start(s), _end(e), _bCount(count) {

        }
    };

    struct SudukoValue {
        int _val;
        bool _fix;
        int _block;
        //std::vector<int> _valuesTried;

        SudukoValue() : _val(0), _fix(false), _block(0) {

        }

        SudukoValue(int val, bool fix = false) : _val(val), _fix(fix), _block(0) {

        }

    };

    class Board {
    private:

        SudukoValue _board[BOARD_SIZE][BOARD_SIZE];
        int _smallBlockSize;
        int _blocks[BOARD_SIZE];
        std::vector<StopPoint> _rowStopPoints;
        std::vector<StopPoint> _colStopPoints;
        
        void fillBlock(int row, int col);
        
        bool verify(int i, int j, const SudukoValue& val);
    public:
        Board();
        bool verifyAndFill(int row, int col, int num);
        bool solveProblem();
        void printBoard();
        void fillFixBlocks(int row, int col, int num){
            _board[row][col]._val = num;
            _board[row][col]._fix = true;
        }

    };

}

#endif	/* BOARD_HPP */

