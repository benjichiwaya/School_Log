#include "Undergraduate.h"
#include <iostream>

Undergraduate::Undergraduate(void)
{
	SAT = "Yes";
}


Undergraduate::~Undergraduate(void)
{
}

string Undergraduate:: getSAT (void) const
{
return this-> SAT;
}
void Undergraduate:: setSAT (const string & sat)
{
this->SAT = sat;
}

void Undergraduate:: write (ostream & os) const 
	{
		
	cout<<"StudentID:           ";os<< StudentID<<endl;
	cout<<"DateAdmitted:         ";os<< DateAdmitted<<endl;
	cout<<"TimeAdmitted:         ";os<< TimeAdmitted<<endl;
	cout<<"FirstName             ";os<< FirstName<<endl;
	cout<<"LastName              ";os<< LastName<<endl;
	cout<<"SAT:                  ";os<< SAT<<endl;
	}


void Undergraduate:: read (istream & is) 
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
		 cout<<"SAT:               ";getline (is, SAT);
	}

double Undergraduate:: getGPA()const
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
string Undergraduate::getStanding() const
{	  
	string Standing;
	
	if (getGPA() >3.3)
		 
		Standing="Dean list";
     
	else if  (getGPA() >=2.0)
		Standing= "Good Standing";
		  
	else 
		Standing= "Probation";
	
	return Standing;
}
string Undergraduate::getStatus() const
 {
	string Status;
	double TotalCreditHours=0.0;
	for (list< Course> :: const_iterator i= Courses.begin(); i!= Courses.end(); i++)
	{
	TotalCreditHours += i-> getCreditHours();
	}
	if (TotalCreditHours < 30)
			Status="freshman";
	 
   else   if (TotalCreditHours < 60)
			Status="Sophomer";
   else   if (TotalCreditHours <90)
            Status="Junior";
	else
			   Status="senior";
	return Status;
}