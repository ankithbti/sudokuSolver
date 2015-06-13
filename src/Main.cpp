#include <iostream>
#include <SudukoBoard.hpp>

int main()
{
    std::cout << "Sududko Solver " << std::endl;
    sudukoSolver::SudukoBoard freshBoard;
    freshBoard.printBoard();
    {

        sudukoSolver::SudukoValue val(4, true);
        freshBoard.fill(0, 3, val);
        freshBoard.fill(2, 1, sudukoSolver::SudukoValue(2, true));
        freshBoard.fill(0, 2, sudukoSolver::SudukoValue(3, true));
        freshBoard.printBoard();


        bool isComplete = false;
        while (true)
        {
            std::cout << " Starting Iteration " << std::endl;
            isComplete = true;
            for (int row = 0; row < sudukoSolver::BOARD_SIZE; ++row)
            {
                for (int col = 0; col < sudukoSolver::BOARD_SIZE; ++col)
                {
                    if (freshBoard._board[row][col]._val == 0)
                    {
                        isComplete = false;
                    }
                }
            }
            
            for (int row = 0; row < sudukoSolver::BOARD_SIZE; ++row)
            {
                for (int col = 0; col < sudukoSolver::BOARD_SIZE; ++col)
                {
                    if (!freshBoard._board[row][col]._fix)
                    {
                        for (int val = 1; val < 5; ++val)
                        {
                            sudukoSolver::SudukoValue value(val, false);
                            if (freshBoard.fill(row, col, value))
                            {
                                //std::cout << " Filled " << std::endl;
                                break;
                            }
                        }
                    }
                }
            }
            freshBoard.printBoard();
        }

        
        std::cout << " Sudoko Solved.... " << std::endl;
        freshBoard.printBoard();


    }
    return 0;
}
