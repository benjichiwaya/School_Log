#include"Department.h"
void main ()
{
Department myDepartment;
do
{
system("cls");
cout<<  "*********************" <<endl;
cout<<  "*Main menu...........*" <<endl;
cout<<  "*....................*" <<endl;
cout<<  "*1.Undergraduate.....*" <<endl;
cout<<  "*2.Graduadte.........*" <<endl;
cout<<  "*3.Course............*" <<endl;
cout<<  "*4.ShowRoster........*" <<endl;
cout<<  "*0.Exit..............*" <<endl;
cout<<  "*********************" <<endl;

int choice;
cout<<"Enter choice   ";
cin>>choice;
//cin.ignore();

switch(choice)
{
case 0: return;
case 1: myDepartment.addUndergraduate();break;
case 2: myDepartment.addGraduate();break;
case 3: myDepartment.addCourse();break;
case 4: myDepartment.showRoster(); break;
default:cerr<<"invalid choice"<<endl;
}
system("pause");
}

while(true);
}



