#include "Medication.h"

Medication::Medication()
{
}

Medication::Medication(int mCode, string mDescription, double mCharge)
{
  medicationCode = mCode;
  medicationDescription = mDescription;
  medicationCharge = mCharge;
}

Medication::~Medication()
{
}

int Medication::getMedicationCode()
{
  return medicationCode;
}

string Medication::getMedicationDescription()
{
  return medicationDescription;
}

double Medication::getMedicationCharge()
{
  return medicationCharge;
}
