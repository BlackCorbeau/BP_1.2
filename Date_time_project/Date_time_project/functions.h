#pragma once

enum Status { SUCCESS, ERROR, WARNING };

Status check(CTime& time);
Status input(CTime& time);
Status convert(CTime& time, CDate& date);
Status add_hours(CTime& time, CDate& date, int hours);
Status add_minutes(CTime& time, CDate& date, int minutes);
Status add_seconds(CTime& time, CDate& date, int seconds);
int compare(CTime& time1, CTime& time2);
Status assign(CTime& time1, CTime time2);