#ifndef _DATE_H_
#define _DATE_H_

class Date
{
 private:
  int month;
  int day;
  int year;
 public:
  Date();
  ~Date();
  void setMonth(int aMonth);
  void setDay(int aDay);
  void setYear(int aYear);
  int getMonth();
  int getDay();
  int getYear();

};

#endif
