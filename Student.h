#pragma once
#include "Clock.h"
#include "Calander.h"
#include <string>
#include "Course.h"
#include <list>
#include <iostream>
using namespace std;

class Student
{
protected:
	
	long StudentID;
	Calander DateAdmitted;
	Clock TimeAdmitted;
	string FirstName;
	string LastName;
	list <Course> Courses;
		
public:
	Student(void);
	virtual ~Student(void);

	long   getStudentID() const;
	string getEmailAddress() const;
	void   addCourse(const Course & obj);
	void   viewTranscript();

	friend istream & operator >>(istream & is,Student & obj);
	friend ostream & operator <<(ostream & os, const Student & obj);

	virtual void write (ostream & os) const = 0;
	virtual void read (istream & is) = 0;
	
	virtual string getStatus () const = 0;
	virtual string getStanding() const =0; 
	virtual double getGPA() const=0; 
};











	