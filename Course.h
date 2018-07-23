#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Course
{
private:
	long    CRN;
	string	CourseTitle;
	int		CreditHours;
	char	LetterGrade;

public:
	Course(void);
	virtual ~Course(void);
	
	long    getCRN() const;
	string	getCourseTitle(void) const;
	int		getCreditHours(void) const;
	char	getLetterGrade(void) const;
	
	void    setCRN(const long r);
	void	setCourseTitle(const string & s);
	void	setCreditHours(const int i);
	void	setLetterGrade(const char c);

	friend ostream & operator<<(ostream & os, const Course & obj);
	friend istream & operator>>(istream & is, Course & obj);

	double getQualityHours(void) const;
	double getQualityHoursGra(void) const;
};




