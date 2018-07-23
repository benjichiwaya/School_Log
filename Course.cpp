#include "Course.h"

Course::Course(void)
{
	CRN = 0;
	CourseTitle = "";
	CreditHours = 0;
	LetterGrade = 'A';
}


Course::~Course(void)
{
}

long Course::getCRN(void) const
{
	return this->CRN;
}

string	Course::getCourseTitle(void) const
{
	return this->CourseTitle;
}

int		Course::getCreditHours(void) const
{
	return this->CreditHours;
}

char	Course::getLetterGrade(void) const
{
	return this->LetterGrade;
}

void Course::setCRN(const long r) 
{
	CRN = r;
}
void	Course::setCourseTitle(const string & s)
{
	CourseTitle = s;
}

void	Course::setCreditHours(const int i)
{
	CreditHours = i;
}

void	Course::setLetterGrade(const char c)
{
	LetterGrade = c;
}

double Course::getQualityHours(void) const  
{
	double qualityHours = 0.0;

	switch(LetterGrade)
	{
	case 'A': 
	case 'a':	qualityHours = 4 * CreditHours;		break;

	case 'B': 
	case 'b':	qualityHours = 3 * CreditHours;		break;

	case 'C': 
	case 'c':	qualityHours = 2 * CreditHours;		break;

	case 'D': 
	case 'd':	qualityHours = 1 * CreditHours;		break;

	case 'F': 
	case 'f':	qualityHours = 0 * CreditHours;		break;
	}

	return qualityHours;
}

double Course::getQualityHoursGra(void) const
{
	double qualityHours = 0.0;

	switch(LetterGrade)
	{
	case 'A': 
	case 'a':	qualityHours = 4 * CreditHours;		break;

	case 'B': 
	case 'b':	qualityHours = 3 * CreditHours;		break;
	}

	return qualityHours;
}



ostream & operator<<(ostream & os, const Course & obj)
{
	cout<< "CRN:      ";    os <<obj.CRN          <<endl;
	cout << "Title:   "; 	os << obj.CourseTitle << endl;
	cout << "Credits: ";	os << obj.CreditHours << endl;
	cout << "Grade:   ";	os << obj.LetterGrade << endl;

	return os;
}

istream & operator>>(istream & is, Course & obj)
{
	cout << "CRN:      ";    is >>obj.CRN;   is.ignore();
	cout << "Title:   ";	getline(is, obj.CourseTitle);

	if (obj.CourseTitle.length() == 0)
	{
		getline(is, obj.CourseTitle);
	}

	cout << "Credits: ";	is >> obj.CreditHours;	is.ignore();
	cout << "Grade:   ";	is >> obj.LetterGrade;	is.ignore();

	return is;
}






