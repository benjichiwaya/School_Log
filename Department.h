#pragma once
#include <list>
#include <typeinfo>
#include "Undergraduate.h"
#include "Graduate.h"

typedef list<Student *> List;

class Department
{
private: 
	List Students;
public:
	Department(void);
	~Department(void);
	
	void addUndergraduate();
	void addGraduate();
	void addCourse();
	void showRoster();
};
