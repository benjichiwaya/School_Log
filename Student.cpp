#include "Student.h"

Student::Student(void)
{
	StudentID = 0002657;
	DateAdmitted;
	TimeAdmitted;
	FirstName = "Mesi";
	LastName= "Meressa";
	Courses;
}

Student::~Student(void)
{
}

long   Student :: getStudentID() const 
{ 
	return StudentID;
}
string Student:: getEmailAddress() const
{
return (FirstName + "." + LastName + "@udc.edu");
}

void Student :: addCourse(const Course & obj)
{
	Courses.push_back(obj);
}

void Student:: viewTranscript()
{
cout << "Full name:   " <<LastName<< ", "<< FirstName <<endl;
cout<< "Admitted on:  " << DateAdmitted<< "  "<< TimeAdmitted << endl;

for (list< Course> :: iterator i=Courses .begin(); i!= Courses.end(); i++)

{
	cout << (*i) << endl;
}
cout << "GPA:          "<< this-> getGPA()<<endl;
cout << "Status:       "<< this-> getStatus()<<endl;	
cout << "Standing:     "<< this-> getStanding()<<endl;

}

istream & operator >>(istream & is,Student & obj)
{
	cout << " STUD ID:      ";	is >> obj.StudentID;is.ignore();
	cout << "FIRST NAME:   ";          getline (is, obj.FirstName);
	cout << "LAST NAME:    ";          getline (is, obj.LastName);
	cout << "DATE (y/m/d):    ";	      is >> obj.DateAdmitted;	
	cout << "TIME (h/m/s)   ";	      is >> obj.TimeAdmitted;
	int n;
	cout << "Enter # of Courses: ";
	is >> n;
	is.ignore();
	Course c;
	for (int i = 0; i< n; i++)
	{
		is>> c; obj.addCourse (c);
	}
	return is;
}

ostream & operator <<(ostream & os, const Student & obj)
{
	cout << "ID:      ";	      os <<obj.StudentID<< endl;	
	cout << "First:   ";          os<<obj.FirstName<<endl;
	cout << "Last:    ";          os<<obj.LastName<<endl;
	cout << "Date:    ";	      os << obj.DateAdmitted<<endl;	
	cout << "Time:    ";	      os << obj.TimeAdmitted<<endl;	
	
	int n = obj.Courses.size();
	cout << "Number of Courses: ";
	os << n<<endl;
	
	for (list< Course> :: const_iterator i= obj.Courses.begin(); i!= obj.Courses.end(); i++)

	{
		os << (*i) <<endl;
	}
	return os;
}