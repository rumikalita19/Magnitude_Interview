#include <iostream>
#include <cstring>

using namespace std;


/*

class A
{
public:
    void printA()
    {
        cout << endl << "Printing A";
    }

    void printX()
    {
        cout << endl << "Printing X" << x;
    }

private:
    int x;
};


class B
{
public:
    void printB()
    {
        cout << endl << "Printing B";
    }

    virtual void printY()
    {
        cout << endl << "Printing Y" << y;
    }

private:
    int y;
};


int main (void)
{
	A* aObj = NULL;
    B* bObj = NULL;
    
    aObj->printA();
    aObj->printX();

    bObj->printB();
    bObj->printY();

    return 0;
}

//////////////////////////////////////////////////
//Segmentation Fault:
//1.Segmentation fault as trying to access a memory 
//which is not instantiated line number 51 
//2.Segmentation fault as trying to access a memory 
//which is not instantiated line number 54
//One observation:
// 1. Syntex is okay 
//    but cout << endl << "Printing A"; 
//    could be cout << "Printing A"<< endl;
////////////////////////////////////////////////

*/
class A
{
public:
	A(int input):x(input)
	{
	}
	A()
	{
	}
	virtual ~B()
	{
	}
    void printA()
    {
        cout << endl << "Printing A";
    }

    void printX()
    {
        cout << endl << "Printing X" << x;
    }

private:
    int x;
};
class B
{
public:
	B(int input):y(input)
	{
	}
	B()
	{
	}
	virtual ~B()
	{
	}
    void printB()
    {
        cout << endl << "Printing B";
    }

    virtual void printY()
    {
        cout << endl << "Printing Y" << y;
    }

private:
    int y;
};

int main (void)
{
	A* aObj = new A;
    B* bObj = new B;
	
    
    aObj->printA();
    aObj->printX(); 

    bObj->printB();
    bObj->printY(); 
	
	delete bObj;
	delete aObj;
    return 0;
}

