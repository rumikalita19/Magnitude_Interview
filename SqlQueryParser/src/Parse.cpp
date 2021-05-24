#include "Parse.h"
#include <cctype>
#include <algorithm>
Parse::Parse()
{
    //ctor
}

Parse::~Parse()
{
    //dtor
}

int Parse::getIndex(string query)
{
    return query.find(" ");
}

string Parse::getClause(string query)
{
    int index = getIndex(query);
    string str = "";
    if(index != -1)
    {
        str = query.substr(0,index);
    }
    else
    {
        str = query;
    }
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
