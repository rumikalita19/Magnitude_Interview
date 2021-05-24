#include "DeleteQuery.h"
#include "Parse.h"
DeleteQuery::DeleteQuery()
:IQuery("DELETE"),
fromClause(false)
{
    cout<<"DeleteQuery constructor"<<endl;
}

DeleteQuery::~DeleteQuery()
{
    //dtor
}

void DeleteQuery::serialize(string query)
{
    int index = Parse::getIndex(query);
    string clause = Parse::getClause(query);
    while(index != -1)
    {
        if(clause == "FROM")
        {
           fromClause = true;
        }
        if(fromClause)
        {
            tableName = clause;
        }
        query = query.substr(index+1);
        index = Parse::getIndex(query);
        clause = Parse::getClause(query);
    }
    if(index ==-1 && clause.size() > 0)
    {
        if(fromClause)
        {
            tableName = clause;
        }
    }
}

string DeleteQuery::deSerialize()
{
   string query = queryClause + " ";
   if(fromClause)
   {
       query += "FROM ";
   }
   return  query + tableName + ";";
}
