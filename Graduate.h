#pragma once
#include "student.h"
class Graduate :public Student
{
	private:
	string GRE;
public:
	Graduate(void);
	virtual ~Graduate(void);

	string getGRE (void) const;
	void setGRE(const string &);


	virtual void write (ostream & os) const;
	virtual void read (istream & is);
	
	virtual string getStatus () const;
	virtual string getStanding() const; 
	virtual double getGPA() const; 

};

