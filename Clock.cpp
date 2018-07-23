#include "Clock.h"

Clock::Clock(const int h, const int m, const int s)
{
	hour = h % 24;
	minute = m % 60;
	second = s % 60;
}
Clock::~Clock(void)
{
}

long Clock::tolong() const
{
	return (second + minute *60 +hour*3600);
}

string Clock::tostring() const
{
ostringstream sout;
write (sout);
return sout.str();
}

void Clock ::inc()
{
	if(++second==60)
	{
		second =0;
		
		if (++minute ==60)
		{
		minute=0;
		if (++hour==24)
		{
			hour=0;
		}
		
		}
	}
}

void Clock :: read (istream & is) 
{
	is >> hour;
	is.ignore();
	is >> minute;
	is.ignore();
	is >> second;
	is.ignore();
	
	hour=hour % 24;
	minute=minute % 60;
	second=second % 60;
}

void Clock :: write (ostream & os) const
{
os << ((hour<10)? " " :"") << hour;
os <<":";
os << ((minute<10)? "0" :"")<< minute;
os <<":";
os << ((second<10)? "0" :"") << second; 
}