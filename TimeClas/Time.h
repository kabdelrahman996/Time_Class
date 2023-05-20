#pragma once
class Time
{
private:
	int second;
	int minute;
	int hour;

public:
	Time();
	Time(int, int, int);
	void display();
	void add(Time, Time);
	Time operator ++ ();
	Time operator -- ();
	Time operator ++ (int);
	Time operator -- (int);
	Time operator + (Time) ;
	Time operator - (Time);
};

