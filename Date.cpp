#include "Date.h"

Date::Date()
{
}

Date::~Date()
{
}

void Date::setMonth(int aMonth)
{
  month = aMonth;
}

void Date::setDay(int aDay)
{
  day = aDay;
}

void Date::setYear(int aYear)
{
  year = aYear;
}

int Date::getMonth()
{
  return month;
}

int Date::getDay()
{
  return day;
}

int Date::getYear()
{
  return year;
}
