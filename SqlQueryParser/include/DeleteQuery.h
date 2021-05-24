#ifndef DELETEQUERY_H
#define DELETEQUERY_H
#include "IQuery.h"

class DeleteQuery : public IQuery
{
    public:
        DeleteQuery();
        virtual ~DeleteQuery();
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
        bool fromClause;
};

#endif // DELETEQUERY_H
