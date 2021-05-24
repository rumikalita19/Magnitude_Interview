#ifndef IQUERY_H
#define IQUERY_H
#include<iostream>
using namespace std;
class IQuery
{
    public:
        IQuery();
        IQuery(string);
        virtual ~IQuery();
/**************************************************
* Note: This method is to get string form of query structure
* Param: Query string
****************************************************/
        void toString();
/**************************************************
* Note: This method is to set select query clauses
        into the object
* Param: Query string
****************************************************/
        virtual void serialize(string query) = 0;
/**************************************************
* Note: This method is to retrieve query string from
*       the query structure
* return: Query string
****************************************************/
        virtual string deSerialize() = 0;
    protected:
        string tableName;
        string queryClause;

};

#endif // IQUERY_H
