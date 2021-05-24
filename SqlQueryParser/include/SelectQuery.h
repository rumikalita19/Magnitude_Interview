#ifndef SELECTQUERY_H
#define SELECTQUERY_H
#include "IQuery.h"
#include<vector>

class SelectQuery : public IQuery
{
    public:
        SelectQuery();
        virtual ~SelectQuery();
/**************************************************
* Note: This method is to set select query clauses
        into the object
* Param: Query string
****************************************************/
        void serialize(string query) override;
/**************************************************
* Note: This method is to retrieve query string from the structure
* return: Query string
****************************************************/
        string deSerialize() override;
    protected:

    private:
        bool isAll;
        bool fromClause;
        vector<string> columns;
};

#endif // SELECTQUERY_H
