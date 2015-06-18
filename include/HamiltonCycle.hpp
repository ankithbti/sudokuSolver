/* 
 * File:   HamiltonCycle.hpp
 * Author: ankithbti
 *
 * Created on 16 June, 2015, 10:52 PM
 */

#ifndef HAMILTONCYCLE_HPP
#define	HAMILTONCYCLE_HPP

#include <iostream>

namespace sudukoSolver {

    const int VERTEX_COUNT = 4;

    class HamiltonCycle {
    public:

        // Undirected Graph
        int graph[VERTEX_COUNT][VERTEX_COUNT];

        int hamiltonPathArray[VERTEX_COUNT];
        
        int orderArray[VERTEX_COUNT];
        int order;

        HamiltonCycle() : order(-1) {
            for (int i = 0; i < VERTEX_COUNT; ++i) {
                hamiltonPathArray[i] = 0;
                orderArray[i] = 0;
                for (int j = 0; j < VERTEX_COUNT; ++j) {
                    graph[i][j] = 0;
                }
            }
        }

        void setEdge(int i, int j) {
            graph[i][j] = 1;
            graph[j][i] = 1;
        }

        bool isSafe(int vertex, int& prevVertex) {
            if (prevVertex == -1) {
                prevVertex = vertex;
                hamiltonPathArray[vertex] = 1;
                orderArray[++order] = vertex; 
                return true;
            }
            if (graph[prevVertex][vertex] == 0) {
                return false;
            } else {
                if (hamiltonPathArray[vertex] == 1) {
                    // Already considered
                    return false;
                }
            }
            prevVertex = vertex;
            hamiltonPathArray[vertex] = 1;
            orderArray[++order] = vertex; 
            return true;

        }

        bool hamiltonPath(int prev) {

            int prevOrig = prev;
            int v = 0;
            bool isComplete = true;
            for (int i = 0; i < VERTEX_COUNT; ++i) {
                if (hamiltonPathArray[i] == 0) {
                    isComplete = false;
                    v = i ;
                }
            }
            if (isComplete) {
                return true;
            }

            std::cout << " Going to Try vertex: " << v << std::endl;
            std::cout << std::endl;
            for (int i = 0; i < VERTEX_COUNT; ++i) {
                std::cout << hamiltonPathArray[i] << " | ";
            }
            std::cout << std::endl;
            
            if (isSafe(v, prev)) {
                if (hamiltonPath(prev)) {
                    return true;
                }
                prev = prevOrig;
                hamiltonPathArray[v] = 0;
                orderArray[--order] = -1;
            }

            return false;
        }

        void printGraph() {
            std::cout << "---------------------------" << std::endl;
            for (int i = 0; i < VERTEX_COUNT; ++i) {
                std::cout << std::endl;
                std::cout << "   -   -   -   - " << std::endl;
                std::cout << " | ";
                for (int j = 0; j < VERTEX_COUNT; ++j) {
                    std::cout << graph[i][j] << " | ";
                }
            }
            std::cout << std::endl;
            for (int i = 0; i < VERTEX_COUNT; ++i) {
                std::cout << hamiltonPathArray[i] << " | ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
            for (int i = 0; i < VERTEX_COUNT; ++i) {
                std::cout << orderArray[i] << " | ";
            }
            std::cout << std::endl;

        }


    };


}

#endif	/* HAMILTONCYCLE_HPP */

