#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;

Time::Time() : second(0), minute(0), hour(0){}

Time::Time(int h, int m, int s)
{
	second = s;
	minute = m;
	hour = h;
}

void Time::display()
{
	cout << setfill('0') << setw(2) << hour << " : " << setfill('0') << setw(2) << minute << " : " << setfill('0') << setw(2) << second << endl;
}

void Time::add(Time t1, Time t2)
{
	second = t1.second + t2.second;
	if (second >= 60)
	{
		minute++;
		second -= 60;
	}
	minute += t1.minute + t2.minute;
	if (minute >= 60)
	{
		hour++;
		minute -= 60;
	}
	hour += t1.hour + t2.hour;
}

Time Time::operator++()
{
	++hour;
	++minute;
	++second;
	
	return *this;
}

Time Time::operator--()
{
	--hour;
	--minute;
	--second;

	return *this;
}

Time Time::operator++(int)
{
	Time old_value = *this;

	++hour;
	++minute;
	++second;

	return old_value;
}

Time Time::operator--(int)
{
	Time old_value = *this;

	--hour;
	--minute;
	--second;

	return old_value;
}

Time Time::operator+ (Time t) 
{
	int h = hour + t.hour;
	int m = minute + t.minute;
	int s = second + t.second;

	if (s >= 60) {
		m += s / 60;
		s %= 60;
	}
	if (m >= 60) {
		h += m / 60;
		m %= 60;
	}
	if (h >= 24) {
		h %= 24;
	}

	return Time(h, m, s);
}

Time Time::operator- (Time t) 
{
	int h = hour - t.hour;
	int m = minute - t.minute;
	int s = second - t.second;
	if (s >= 60)
	{
		m += s / 60;
		s %= 60;
	}
	if (m >= 60)
	{
		h += m / 60;
		m %= 60;
	}
	if (h >= 24)
		h %= 24;

	return Time(h, m, s);
}