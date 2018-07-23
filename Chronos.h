#pragma once
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

class Chronos
{
public:

	Chronos(void);
	virtual ~Chronos(void);

	// Arithmetic operators 
	long operator - (const Chronos & obj) const;
	Chronos & operator +=(const int k); 

	// Relational operator 
	friend bool operator<(const Chronos & a, const Chronos & b);
	friend bool operator>(const Chronos & a, const Chronos & b);
	friend bool operator<=(const Chronos & a, const Chronos & b);
	friend bool operator>=(const Chronos & a, const Chronos & b);
	friend bool operator==(const Chronos & a, const Chronos & b);
	friend bool operator!=(const Chronos & a, const Chronos & b);
	
	// Input and Output operators 
	friend istream & operator>>(istream & in, Chronos & obj);
	friend ostream & operator<<(ostream & out, const Chronos & obj);

	// Pure virtual methods 
	virtual long tolong () const = 0;	
	virtual string tostring () const = 0;
	virtual void inc () = 0;

	virtual void read (istream & is) = 0;
	virtual void write (ostream & os) const =0;

};




	
							  