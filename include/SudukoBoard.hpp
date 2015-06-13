/* 
 * File:   SudukoBoard.hpp
 * Author: ankithbti
 *
 * Created on 12 June, 2015, 10:37 PM
 */

#ifndef SUDUKOBOARD_HPP
#define	SUDUKOBOARD_HPP

namespace sudukoSolver {

    struct SudukoValue {
        int _val;
        bool _fix;
        int _block;

        SudukoValue() : _val(0), _fix(false), _block(0) {

        }

        SudukoValue(int val, bool fix) : _val(val), _fix(fix), _block(0) {
            
        }
        
    };

    const int BOARD_SIZE = 4;

    class SudukoBoard {
    public:
        SudukoValue _board[4][4];
        int _smallBlockSize;
    public:
        SudukoBoard();

        void printBoard();

        bool fill(int row, int col, SudukoValue val);
    };

}

#endif	/* SUDUKOBOARD_HPP */

