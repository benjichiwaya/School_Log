#pragma once
#include "student.h"
class Undergraduate :public Student
{
private:
	string SAT;
public:
	Undergraduate(void);
	virtual ~Undergraduate(void);

	string getSAT (void) const;
	void setSAT(const string &);


	virtual void write (ostream & os) const;
	virtual void read (istream & is);
	
	virtual string getStatus () const;
	virtual string getStanding() const; 
	virtual double getGPA() const; 

};

