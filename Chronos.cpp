#include "Chronos.h"

Chronos:: Chronos (){} 
Chronos:: ~Chronos (){}

//Arithmetic operators: diffrence and increament 
long Chronos:: operator -(const Chronos & obj) const
	{
		return tolong() - obj.tolong();
	}
Chronos & Chronos:: operator += (const int k)
{
for (int i=0; i<k; i++)
	inc ();
return *this;
}

//relational operators 	
bool operator<(const Chronos & a, const Chronos & b)
	{
		return a.tolong() < b.tolong();
	}
bool operator>(const Chronos & a, const Chronos & b)
	{
		return a.tolong() > b.tolong();
	}
bool operator<=(const Chronos & a, const Chronos & b)
	{
		return a.tolong() <= b.tolong();
	}
bool operator>=(const Chronos & a, const Chronos & b)
	{
		return a.tolong() >= b.tolong();
	}
bool operator==(const Chronos & a, const Chronos & b)
	{
		return a.tolong() == b.tolong();
	}
bool operator!=(const Chronos & a, const Chronos & b)
	{
		return a.tolong() != b.tolong();
	}

// Input and Output operators 
istream & operator>>(istream & in, Chronos & obj)
{
obj.read(in);
return in;
}

ostream & operator<<(ostream & out, const Chronos & obj)
{
obj.write(out);
return out;
}	