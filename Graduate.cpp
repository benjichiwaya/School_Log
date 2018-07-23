#include "Graduate.h"


Graduate::Graduate(void)
{
GRE = "Yes";
}

Graduate::~Graduate(void)
{
}

string Graduate:: getGRE (void) const
{
return this-> GRE;
}

void Graduate:: setGRE (const string & gre)
{
this->GRE = gre;
}

void Graduate:: write (ostream & os) const 
	{
		
	cout<<"StudentID:           ";os<< StudentID<<endl;
	cout<<"DateAdmitted:         ";os<< DateAdmitted<<endl;
	cout<<"TimeAdmitted:         ";os<< TimeAdmitted<<endl;
	cout<<"FirstName             ";os<< FirstName<<endl;
	cout<<"LastName              ";os<< LastName<<endl;
	cout<<"GRE:                  ";os<< GRE<<endl;
	}


void Graduate:: read (istream & is) 
	{

         cout<<"\n\t...Type of Undergraduate Information...\t\n";
     for(StudentID=0;StudentID<20; StudentID++)
		 cout<<"\t"<<StudentID<<" "<<getGPA()<<"\n";
	     cout<<"\t"<<StudentID<<" "<<getStanding()<<"\n";
	     cout<<"\t"<<StudentID<<" "<<getStatus()<<"\n";
	     cout<<"DateAdmitted:      "; is>>DateAdmitted;
		 cout<<"TimeAdmitted:      "; is>>TimeAdmitted;
		 cout<<"FirstName:         ";is>> FirstName;
		 cout<<"LastName:          ";is>> LastName;
		 cout<<"GRE:               ";getline (is, GRE);
	}

double Graduate:: getGPA()const
{
		double TotalQualityHours= 0.0;
		double TotalCreditHours=0.0;
		double GPA;		 
	
for (list< Course> :: const_iterator i= Courses.begin(); i!= Courses.end(); i++)
{
TotalQualityHours += i-> getQualityHours();
TotalCreditHours += i-> getCreditHours();
}
		if(TotalCreditHours !=0.0)
		
		{
		GPA = (TotalQualityHours/TotalCreditHours);
        }
		return GPA;
}

string Graduate::getStanding() const
{	  
	string Standing= "Probation";
	if (getGPA() >3.0)
		  Standing="Good Standing";
	 
	return Standing;
}
string Graduate::getStatus() const
 {
	string Status = "Graduate";
	double TotalCreditHours=0.0;

	for (list< Course> :: const_iterator i= Courses.begin(); i!= Courses.end(); i++)
	{
	if (i->getCourseTitle() =="Thesis" || i-> getCourseTitle()=="Dissertation")
	{
	Status ="Candidate";
	}
	}
	return Status;
}