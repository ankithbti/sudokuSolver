/* 
 * File:   SudokuHttpHandler.hpp
 * Author: ankithbti
 *
 * Created on 14 June, 2015, 7:56 PM
 */

#ifndef SUDOKUHTTPHANDLER_HPP
#define	SUDOKUHTTPHANDLER_HPP

#include <HttpReqHandlerInterface.hpp>
#include "Board.hpp"

namespace sudukoSolver {

    class SudokuHttpHandler : public httpServer::HttpReqHandlerInterface {
    private:
        const Board& _board;
    public:

        explicit SudokuHttpHandler(const std::string& docRoot, const Board& b) : httpServer::HttpReqHandlerInterface(docRoot), _board(b) {

        }

        virtual void handleGetRequest(httpServer::HttpRequest::ConstSmartPtr req, httpServer::HttpReply::SmartPtr rep);
        virtual void handlePostRequest(httpServer::HttpRequest::ConstSmartPtr req, httpServer::HttpReply::SmartPtr rep);
        virtual void handlePutRequest(httpServer::HttpRequest::ConstSmartPtr req, httpServer::HttpReply::SmartPtr rep);
        virtual void handleDeleteRequest(httpServer::HttpRequest::ConstSmartPtr req, httpServer::HttpReply::SmartPtr rep);

    };
}


#endif	/* SUDOKUHTTPHANDLER_HPP */

