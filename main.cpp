#include<iostream>
#include<string>
#include"Functions.h"
#include"Patient.h"
#include"PatientRecord.h"
#include"Emergency.h"
using namespace std;
int main()
{
	Emergency e1;
	int userCommand = NULL,condition = NULL;
	string name,birthDate,bloodGroup;
	cout << "\t- H O S P I T A L    E M E R G E N C Y    W A R D -" << endl;
	while (true)
	{
		cout << "\n\t\t    - O P E R A T I O N S -\n";
		cout << "\n1.Add Patient\n2.Remove Patient\n3.Display Ward\n4.Exit\n";
		while (cout << "\nEnter the Desired Option : " && !(cin >> userCommand))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid Input! Please Enter the Integer Input.\n";
		}
		// ****************************** ADD PATIENT **************************
		if (userCommand == 1)
		{
			cout << "\n\t\t    - C O N D I T I O N S -\n";
			cout << "\n1.Unresponsive\n2.Respiratory Arrest\n3.Unconscious\n4.Major Trauma\n5.Shock\n";
		nameInput:
			cin.ignore();
			cout << "\nEnter the Patient's Name : ";
			getline(cin, name);
			if (!(nameFormat(name)))
			{
				cout << "\nInvalid Input. Please Enter the Name in Vaild Format.\n";
				goto nameInput;
			}
		birthDateInput:
			cout << "Enter the Date of Birth : ";
			getline(cin, birthDate);
			if (!(birthDateFormat(birthDate)))
			{
				cout << "\nInvalid Input. Please Enter the Birthdate in Vaild Format.\n";
				goto birthDateInput;
			}
		bloodGroupInput:
			cout << "Enter the Blood Group : ";
			getline(cin, bloodGroup);
			if (!(bloodGroupFormat(bloodGroup)))
			{
				cout << "\nInvalid Input. Please Enter the Blood Group in Vaild Format.\n";
				goto bloodGroupInput;
			}
		ConditionInput:
			while (cout << "Enter the Condition : " && !(cin >> condition))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input! Please Enter the Integer Input.\n";
			}
			if (condition == 1)
				e1.addPatient(name,birthDate,bloodGroup,"Unresponsive");
			else if (condition == 2)
				e1.addPatient(name, birthDate, bloodGroup, "Respiratory Arrest");
			else if (condition == 3)
				e1.addPatient(name, birthDate, bloodGroup, "Unconscious");
			else if (condition == 4)
				e1.addPatient(name, birthDate, bloodGroup, "Major Trauma");
			else if (condition == 5)
				e1.addPatient(name, birthDate, bloodGroup, "Shock");
			else
			{
				cout << "\nInvalid Input! Please Input Again.\n";
				goto ConditionInput;
			}
	
		}
		// ****************************** REMOVE PATIENT **************************
		else if (userCommand == 2)
		{
			cout << "\nEnter the Patient's Name : ";
			cin.ignore();
			getline(cin, name);
			e1.removePatient(name);
		}
		// ****************************** DISPLAY WARD **************************
		else if (userCommand == 3)
		{
			e1.display();
		}
		// ****************************** EXIT **************************
		else if (userCommand == 4)
		{
			cout << "\nExiting.\n";
			break;
		}
		// ****************************** INVALID INPUT **************************
		else
		{
			cout << "\nInvalid Input! Please Input Again.\n";
		}
	}
	return 0;
}