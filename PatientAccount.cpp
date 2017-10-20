#include "PatientAccount.h"

long PatientAccount::nextPatientAccountNum = 1000;

PatientAccount::PatientAccount() : patientAccountNum(nextPatientAccountNum)
{
  nextPatientAccountNum++;
}

PatientAccount::PatientAccount(string pFName, string pLName, long pSSN, char pGender, int pAge, double pRate, int aMonth, int aDay, int aYear) : patientAccountNum(nextPatientAccountNum)
{
  firstName = pFName;
  lastName = pLName;
  SSN = pSSN;
  gender = pGender;
  age = pAge;
  dailyRate = pRate;
  admitDate.setMonth(aMonth);
  admitDate.setDay(aDay);
  admitDate.setYear(aYear);
  dischargeDate.setMonth(0);
  dischargeDate.setDay(0);
  dischargeDate.setYear(0);
  nextPatientAccountNum++;
}

PatientAccount::~PatientAccount()
{
}

//emplacing vectors within PatientAccount
void PatientAccount::addSurgery(int sCode, string sDescription, long sCharge)
{
  patientSurgeries.emplace_back(sCode, sDescription, sCharge);
  cout << sDescription << " successfully added to " << firstName << " " << lastName << "'s account." << endl;
}

//emplacing vectors within PatientAccount
void PatientAccount::addMedication(int mCode, string mDescription, long mCharge)
{
  patientMedications.emplace_back(mCode, mDescription, mCharge);
  cout << mDescription << " successfully added to " << firstName << " " << lastName << "'s account." << endl;
}

//set discharge day
void PatientAccount::setDischargeDate(int dMonth, int dDay, int dYear) {
  dischargeDate.setMonth(dMonth);
  dischargeDate.setDay(dDay);
  dischargeDate.setYear(dYear);
}

int PatientAccount::getSurgerySize() {
  return patientSurgeries.size();
}

int PatientAccount::getMedicationSize() {
  return patientMedications.size();
}

long PatientAccount::getSurgeryCharge(int i) {
  return patientSurgeries[i].getSurgeryCharge();
}

long PatientAccount::getMedicationCharge(int i) {
  return patientMedications[i].getMedicationCharge();
}

string PatientAccount::getSurgeryDescription(int i) {
  return patientSurgeries[i].getSurgeryDescription();
}

string PatientAccount::getMedicationDescription(int i) {
  return patientMedications[i].getMedicationDescription();
}

long PatientAccount::getPatientAccountNum()
{
  return patientAccountNum;
}

string PatientAccount::getFName()
{
  return firstName;
}

string PatientAccount::getLName()
{
  return lastName;
}

long PatientAccount::getSSN()
{
  return SSN;
}

//returns male or female depending on what a person chooses
string PatientAccount::getGender()
{
  if (gender == 'M')
    return "Male";
  else if (gender == 'F')
    return "Female";
}

int PatientAccount::getAge()
{
  return age;
}

double PatientAccount::getRate()
{
  return dailyRate;
}

int PatientAccount::getAdmitMonth()
{
  return admitDate.getMonth();
}

int PatientAccount::getAdmitDay()
{
  return admitDate.getDay();
}

int PatientAccount::getAdmitYear()
{
  return admitDate.getYear();
}

int PatientAccount::getDischargeMonth()
{
  return dischargeDate.getMonth();
}

int PatientAccount::getDischargeDay()
{
  return dischargeDate.getDay();
}

int PatientAccount::getDischargeYear()
{
  return dischargeDate.getYear();
}
