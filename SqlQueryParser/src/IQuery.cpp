#include "IQuery.h"

IQuery::IQuery(string str)
{
    queryClause = str;
    tableName = "";
    cout<<"IQuery constructor"<<endl;
}

IQuery::~IQuery()
{
    //dtor
}

void IQuery::toString()
{
    cout<<"The query is "<<queryClause<<endl;
}
