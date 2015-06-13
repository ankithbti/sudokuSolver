#include <iostream>
//#include <SudukoBoard.hpp>

#include "Board.hpp"

int main()
{
    sudukoSolver::Board b;
    b.printBoard();
    if(b.solveProblem()){
        std::cout << " Got Solution " << std::endl;
    }else{
        std::cout << " No Solution " << std::endl;
    }
    b.printBoard();
    return 0;
    
//    std::cout << "Sududko Solver " << std::endl;
//    //sudukoSolver::SudukoBoard freshBoard;
//    try{
//    sudukoSolver::Board freshBoard;
//    freshBoard.printBoard();
//   
//    if(freshBoard.solveProblem(0)){
//        std::cout << " Board Solved. " << std::endl;
//    }else{
//        std::cout << " Not Solved. " << std::endl;
//    }
//    freshBoard.printBoard();
//    }catch(std::exception& err){
//        std::cout << " Error: " << err.what() << std::endl;
//    }
//    return 0 ;
//    {
//
//        //freshBoard.fill(0, 0, sudukoSolver::SudukoValue(2, true));
//        //freshBoard.fill(0, 3, sudukoSolver::SudukoValue(4, true));
//        //freshBoard.fill(3, 2, sudukoSolver::SudukoValue(1, true));
//        //freshBoard.fill(1, 2, sudukoSolver::SudukoValue(1, true));
//        //freshBoard.fill(2, 3, sudukoSolver::SudukoValue(2, true));
//        //freshBoard.fill(3, 3, sudukoSolver::SudukoValue(1, true));
//        //freshBoard.printBoard();
//
//        /*
//        bool isComplete = false;
//        int beginVal = 0;
//        while (!isComplete)
//        {
//            std::cout << " Starting Iteration " << std::endl;
//            isComplete = true;
//            for (int row = 0; row < sudukoSolver::BOARD_SIZE; ++row)
//            {
//                for (int col = 0; col < sudukoSolver::BOARD_SIZE; ++col)
//                {
//                    if (freshBoard._board[row][col]._val == 0)
//                    {
//                        isComplete = false;
//                    }
//                }
//            }
//            ++beginVal;
//            if(beginVal > sudukoSolver::BOARD_SIZE){
//                beginVal = 1;
//                //std::cout << " No Solution to this puzzle...Hands down... " << std::endl;
//                //break;
//            }
//            for (int row = 0; row < sudukoSolver::BOARD_SIZE; ++row)
//            {
//                for (int col = 0; col < sudukoSolver::BOARD_SIZE; ++col)
//                {
//                    if (!freshBoard._board[row][col]._fix)
//                    {
//                        for (int val = beginVal; val <= sudukoSolver::BOARD_SIZE; ++val)
//                        {
//                            sudukoSolver::SudukoValue value(val);
//                            if (freshBoard.fill(row, col, value))
//                            {
//                                //std::cout << " Filled " << std::endl;
//                                break;
//                            }
//                        }
//                        for (int val = 0; val < beginVal; ++val)
//                        {
//                            sudukoSolver::SudukoValue value(val);
//                            if (freshBoard.fill(row, col, value))
//                            {
//                                //std::cout << " Filled " << std::endl;
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//            freshBoard.printBoard();
//        }
//
//        
//        std::cout << " Sudoko Solved.... " << std::endl;
//        freshBoard.printBoard();
//         * */
//
//    }
}
