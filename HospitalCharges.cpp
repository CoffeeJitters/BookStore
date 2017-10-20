#include "HospitalCharges.h"

HospitalCharges::HospitalCharges()
{
}

HospitalCharges::~HospitalCharges()
{
}

//Checks if the date entered is valid
//if so it then checks if the vector has zero elements
//if it doesn't it iterates through the vector to see if there's already an account with an identifical SSN
//if it doesn't then the function emplaces back to that vector a series of values that correspond to its data type's constructor
void HospitalCharges::CreateNewPatient(string pFName, string pLName, long pSSN, char pGender, int pAge, double pRate, int aMonth, int aDay, int aYear)
{
  bool existance = false;

  if (!isDateValid(aMonth, aDay, aYear))//check if data entered is valid
    cout << "Invalid date entry." << endl;
  else {
    if (patientsAccounts.size() == 0) {//check if the size of the vector is still at 0 and if so it immediately emplaces to the back of the vector
      patientsAccounts.emplace_back(pFName, pLName, pSSN, pGender, pAge, pRate, aMonth, aDay, aYear);
      cout << pFName << " " << pLName << " account successfully created." << endl;
    }
    else {
      for (PatientAccount c : patientsAccounts)
	if (c.getSSN() == pSSN) {//checking if the SSN already eists
	  cout << "An account for " << pFName << " " << pLName << " already exists." << endl;
	  existance = true;// ^ if so then it sets bool var to true and breaks off the loop
	  break;
	}
      if (existance != true) {//if the existance variable never manages to become true then it emplaces to the back of the vector
	patientsAccounts.emplace_back(pFName, pLName, pSSN, pGender, pAge, pRate, aMonth, aDay, aYear);
	cout << pFName << " " << pLName << " account successfully created." << endl;
      }
    }
  }
}

void HospitalCharges::CreateNewSurgery(int sCode, string sDescription, double sCharge)
{
  bool existance = false;

  if (sCharge == 0)//if the charge is 0, the function stops here
    cout << "Invalid charge, can not create new entry." << endl;
  else {
    for (Surgery c : surgeries) {
      if (c.getSurgeryCode() == sCode) {//check to see if the code already exists
	cout << "This surgery code already exists, can not create a new entry." << endl;
	existance = true;
      }
      else if (c.getSurgeryDescription() == sDescription) {//check if the surgery name already exists
	cout << "This surgery already exists, can not create a new entry." << endl;
	existance = true;
      }
    }
    if (existance != true) {//if the bool function never manages to become "true" it emplaces a new surgery
      surgeries.emplace_back(sCode, sDescription, sCharge);
      cout << "Surgery entry successfully created." << endl;
    }
  }
}

void HospitalCharges::CreateNewMedication(int mCode, string mDescription, double mCharge)
{
  bool existance = false;

  if (mCharge <= 0)//if the charge is 0, the function stops here
    cout << "Invalid charge, can not create new entry." << endl;
  else {
    for (Medication c : medications) {
      if (c.getMedicationCode() == mCode) {//if medications already exists it will not add another
	cout << "This medication code already exists, can not create a new entry." << endl;
	existance = true;
      }
      else if (c.getMedicationDescription() == mDescription) {//if name of meds already exist it won't create another 
	cout << "This surgery code already exists, can not create a new entry." << endl;
	existance = true;
      }
    }
    if (existance != true) {//if things never manage to be true in here then it creates a new element of medications with appropriate variables
      medications.emplace_back(mCode, mDescription, mCharge);
      cout << "Medication entry successfully created." << endl;
    }
  }
}

void HospitalCharges::AddPatientSurgery(int sCode, long pNum)
{
  bool existance = false;
  string sDescription;
  long sCharge;

  if (pNum < 1000)
    cout << "Invalid patient account number." << endl;
  else {
    for (Surgery c : surgeries)
      if (c.getSurgeryCode() == sCode) {//if surgery code is valid
	existance = true;//it sets bool to true
	sDescription = c.getSurgeryDescription();
	sCharge = c.getSurgeryCharge();
	break;
      }

    if (existance) {//if bool never manages to be true it creates new surgery to account
      for (PatientAccount& c : patientsAccounts)
	if (c.getPatientAccountNum() == pNum) {
	  c.addSurgery(sCode, sDescription, sCharge);
	  break;
	}
    }
    else
      cout << "Invalid patient surgery." << endl;
  }
}

void HospitalCharges::AddPatientMedication(int mCode, long pNum)
{
  bool existance = false;
  string mDescription;
  long mCharge;

  if (pNum < 1000)//ids aren't under 1000
    cout << "Invalid patient account number." << endl;
  else {
    for (Medication c : medications)
      if (c.getMedicationCode() == mCode) {//check if med code matches an existing one
	existance = true;
	mDescription = c.getMedicationDescription();//initializing appropriate vars before break
	mCharge = c.getMedicationCharge();
	break;
      }

    if (existance) {
      for (PatientAccount& c : patientsAccounts)
	if (c.getPatientAccountNum() == pNum) {//checking if the pNum matches an existing patient
	  c.addMedication(mCode, mDescription, mCharge);//if so it adds medication to his account
	  break;
	}
    }
    else
      cout << "Invalid patient medication." << endl;
  }
}

