#ifndef _PATIENTACCOUNT_H_
#define _PATIENTACCOUNT_H_

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Surgery.h"
#include "Medication.h"

using namespace std;

class PatientAccount
{
 private:
  const long patientAccountNum; // =nextPatientAccountNum
  string firstName;
  string lastName;
  long SSN;
  char gender;
  int age;
  double dailyRate;
  Date admitDate;
  Date dischargeDate;
  vector <Surgery> patientSurgeries;
  vector <Medication> patientMedications;
  static long nextPatientAccountNum;
 public:
  PatientAccount();
  PatientAccount(string pFName, string pLName, long pSSN, char pGender, int pAge, double pRate, int aMonth, int aDay, int aYear);
  ~PatientAccount();
  void addSurgery(int sCode, string sDescription, long sCharge);
  void addMedication(int mCode, string mDescription, long mCharge);
  void setDischargeDate(int dMonth, int dDay, int dYear);
  int getSurgerySize();
  int getMedicationSize();
  long getSurgeryCharge(int i);
  long getMedicationCharge(int i);
  string getSurgeryDescription(int i);
  string getMedicationDescription(int i);
  long getPatientAccountNum();
  string getFName();
  string getLName();
  long getSSN();
  string getGender();
  int getAge();
  double getRate();
  int getAdmitMonth();
  int getAdmitDay();
  int getAdmitYear();
  int getDischargeMonth();
  int getDischargeDay();
  int getDischargeYear();
};

#endif
