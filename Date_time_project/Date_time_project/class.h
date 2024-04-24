#pragma once

class CTime
{
private:
	int second;
	int minute;
	int hour;
public:
	CTime();
	CTime(int _second, int _minute, int _hour);
	~CTime();
	void initialize_seconds(int _second);
	void initialize_minutes(int _minutes);
	void initialize_hours(int _hours);
	int get_seconds() const;
	int get_minutes() const;
	int get_hours() const;
	void print_parametrs();
};

