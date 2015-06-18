/* 
 * File:   TestInterface.hpp
 * Author: ankithbti
 *
 * Created on 16 June, 2015, 9:41 PM
 */

#ifndef TESTINTERFACE_HPP
#define	TESTINTERFACE_HPP

namespace sudukoSolver {

    template <typename T>
    class TestInterface {
    public:

        TestInterface() {
            std::cout << " Test Interface Constructor. " << std::endl;
            val = 10;
        }

        T val;

        T getVal() {
            return val;
        }
    };

}

#endif	/* TESTINTERFACE_HPP */

