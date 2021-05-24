#ifndef PARSE_H
#define PARSE_H
#include<iostream>
using namespace std;

class Parse
{
    public:
        Parse();
        virtual ~Parse();
/******************************************************
* Note: this method is to get index of first space
* Param: Query string
********************************************************/
        static int getIndex(string query);
/******************************************************
* Note: this method is to get first word
********************************************************/
        static string getClause(string query);
    protected:

    private:
};

#endif // PARSE_H
