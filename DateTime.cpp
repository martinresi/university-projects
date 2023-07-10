#include "DateTime.h"
#include <string>
#include <chrono>

using std::chrono::system_clock;
using UDateTime::DateTime;
using namespace std;

struct UDateTime::DateTime
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

string PadWithLeadingZero(int timeUnit);
string Format12Hour(int hour);
string GetAmPm(int hour);

string UDateTime::ToFormat(const DateTime* dateTime, DateTimeFormat format)
{
    string dateTimeFormatted;

    switch (format)
    {
    case YYYYMMDD_HHmmss:
        dateTimeFormatted = to_string(dateTime->year) + "-"
            + PadWithLeadingZero(dateTime->month) + "-"
            + PadWithLeadingZero(dateTime->day) + " "
            + PadWithLeadingZero(dateTime->hour) + ":"
            + PadWithLeadingZero(dateTime->minute) + ":"
            + PadWithLeadingZero(dateTime->second);
        break;

	case YYYYMMDD_hhmmss:
        dateTimeFormatted = to_string(dateTime->year) + "-"
            + PadWithLeadingZero(dateTime->month) + "-"
            + PadWithLeadingZero(dateTime->day) + " "
            + PadWithLeadingZero(stoi(Format12Hour(dateTime->hour))) + ":"
            + PadWithLeadingZero(dateTime->minute) + ":"
            + PadWithLeadingZero(dateTime->second) + " "
            + GetAmPm(dateTime->hour);
        break;
     
    case DDMMYYYY_hhmmss:
        dateTimeFormatted = PadWithLeadingZero(dateTime->day) + "-"
            + PadWithLeadingZero(dateTime->month) + "-"
            + to_string(dateTime->year) + " "
            + PadWithLeadingZero(stoi(Format12Hour(dateTime->hour))) + ":"
            + PadWithLeadingZero(dateTime->minute) + ":"
            + PadWithLeadingZero(dateTime->second) + " "
            + GetAmPm(dateTime->hour); 
        break;

    case YYYYMMDDHHmmss:
        dateTimeFormatted = to_string(dateTime->year)
            + PadWithLeadingZero(dateTime->month)
            + PadWithLeadingZero(dateTime->day)
            + PadWithLeadingZero(dateTime->hour)
            + PadWithLeadingZero(dateTime->minute)
            + PadWithLeadingZero(dateTime->second);
        break;

	case DDMMYYYY_HHmmss:
        dateTimeFormatted = PadWithLeadingZero(dateTime->day) + "-"
            + PadWithLeadingZero(dateTime->month) + "-"
            + to_string(dateTime->year) + " "
            + PadWithLeadingZero(dateTime->hour) + ":"
            + PadWithLeadingZero(dateTime->minute) + ":"
            + PadWithLeadingZero(dateTime->second);
        break;

    case YYMD_Hms:
        dateTimeFormatted = to_string(dateTime->year % 100) + "-"
            + to_string(dateTime->month) + "-"
            + to_string(dateTime->day) + " "
            + to_string(dateTime->hour) + ":"
            + to_string(dateTime->minute) + ":"
            + to_string(dateTime->second);
        break;

    case YYMD_hms:
        dateTimeFormatted = to_string(dateTime->year % 100) + "-"
            + to_string(dateTime->month) + "-"
            + to_string(dateTime->day) + " "
            + Format12Hour(dateTime->hour) + ":"
            + to_string(dateTime->minute) + ":"
            + to_string(dateTime->second) + " "
            + GetAmPm(dateTime->hour);
        break;

    case DMYY_hms:
        dateTimeFormatted = to_string(dateTime->day) + "-"
            + to_string(dateTime->month) + "-"
            + to_string(dateTime->year % 100) + " "
            + Format12Hour(dateTime->hour) + ":"
            + to_string(dateTime->minute) + ":"
            + to_string(dateTime->second) + " "
            + GetAmPm(dateTime->hour);
        break;

    case DMYY_Hms:
        dateTimeFormatted = to_string(dateTime->day) + "-"
            + to_string(dateTime->month) + "-"
            + to_string(dateTime->year % 100) + " "
            + to_string(dateTime->hour) + ":"
            + to_string(dateTime->minute) + ":"
            + to_string(dateTime->second);
        break;
    }

    return dateTimeFormatted;
}

string GetAmPm(int hour) {
    if (hour >= 12) {
        return "p.m.";
    }
    else {
        return "a.m.";
    }
}

string Format12Hour(int hour)
{
    if (hour == 0)
        return "12";
    else if (hour <= 12)
        return to_string(hour);
    else
        return to_string(hour - 12);
}

string PadWithLeadingZero(int timeUnit)
{
    string text = to_string(timeUnit);

    if (timeUnit < 10) {
        return "0" + text;
    }
    else {
        return text;
    }
}

void UDateTime::DestroyDateTime(DateTime* dateTime)
{
    delete dateTime;
}

DateTime* UDateTime::Now()
{
    time_t epochTime = system_clock::to_time_t(system_clock::now());
    tm localTime = {};
    localtime_s(&localTime, &epochTime);

    int year = localTime.tm_year + 1900;
    int month = localTime.tm_mon + 1;
    int day = localTime.tm_mday;
    int hour = localTime.tm_hour;
    int minute = localTime.tm_min;
    int second = localTime.tm_sec;

    return CreateDateTime(year, month, day, hour, minute, second);
}

DateTime* UDateTime::CreateDateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, int minutes, int seconds)
{
    DateTime* dateTime = new DateTime;
    dateTime->year = year;
    dateTime->month = month;
    dateTime->day = day;
    dateTime->hour = hour;
    dateTime->minute = minutes;
    dateTime->second = seconds;

    return dateTime;
}

unsigned int UDateTime::GetYear(const DateTime* dateTime)
{
    return dateTime->year;
}

unsigned int UDateTime::GetMonth(const DateTime* dateTime)
{
    return dateTime->month;
}

unsigned int UDateTime::GetDay(const DateTime* dateTime)
{
    return dateTime->day;
}

unsigned int UDateTime::GetHour(const DateTime* dateTime)
{
    return dateTime->hour;
}

unsigned int UDateTime::GetMinutes(const DateTime* dateTime)
{
    return dateTime->minute;
}

unsigned int UDateTime::GetSeconds(const DateTime* dateTime)
{
    return dateTime->second;
}
