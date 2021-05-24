#include <iostream>
#include <cstring>

using namespace std;




/*class A
{
public:
    

private:
    int x;
    int* ptr;
    int& ref;
};
int main (void)
{
	A aObj; 

    return 0;
}

//////////////////////////////////////////////////
//Compilation error:
//1. A must have constructor with initilizer list 
//it has a reference member variable so it will be compilation
//use of deleted function ‘A::A()’ in line number 21
//2. uninitialized reference member in ‘class A’ in line number 17
////////////////////////////////////////////////

*/



//first approach
class A
{
public:
    A(int value = 0):x(value),ptr(&x),ref(x)
	{
	}
private:
    int x;
    int* ptr;
    int& ref;
};
//second approach but ref may have garbage value
/*
class A
{
public:
    A():ptr(nullptr),ref(x)
	{
	}
private:
    int x;
    int* ptr;
    int& ref;
};
*/
int main (void)
{
	A aObj; 

    return 0;
}
