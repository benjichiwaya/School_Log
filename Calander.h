#pragma once
#include "chronos.h"
class Calander : public Chronos
{
private:
	int year, month, day;
public:
	Calander(const int y = 0, const int m = 0, const int d = 0);
	virtual ~Calander(void);

	virtual long tolong() const;
	virtual string tostring() const;
	virtual void inc ();
	virtual void read(istream & is);
	virtual void write(ostream & os) const;
	
	int getmonthsize() const;
};