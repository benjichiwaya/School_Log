#pragma once
#include "chronos.h"

class Clock : public Chronos
{
private:
	int hour, minute, second;
public:
	Clock(const int h=0, const int m=0, const int s=0);
	virtual ~Clock(void);
	
	virtual long tolong() const;
	virtual string tostring() const;
	virtual void inc ();
	virtual void read(istream & is);
	virtual void write(ostream & os) const;
};