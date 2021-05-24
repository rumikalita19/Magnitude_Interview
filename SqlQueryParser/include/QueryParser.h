#ifndef QUERYPARSER_H
#define QUERYPARSER_H
/****************************
* File name: QueryParser.h
* Purpose : This file is used
* to perse any sql query to a
* suitable data structure.
*****************************/
#include "IQuery.h"
#include "QueryFactory.h"
using namespace std;
class QueryParser
{
    public:
        QueryParser();
        virtual ~QueryParser();
/****************************
* Method: Parse
* Todo
*****************************/
        void Parse()
        {
            // parsedQuery is filled here
            // this is for illustration, no code required from you
        }
/****************************
* Note: this method is to send the query structure
        here we are storing to queryObj
* Param: Instance of query structure
*****************************/
        void sendBufferOverNetwork(IQuery* q)
        {
            q->toString();
            //Not implemented as not required as per requirement
            delete queryObj;
            if(q != nullptr)
            {
                queryObj = q;
            }
        }
/********************************************************
* Note: this method is to set the query string
*************************************************************/

        void setQuery(string str)
        {
            if(str.size() > 0)
            {
                if(str[str.size()-1] == ';')
                {
                    str[str.size()-1] = '\0';
                }
                query = str;
            }

        }
/********************************************************
* Note: this method is to serialize the query string to
        query structure.
*************************************************************/
        void sendOverNetwork()
        {
            cout<<"QueryParser::SendOverNetwork accessing serialize"<<endl;
            IQuery* queryStruc;
            queryStruc = queryFactory->serialize(query);
            if(queryStruc != nullptr)
            {
                sendBufferOverNetwork(queryStruc);
            }
            else
            {
                cout<<"QueryParser::SendOverNetwork queryStruc is null"<<endl;
            }
        }

/********************************************************
* Note: this method is to de-serialize the query structure to
        query string.
*************************************************************/
        string recieveFromNetwork()
        {
            if(queryObj != nullptr)
            {
                resp = queryObj->deSerialize();
            }
            else
            {
                cout<<"QueryParser::recieveFromNetwork queryStruc is null"<<endl;
            }
            return resp;
        }

    protected:

    private:
        string query;
        string resp;
        QueryFactory *queryFactory;
        IQuery* queryObj;
};

#endif // QUERYPARSER_H
