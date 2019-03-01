#pragma once
#include <iostream>
using namespace std;
// MyString class declaration goes here

class MyString
{
public:
	MyString();
	MyString(const char *);
	MyString(const MyString &);
	~MyString();

	const char* c_str();
	
	MyString operator=(const MyString&);
	MyString operator=(const char*);

	MyString operator+(const MyString&);
	MyString operator+(const char*);

	bool operator==(const MyString&);

private:
	//internal string pointer
	char* string;
};
ostream &operator<<(ostream &, MyString &);