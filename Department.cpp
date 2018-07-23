#include "Department.h"
#include "Course.h"

Department::Department()
{
	try
	{
		//retrive Student from textfile
	
	ifstream Uin ("Undergraduate.data");
	for (Undergraduate obj; Uin >> obj; Students.push_back(new Undergraduate (obj)));
	Uin.close();
	
	ifstream Gin ("Graduate.data");
	for (Graduate obj; Gin >> obj; Students.push_back(new Graduate(obj)));
	Gin.close();
	}
	catch (...)
	{
	cerr<<"//error in Department::restore()"<<endl;
	}
}


Department::~Department()
{
	try
	{
		// store student into textfile
		ofstream Uout ("Undergraduate.data");
		ofstream Gout ("Graduate.data");
		for (List::iterator ptr=Students.begin(); ptr != Students.end(); ptr++)
		{
		if(typeid(*(ptr)) ==typeid(Undergraduate))
				Uout<<*(*ptr)<<endl;
		if(typeid(*(ptr)) ==typeid(Graduate))
				Gout<<*(*ptr)<<endl;
		delete (*ptr);
		}
		Uout.close();
		Gout.close();
	}
	catch (...)
	{
		cerr<<"// error in Department::backup()"<<endl; 
	}
}

void Department:: addUndergraduate ()
	{
	try
	{
	Undergraduate * obj = new Undergraduate;
	cout << "Enter Undergraduate info..."<<endl;
	cin>>(*obj);
	Students.push_front(obj);
	}
	catch (...)
	{
		cerr<<"//error in Department ::addUndergraduate()"<<endl;
	}
}

void Department:: addGraduate()
{
	try
	{
	Graduate * obj = new Graduate;
	cout << "Enter Graduate info..."<<endl;
	cin>>(*obj);
	Students.push_back(obj);
	}
	catch (...)
	{
		cerr<<"//error in Department ::addGraduate()"<<endl;
	}

}

void Department:: addCourse()
{

	int id;
	cout << "Enter Student ID: ";
	cin >> id;
	cin.ignore();

	for (List:: iterator ptr = Students.begin();
		 ptr !=Students.end(); ptr++)
	{
	if ((*ptr)->getStudentID() == id)
	{
	try
	{
	Course * obj = new Course;
	cout << "Enter Course info..."<<endl;
	cin>> (*obj);
	(*ptr)->addCourse(*obj);
	}
	catch (...)
	{
	cerr<<"//error in Department ::addCourse()"<<endl; 
	}
	}
	}

}
void Department:: showRoster()
{

	long StudentID=0;
	long CourseNumber=0;
	double GPA = 0.0;
	string Standing;
	string Status;
	string email;

	//cout<< "......................................"<<endl;
	cout<< "Detail report ...."<<endl;
	//cout<<"......................................."<<endl;

	// for ( int i=0, i< 10; i++)
	for (List::iterator ptr = Students.begin();
		ptr != Students.end(); ptr++)
	{
		//increment student ID
		cout << "#" << StudentID++ << endl;
		//prints student info
		cout << *(*ptr) << endl;
		GPA += (*ptr)->getGPA();
		Standing = (*ptr)->getStanding();
		Status = (*ptr)->getStatus();
		email = (*ptr)->getEmailAddress();
		cout << "Your School Email Addres**********=" << email << endl;
		cout << "STUDENT GRADE POINT AVERG/GPA*****=" << GPA << endl;
		cout << "STUDENT STANDING******************=" << Standing << endl;
		cout << "CURRENT STUDENT STATUS************=" << Status << endl;

	}
	cout<< "Course Number is:    "<<CourseNumber<<endl;
}
