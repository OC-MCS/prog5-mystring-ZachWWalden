// test driver code goes here
#include "MyString.h"
using namespace std;

int main()
{
	//test default constructo
	MyString constructor;
	//test string literal constructor
	MyString defCons("defcons");
	//test copy constructor
	MyString copCons(constructor);

	cout << "output test ";
	cout << "'constructor'  = " << constructor << " 'def cons' = " << defCons << " 'cop cons' = " << copCons << endl;

	cout << "equivalency test \n";
	if (constructor == copCons)
		cout << constructor << " == " << copCons << endl;

	//test overloaded overloaded assignment operaotr
	copCons = constructor = "Hi";

	cout << constructor << endl;
	cout << copCons << endl;
	//test overloaded assignment operator
	constructor = defCons;

	cout << "'constructor' " << constructor << " 'def cons' " << defCons << " 'cop cons' " << copCons << endl;
	
	//test second overloaded + operator, Only Works if the literal is on the right side of the operator
	MyString charOp = "Hi Andy";
	cout << charOp << endl;
	charOp = charOp + ", Bye Andy" + " hehe tehehe";
	cout << charOp << endl;

	//test + operator
	cout << "testing + operator ";
	copCons = defCons + defCons;
	
	cout << "'copCons'" << copCons << " = 'def cons' " << defCons << " + 'def cons' " << defCons << endl;
	return 0;
}