#include <iostream>
#include <cstring>

using namespace std;

/*class A
{
public:
    virtual void printA()
    {
        cout << endl << "Printing A";
    }
};

class B
{
public:
    virtual void printB()
    {
        cout << endl << "Printing B";
    }
};


class C : public A, public B
{
public:
    virtual void printC()
    {
        cout << endl << "Printing C";
    }
};

class D : public B, public A
{
public:
    virtual void printD()
    {
        cout << endl << "Printing D";
    }
};

void callPrints1(A* obj)
{
    obj->printA();
    B* bobj = (B*)(obj);
    bobj->printB();
}

void callPrints2(B* obj)
{
    obj->printB();
    A* bobj = (A*)(obj);
    bobj->printA();
}

int main (void)
{
	A* cObj = new C();
    A* dObj = new D();
    B* eObj = new C();
    B* fObj = new D();

    callPrints1(cObj);
    callPrints1(dObj);

    callPrints2(eObj);
    callPrints2(fObj);

    //delete cObj;
    //delete dObj;

    return 0;
}

//////////////////////////////////////////////////
//Memory leak:
//1. Memory is not released for all the object created
//cObj, dObj, eObj, fObj
//Logical error:
//1. Creating object with base class pointer in 
//case of multiple inheritence line number 59 to 62
//Observation:
//1. we can use casting in place of type conversion.(Better approach)
//   here, we can use dynamic_cast use it has dynamic polymorphism
////////////////////////////////////////////////
*/

class A
{
public:
    virtual void printA()
    {
        cout << endl << "Printing A";
    }
};

class B
{
public:
    virtual void printB()
    {
        cout << endl << "Printing B";
    }
};


class C : public A, public B
{
public:
    virtual void printC()
    {
        cout << endl << "Printing C";
    }
};

class D : public B, public A
{
public:
    virtual void printD()
    {
        cout << endl << "Printing D";
    }
};

void callPrints1(A* obj)
{
    obj->printA();
    B* bobj = dynamic_cast<B*>(obj); 
    bobj->printB();
}

void callPrints2(B* obj)
{
    obj->printB();
    A* bobj = dynamic_cast<A*>(obj);
    bobj->printA();
}

int main (void)
{
	C* cObj = new C();
    D* dObj = new D();
    C* eObj = new C();
    D* fObj = new D();

    callPrints1(cObj);
    callPrints1(dObj);

    callPrints2(eObj);
    callPrints2(fObj);

    delete dObj;
    delete cObj;
    delete eObj;
    delete fObj;

    return 0;
}