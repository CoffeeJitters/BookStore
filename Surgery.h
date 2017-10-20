#ifndef _SURGERY_H_
#define _SURGERY_H_

#include <string>

using namespace std;

class Surgery
{
 private:
  int surgeryCode;
  string surgeryDescription;
  double surgeryCharge;
 public:
  Surgery();
  Surgery(int sCode, string sDescription, double sCharge);
  ~Surgery();
  int getSurgeryCode();
  string getSurgeryDescription();
  double getSurgeryCharge();
};

#endif
