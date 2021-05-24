#include "SelectQuery.h"
#include "Parse.h"
SelectQuery::SelectQuery()
:IQuery("SELECT"),
isAll(false),
fromClause(false)
{
    cout<<"SelectQuery constructor"<<endl;
}

SelectQuery::~SelectQuery()
{
    //dtor
}

void SelectQuery::serialize(string query)
{
    cout<<"SelectQuery::serialize "<<endl;
    int index = Parse::getIndex(query);
    string clause = Parse::getClause(query);
    while(index != -1)
    {
        if(clause == "*")
        {
           isAll = true;
        }
        else if(clause == "FROM")
        {
           fromClause = true;
        }
        else
        {
            if(fromClause)
            {
                tableName = clause;
            }
            else
            {
                columns.push_back(clause);
            }
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

string SelectQuery::deSerialize()
{
   string query = queryClause + " ";
   if(isAll)
   {
       query += "* ";
   }
   else
   {
       for(auto it: columns)
       {
           query += it + " ";
       }
   }
   if(fromClause)
   {
       query += "FROM ";
   }
   return  query + tableName + ";";
}