//function that prints all information on patients on record
void HospitalCharges::PrintAllPatientAccounts() const
{
  for (PatientAccount c : patientsAccounts) {
    cout << endl;
    cout << c.getFName() << " " << c.getLName() << ", " << c.getGender() << ", " << c.getAge() << endl;
    cout << "Patient ID: " << c.getPatientAccountNum() << endl;
    cout << "Admitted on: " << c.getAdmitMonth() << "/" << c.getAdmitDay() << "/" << c.getAdmitYear() << endl;
    cout << "Discharged on: " << c.getDischargeMonth() << "/" << c.getDischargeDay() << "/" << c.getDischargeYear() << endl;
    cout << "Surgeries: ";
    for (int i = 0; i < c.getSurgerySize(); i++) {
      cout << c.getSurgeryDescription(i);
      if (i + 1 < c.getSurgerySize())
	cout << ", ";
    }
    cout << endl;
    cout << "Medications: ";
    for (int i = 0; i < c.getMedicationSize(); i++) {
      cout << c.getMedicationDescription(i);
      if (i + 1 < c.getMedicationSize())
	cout << ", ";
    }
    cout << endl;
  }
}

//prints a list of all surgery in the system and other details
void HospitalCharges::PrintAllSurgeries()
{
  cout << endl;
  cout << left << setw(15) << "SurgeryCode"
       << setw(20) << "Description"
       << setw(13) << "Charge" << endl;
  cout << "------------------------------------------" << endl;
  for (Surgery c : surgeries) {
    cout << setw(15) << c.getSurgeryCode()
	 << setw(20) << c.getSurgeryDescription()
	 << setw(13) << c.getSurgeryCharge() << endl;
  }
  cout << endl;
}

//prints a list of all medication in the system and other details
void HospitalCharges::PrintAllMedications()
{
  cout << endl;
  cout << left << setw(15) << "MedicationCode"
       << setw(20) << "Description"
       << setw(13) << "Charge" << endl;
  cout << "------------------------------------------" << endl;
  for (Medication c : medications) {
    cout << setw(15) << c.getMedicationCode()
	 << setw(20) << c.getMedicationDescription()
	 << setw(13) << c.getMedicationCharge() << endl;
  }
  cout << endl;
}

void HospitalCharges::DischargePatient(long pNum, int dMonth, int dDay, int dYear)
{
  bool existance = true;
  if (!isDateValid(dMonth, dDay, dYear))
    cout << "Invalid discharge date." << endl;
  else if (pNum < 1000)
    cout << "Invalid patient account number." << endl;
  else {
    for (PatientAccount& c : patientsAccounts) {
      if (c.getPatientAccountNum() == pNum) {//if pNum matches it begins checking whether the discharge date is later than the date admitted
	existance = true;
	if (c.getAdmitYear() > dYear) {
	  cout << "Invalid discharge date." << endl;
	  break;
	}
	else if (c.getAdmitYear() == dYear) {
	  if (c.getAdmitMonth() > dMonth) {
	    cout << "Invalid discharge date." << endl;
	    break;
	  }
	  else if (c.getAdmitMonth() == dMonth) {
	    if (c.getAdmitDay() > dDay) {
	      cout << "Invalid discharge date." << endl;
	      break;
	    }
	    else {
	      c.setDischargeDate(dMonth, dDay, dYear);
	      cout << "Patient " << pNum << " successfully discharged" << endl;
	      break;
	    }
	  }
	}
	else {
	  c.setDischargeDate(dMonth, dDay, dYear);
	  cout << "Patient " << pNum << " successfully discharged" << endl;
	  break;
	}
      }
      else
	existance = false;
    }
    if (!existance)
      cout << "Invalid patient account number." << endl;
  }
}

void HospitalCharges::CalculatePatientBill(long pNum)
{
  for (PatientAccount c : patientsAccounts) {
    if (c.getPatientAccountNum() == pNum) {
      if (c.getDischargeDay() == 0) {
	cout << "Patient " << pNum << " is still in hospital." << endl;
	break;
      }
      else {
	int charges = 0;
	int days = calculateDay(c.getDischargeYear(), c.getDischargeMonth(), c.getDischargeDay()) - calculateDay(c.getAdmitYear(), c.getAdmitMonth(), c.getAdmitDay());//subtracting 2 dates set to their days
	double chargesofar = days * c.getRate();
	for (int i = 0; i < c.getSurgerySize(); i++) {
	  charges += c.getSurgeryCharge(i);
	}
	for (int i = 0; i < c.getMedicationSize(); i++) {
	  charges += c.getMedicationCharge(i);
	}
	double total = chargesofar + charges;
	cout << fixed << setprecision(2) << "Patient " << pNum << " bill is " << total << "." << endl;
	break;
      }
    }
  }
}

