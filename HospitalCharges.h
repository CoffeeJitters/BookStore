#ifndef _HOSPITALCHARGES_H_
#define _HOSPITALCHARGES_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Surgery.h"
#include "Medication.h"
#include "PatientAccount.h"

using namespace std;

class HospitalCharges
{
 private:
  vector <Surgery> surgeries;
  vector <Medication> medications;
  vector <PatientAccount> patientsAccounts;
 public:
  HospitalCharges();
  ~HospitalCharges();
  void CreateNewPatient(string pFName, string pLName, long pSSN, char pGender, int pAge, double pRate, int aMonth, int aDay, int aYear);
  void CreateNewSurgery(int sCode, string sDescription, double sCharge);
  void CreateNewMedication(int mCode, string mDescription, double mCharge);
  void AddPatientSurgery(int sCode, long pNum);
  void AddPatientMedication(int mCode, long pNum);
  void PrintAllPatientAccounts() const;
  void PrintAllSurgeries();
  void PrintAllMedications();
  void DischargePatient(long pNum, int dMonth, int dDay, int dYear);
  void CalculatePatientBill(long pNum);
  void ProcessTransactionFile(string fileName);
  bool isDateValid(int month, int day, int year);
  bool leapYear(int year);
  int calculateDay(int y, int m, int d);
};

#endif
