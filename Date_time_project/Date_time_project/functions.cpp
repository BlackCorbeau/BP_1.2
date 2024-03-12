#include <iostream>
#include "CDate.h"
#include "class.h"
#include "functions.h"

Status check(CTime& time) //Работает 
{
	Status state = SUCCESS;
	int a = time.get_seconds();
	int b = time.get_minutes();
	int c = time.get_hours();
	if (a >= 60 || a < 0) { state = ERROR; return state; }
	else if (b >= 60 || b < 0) { state = ERROR; return state; }
	else if (c >= 24 || c < 0) { state = ERROR; return state; }
	else { return state; }
}

Status input(CTime& time) { //Работает 
	setlocale(LC_ALL, "ru");
	Status state = SUCCESS;
	char colon;
	int hour;
	int minute;
	int second;
	std::cin >> hour >> colon
		>> minute >> colon
		>> second;
	time.initialize_hours(hour);
	time.initialize_minutes(minute);
	time.initialize_seconds(second);
	state = check(time);
	while (state == ERROR)
	{
		std::cout << "Вы ввели неверные значения введите еще раз\n";
		std::cin >> hour >> colon
			>> minute >> colon
			>> second;
		time.initialize_hours(hour);
		time.initialize_minutes(minute);
		time.initialize_seconds(second);
		state = check(time);
	}
	return state;
}

Status convert(CTime& time, CDate& date) //Работает 
{
	int second = time.get_seconds();
	int minute = time.get_minutes();
	int hour = time.get_hours();
	Status state = SUCCESS;
	while (second >= 60 || minute >= 60 || hour >= 24)
	{
		if (second >= 60)
		{
			second -= 60;
			minute += 1;
		}
		else if (minute >= 60)
		{
			minute -= 60;
			hour += 1;
		}
		else if (hour >= 24)
		{
			int a = date.get_day();
			hour -= 24;
			a += 1;
			date.initialize_day(a);
		}
	}
	time.initialize_seconds(second);
	time.initialize_minutes(minute);
	time.initialize_hours(hour);
	state = check(time);
	return state;
}
// 12:32:78 -> 12:33:18 SUCCESS
// 23:60:78 -> 00:01:18 WARNING
// 78:11:19 -> ERROR

// + sub
Status add_hours(CTime& time, CDate& date, int hours) //Работает 
{
	int hour = time.get_hours();
	Status status = SUCCESS;
	hour += hours;
	time.initialize_hours(hour);
	status = convert(time, date);
	status = check(time);
	return status;
}
Status add_minutes(CTime& time, CDate& date, int minutes) //Работает
{
	int minute = time.get_minutes();
	Status status = SUCCESS;
	minute += minutes;
	time.initialize_minutes(minute);
	status = convert(time, date);
	status = check(time);
	return status;
}
Status add_seconds(CTime& time, CDate& date, int seconds) //Работает
{
	int second = time.get_seconds();
	Status status = SUCCESS;
	second += seconds;
	time.initialize_seconds(second);
	status = convert(time, date);
	status = check(time);
	return status;
}

// 12:33:18 +4 hours -> 16:33:18 SUCCESS
// 20:33:18 +4 hours -> 24:33:18 = 00:33:18 WARNING
// 78:11:19 +4 hours -> ERROR

// 1 - time1 > time2, 0 - time1 == time2, -1 time1 < time2
int compare( CTime& time1, CTime& time2) // Работает
{
	int hour1 = time1.get_hours();
	int hour2 = time2.get_hours();
	int minutes1 = time1.get_minutes();
	int minutes2 = time2.get_minutes();
	int seconds1 = time1.get_seconds();
	int seconds2 = time2.get_seconds();
	if (hour1 == hour2 && minutes1 == minutes2 && seconds1 == seconds2)
	{
		if (minutes1 == minutes2)
		{
			if (seconds1 == seconds2)
			{
				return 0;
			}
			else if (seconds1 > seconds2)
			{
				return 1;
			}
			else if (seconds1 < seconds2)
			{
				return -1;
			}
		}

		else if (minutes1 > minutes2)
		{
			return 1;
		}
		else if (minutes1 < minutes2)
		{
			return -1;
		}
	}
	else if (hour1 > hour2)
	{
		return 1;
	}
	else if (hour1 < hour2)
	{
		return -1;
	}
}

// time1 = time2
Status assign(CTime& time1, CTime time2) { //Работает
	Status state = SUCCESS;
	int hours1 = time1.get_hours();
	int hours2 = time2.get_hours();
	int minutes1 = time1.get_minutes();
	int minutes2 = time2.get_minutes();
	int seconds1 = time1.get_seconds();
	int seconds2 = time2.get_seconds();
	hours1 = hours2;
	minutes1 = minutes2;
	seconds1 = seconds2;
	time1.initialize_hours(hours1);
	time1.initialize_minutes(minutes1);
	time1.initialize_seconds(seconds1);
	return state;
}
