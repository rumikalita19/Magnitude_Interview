#ifndef QUERYFACTORY_H
#define QUERYFACTORY_H
#include "IQuery.h"

class QueryFactory
{
    public:
        QueryFactory();
        virtual ~QueryFactory();
/**************************************************
* Note: This method is to get specific query structure
        object
* Param: Query string
****************************************************/
        IQuery* serialize(string query);

    protected:

    private:
};

#endif // QUERYFACTORY_H
