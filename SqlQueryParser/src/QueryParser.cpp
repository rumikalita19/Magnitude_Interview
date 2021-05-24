#include "QueryParser.h"

QueryParser::QueryParser()
:query(""),
resp(""),
queryFactory(new QueryFactory),
queryObj(nullptr)

{

    cout<<"QueryParser constructor called"<<endl;
}

QueryParser::~QueryParser()
{
    delete queryFactory;
    cout<<"QueryParser destructor called"<<endl;
}

int main()
{
    QueryParser parser;
    string query = "Select * from Table;";
    parser.setQuery(query);
    parser.sendOverNetwork();
    cout<<"After de-serialization "<<parser.recieveFromNetwork()<<endl;

    cout<<"************************************************************"<<endl;
    query = "Select col1, col2, col3 from Table;";
    parser.setQuery(query);
    parser.sendOverNetwork();
    cout<<"After de-serialization "<<parser.recieveFromNetwork()<<endl;

    cout<<"************************************************************"<<endl;
    query = "Delete from table;";
    parser.setQuery(query);
    parser.sendOverNetwork();
    cout<<"After de-serialization "<<parser.recieveFromNetwork()<<endl;
    return 0;
}
