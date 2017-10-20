#include "Surgery.h"

Surgery::Surgery()
{
}

Surgery::Surgery(int sCode, string sDescription, double sCharge)
{
  surgeryCode = sCode;
  surgeryDescription = sDescription;
  surgeryCharge = sCharge;
}

Surgery::~Surgery()
{
}

int Surgery::getSurgeryCode()
{
  return surgeryCode;
}

string Surgery::getSurgeryDescription()
{
  return surgeryDescription;
}

double Surgery::getSurgeryCharge()
{
  return surgeryCharge;
}
