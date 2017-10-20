#ifndef _MEDICATION_H_
#define _MEDICATION_H_

#include <string>

using namespace std;

class Medication
{
 private:
  int medicationCode;
  string medicationDescription;
  double medicationCharge;
 public:
  Medication();
  Medication(int mCode, string mDescription, double mCharge);
  ~Medication();
  int getMedicationCode();
  string getMedicationDescription();
  double getMedicationCharge();
};

#endif