void HospitalCharges::ProcessTransactionFile(string fileName)
{
  ifstream inputFile;
  inputFile.open(fileName);

  if (inputFile.is_open()) {
    string action;

    inputFile >> action;

    //this while loop reads from the transaction file and then tries ot match it with the first word. 
    //once it reaches on of file then that's it for the entire program basically
    while (!inputFile.eof()) {//while the file doesn't reach the end

      //the function order matches that of the transaction file
      if (action == "CreateNewPatient") {
	string pFName, pLName;
	long pSSN;
	char pGender;
	int pAge, aMonth, aDay, aYear;
	double pRate;

	do {
	  inputFile >> pFName
		    >> pLName
		    >> pSSN
		    >> pGender
		    >> pAge
		    >> pRate
		    >> aMonth
		    >> aDay
		    >> aYear
		    >> action;

	  CreateNewPatient(pFName, pLName, pSSN, pGender, pAge, pRate, aMonth, aDay, aYear);
	} while (action == "CreateNewPatient" && !inputFile.eof());
      }
      else if (action == "PrintAllPatientAccounts") {
	PrintAllPatientAccounts();

	inputFile >> action;
      }
      else if (action == "CreateNewSurgery") {
	int sCode;
	string sDescription;
	double sCharge;

	cout << endl;
	do {
	  inputFile >> sCode
		    >> sDescription
		    >> sCharge
		    >> action;

	  CreateNewSurgery(sCode, sDescription, sCharge);
	} while (action == "CreateNewSurgery" && !inputFile.eof());
      }
      else if (action == "PrintAllSurgeries") {
	PrintAllSurgeries();

	inputFile >> action;
      }
      else if (action == "CreateNewMedication") {
	int mCode;
	string mDescription;
	double mCharge;

	cout << endl;
	do {
	  inputFile >> mCode
		    >> mDescription
		    >> mCharge
		    >> action;

	  CreateNewMedication(mCode, mDescription, mCharge);
	} while (action == "CreateNewMedication" && !inputFile.eof());
      }
      else if (action == "PrintAllMedications") {
	PrintAllMedications();

	inputFile >> action;
      }
      else if (action == "AddPatientSurgery") {
	int sCode;
	long pNum;

	do {
	  inputFile >> sCode
		    >> pNum
		    >> action;

	  AddPatientSurgery(sCode, pNum);
	} while (action == "AddPatientSurgery" && !inputFile.eof());
	cout << endl;
      }
      else if (action == "AddPatientMedication") {
	int mCode;
	long pNum;

	do {
	  inputFile >> mCode
		    >> pNum
		    >> action;

	  AddPatientMedication(mCode, pNum);
	} while (action == "AddPatientMedication" && !inputFile.eof());
	cout << endl;
      }
      else if (action == "DischargePatient") {
	long pNum;
	int dMonth, dDay, dYear;

	cout << endl;
	do {
	  inputFile >> pNum
		    >> dMonth
		    >> dDay
		    >> dYear
		    >> action;

	  DischargePatient(pNum, dMonth, dDay, dYear);
	} while (action == "DischargePatient" && !inputFile.eof());
      }
      else if (action == "CalculatePatientBill") {
	long pNum;

	cout << endl;
	do {
	  inputFile >> pNum
		    >> action;

	  CalculatePatientBill(pNum);
	} while (action == "CalculatePatientBill" && !inputFile.eof());
	cout << endl;
      }
    }
  }
}

bool HospitalCharges::isDateValid(int month, int day, int year)
{
  bool validation = true;//return value is initially true
  if (!(year >= 1600 && year <= 2100))//if year is not >= 1600 && <= 2100
    validation = false;//then validation is false

  if (day < 1)//if day is < 1
    validation = false;//then validation is false

  switch (month)
    {
    case 2:
      if (leapYear(year)) // We only care about leap years in February 
	if (day > 29)//if day is > 29
	  validation = false;//then validation is false
	else
	  if (day > 28)//if day > 28
	    validation = false;//then validation is false
      break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12://for these particular month entries
      if (day > 31)//if day > 31
	validation = false;//then validation is false
      break;
    case 4: case 6: case 9: case 11://for these particular month entries
      if (day > 30)//if day > 30
	validation = false;//then validation is false
      break;
    default:// the month is not between 1 and 12
      validation = false;//then validation is false
      break;
    }
  return validation;
}

bool HospitalCharges::leapYear(int year)
{
  return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);//bool function on whether the year inputed is on a leap year or not
}

//algorithm for turning a data to a number of days. very complicate
int HospitalCharges::calculateDay(int y, int m, int d) {
  m = (m + 9) % 12;
  y = y - m / 10;
  return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}
