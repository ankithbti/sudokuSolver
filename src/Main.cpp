#include <iostream>
//#include <SudukoBoard.hpp>

#include "Board.hpp"
#include <SudokuHttpHandler.hpp>
#include <HttpServer.hpp>
#include <TestInterface.hpp>
#include <HamiltonCycle.hpp>

const int SIZE = 3;
const int ARRAY_SIZE = SIZE * 2;
int array[ARRAY_SIZE];

void init()
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = 0;
    }
    
}

void print()
{
    
    std::cout << std::endl;    
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << array[i] << " | ";
    }
    std::cout << std::endl;
}

bool verifyAndFill(int index, int val)
{
    for(int i =0 ; i < ARRAY_SIZE ; ++i){
        if(array[i] == val){
            return false;
        }
    }
    if( (index+val+1) >= ARRAY_SIZE){
        return false;
    }
    if(array[index+val+1] != 0){
        return false;
    }
    array[index] = val;
    array[index+val+1] = val;
    return true;
}

bool solve()
{
    print();
    bool isComplete = true;
    int index = 0 ;
    for(int i = ARRAY_SIZE - 1 ; i >= 0 ; --i ){
        if(array[i] == 0){
            isComplete = false; 
            index = i ;
        }
    }
    if(isComplete){
        return true;
    }

    std::cout << "For Index: " << index << std::endl;
    for(int val  = 1 ; val <= SIZE ; ++val){
        std::cout << " -- Trying Value: " << val << " for Index: " << index << std::endl;
        if(verifyAndFill(index, val)){
            std::cout << " Recursion " << std::endl;
            if(solve()){
                return true;
            }
            array[index] = 0 ;
            array[index+val+1] = 0 ;           
        }else{
            std::cout << " No Recursion " << std::endl;
        }
    }
    return false;
}

int main()
{
    
    sudukoSolver::TestInterface<int> t;
    std::cout << t.getVal() << std::endl;
    
    sudukoSolver::HamiltonCycle hc;
    hc.printGraph();
    
    hc.setEdge(0,1);
    hc.setEdge(1,2);
    hc.setEdge(0,2);
    hc.setEdge(0,3);
    hc.setEdge(2,3);
    
    hc.printGraph();
    
    if(hc.hamiltonPath(-1)){
        std::cout << " Got Solution " << std::endl;
    }else{
        std::cout << " No Solution " << std::endl;
    }
    
    hc.printGraph();
    
    
    return 0;
    sudukoSolver::Board bo;
    std::string port("1234");
    std::string docRoot("/Users/ankithbti/Development/Cpp/httpServer");
    httpServer::HttpReqHandlerInterface::SmartPtr reqHandler(new sudukoSolver::SudokuHttpHandler(docRoot, bo));
    httpServer::HttpServer server(port, reqHandler);
    server.start();

    try
    {
        while (true)
        {
            boost::this_thread::sleep(boost::posix_time::seconds(1));
        }
    }
    catch (const boost::thread_interrupted& err)
    {
        std::cout << " Stopping the Server. " << std::endl;
    }

    server.stop();

    return 0;
    init();
    print();
    std::cout << std::endl;
    if(solve()){
        std::cout << " Got Solution . " << std::endl;
        print();
    }else{
        std::cout <<  " No Solution. " << std::endl;
        print();
    }
    //return 0;
    sudukoSolver::Board b;
    b.fillFixBlocks(0, 2, 7);
    b.fillFixBlocks(0, 4, 6);
    b.fillFixBlocks(0, 6, 4);
    b.fillFixBlocks(0, 7, 2);
    b.fillFixBlocks(1, 0, 2);
    b.fillFixBlocks(1, 2, 6);
    b.fillFixBlocks(1, 3, 4);
    b.fillFixBlocks(2, 0, 3);
    b.fillFixBlocks(2, 3, 7);
    b.fillFixBlocks(2, 7, 6);
    b.fillFixBlocks(2, 8, 1);
    b.fillFixBlocks(3, 6, 1);
    b.fillFixBlocks(3, 7, 3);
    b.fillFixBlocks(4, 0, 8);

    b.fillFixBlocks(4, 4, 5);
    b.fillFixBlocks(4, 8, 6);
    b.fillFixBlocks(5, 1, 7);
    b.fillFixBlocks(5, 2, 5);
    b.fillFixBlocks(6, 0, 4);
    b.fillFixBlocks(6, 1, 9);
    b.fillFixBlocks(6, 5, 5);
    b.fillFixBlocks(6, 8, 2);
    b.fillFixBlocks(7, 5, 2);
    b.fillFixBlocks(7, 6, 9);
    b.fillFixBlocks(7, 8, 4);
    b.fillFixBlocks(8, 1, 2);
    b.fillFixBlocks(8, 2, 8);
    b.fillFixBlocks(8, 4, 7);
    b.fillFixBlocks(8, 6, 6);



    b.printBoard();
    if (b.solveProblem())
    {
        std::cout << " Got Solution " << std::endl;
    }
    else
    {
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
