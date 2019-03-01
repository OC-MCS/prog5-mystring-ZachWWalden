// MyString implementation file
#include "MyString.h"
#include <cstring>
using namespace std;

/*======================================================
	Default constructor - intializes MyString to "Empty String"
======================================================*/
MyString::MyString()
{
	//default string value.
	char a[13] = { "Empty String" };
	//holds length of the default string value
	int len = strlen(a) + 1;
	string = new char[len];
	strcpy_s(string, len, a);
}
/*======================================================
Constructor - takes a const char* copy string literal created by the compiler, and initializes the instantiation to it
		Parameters: const char* copy - commpiler created pointer to a string literal
======================================================*/
MyString::MyString(const char* copy)
{
	string = new char[strlen(copy) + 1];

	strcpy_s(string, sizeof(string), copy);
}
/*======================================================
Copy Constructor - takes a const MyString &copyString object, and 
				   initializes the new instantiation to it.
		Parameters: const MyString & 
======================================================*/
MyString::MyString(const MyString &copyString)
{
	cout << "Copy Constructor called\n\n";
	//holds the size for the new string
	int size = strlen(copyString.string) + 1;
	string = new char[size];
	
	strcpy_s(string, size, copyString.string);
}
/*======================================================
	operator= - takes a const MyString &copyString object, 
				and assigns it to an already instantiated MyString object.
	Parameters: const MyString& assignString - referenceto to the right operand 
	
	reuturn type - MyString - returns a new MyString.
======================================================*/
MyString MyString::operator=(const MyString& assignString)
{
	if (this != &assignString)
	{
		delete[]string;
		//holds the size for the new string
		int length = strlen(assignString.string) + 1;
		string = new char[length];

		strcpy_s(string, length, assignString.string);
	}
	return *this;
}
/*======================================================
    overloaded operator= - takes a const char* string literal, and assigns it to
			an already instantiated MyString object.
	Parameters: const char* copy - pointer to a string literal on the right of the operand

	reuturn type - MyString - returns a MyString.
======================================================*/
MyString MyString::operator=(const char* copy)
{
	delete[] string;
	//holds the size for the new string
	int length = strlen(copy) + 1;
	string = new char[length];

	strcpy_s(string, length, copy);

	return *this;
}
/*======================================================
	operator+ - takes a MyString object on the right ot the + operator, 
				and adds it to MyString object on the left of the + operator
	Parameters: const MyString& addString - MyString on the right of the 
				operator to be added to the MyString on the left of the operator
	return type: MyString - returns the added up MyString
======================================================*/
MyString MyString::operator+(const MyString& addString)
{
	//local object to add parameters into
	MyString returnString;
	delete[] returnString.string;
	//holds the size for the new string
	int len = strlen(string) + strlen(addString.string) + 1;
	returnString.string = new char[len];
	strcpy_s(returnString.string, len, string);
	strcat_s(returnString.string, len, addString.string);

	return returnString;
}
/*======================================================
	overloaded operator+ - takes a const char* to a string literal on the right ot the + operator,
				and adds it to MyString object on the left of the + operator
	Parameters: const char* copy - compiler created pointer a programmer entered string literal.
				operator to be added to the MyString on the left of the operator
	return type: MyString - returns the added up MyString
======================================================*/
MyString MyString::operator+(const char* copy)
{
	MyString returnString;
	delete[] returnString.string;
	//holds the size for the new string
	int len = strlen(string) + strlen(copy) + 1;
	returnString.string = new char[len];
	strcpy_s(returnString.string, len, string);
	strcat_s(returnString.string, len, copy);

	return returnString;
}
/*======================================================
	operator== - checks if the MyStrings on the left and right of the == operator are equivalent.
	Parameters: const MyString& compString - MyString on the right of the operator.
	return type - bool  returns true if the MyStrings are equivalent.
======================================================*/
bool MyString::operator==(const MyString& compString)
{
	//bool for equivalency status.
	bool status = true;
	if (strlen(string) == strlen(compString.string))
	{
		for (int i = 0; i < strlen(string) && status; i++)
		{
			if (string[i] != compString.string[i])
				status = false;
		}
	}
	else
		status = false;

	return status;
}
/*======================================================
	operator<< - outputs a MyString
	Parameters: - ostream &strm - reference to ostream object used to output
				- MyString &outputString - MySttring object to be displayed
	return type: ostream& - returns the passed ostream object.
======================================================*/
ostream &operator<<(ostream &strm, MyString &outputString)
{
	//local pointer.
	const char *ptr = outputString.c_str();

	strm << ptr;

	return strm;
}
/*======================================================
	Destructor - deletes dynamically allocated memory used 
				 to store the string in the MyString object.
======================================================*/
MyString::~MyString()
{
	cout << "Destructor called\n\n";
	delete[] string;
}
/*======================================================
	c_str - getter function that returns the internal string pointer
======================================================*/
const char* MyString::c_str()
{
	return this->string;
}