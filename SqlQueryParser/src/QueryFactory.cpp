#include "QueryFactory.h"
#include "SelectQuery.h"
#include "DeleteQuery.h"
#include "Parse.h"
QueryFactory::QueryFactory()
{
    //ctor
}

QueryFactory::~QueryFactory()
{
}

IQuery* QueryFactory::serialize(string query)
{
    int index = Parse::getIndex(query);
    string clause = Parse::getClause(query);
    cout<<"QueryFactory::serialize clause "<<clause<<endl;
    IQuery* obj = nullptr;
    if(clause == "SELECT")
    {
        obj = new SelectQuery;
        cout<<"QueryFactory::serialize inside  SELECT"<<endl;
    }
    else if(clause == "DELETE")
    {
        obj = new DeleteQuery;
    }
    if(obj != nullptr)
    {
        cout<<"QueryFactory::serialize accessing serialize"<<endl;
        obj->serialize(query.substr(index+1));
    }
    else
    {
        cout<<"QueryFactory::serialize query object not created"<<endl;
    }
    return obj;
}
