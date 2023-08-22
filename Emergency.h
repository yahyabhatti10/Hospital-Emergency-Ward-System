#include<iostream>
#include<string>
#include"Functions.h"
#include"Patient.h"
#include"PatientRecord.h"
using namespace std;
#ifndef	Emergency_H
#define Emergency_H
class Emergency
{
private:
	PatientRecord* front;
	PatientRecord* rear;
	int noOfPatients;
public:
	Emergency() // Default Constructor
	{
		front = NULL;
		rear = NULL;
		noOfPatients = NULL;
	}
	// ************* ADDING THE PATIENT *************
	void addPatient(string name, string dateOfBirth, string bloodGroup, string condition)
	{
		PatientRecord* newPatient = new PatientRecord;
		if (front == NULL && rear == NULL) // If Queue is Empty
		{
			front = newPatient;
			newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
			newPatient->setNext(NULL);
			rear = newPatient;
		}
		else if (front == rear) // If there is one patient in the Queue
		{
			if (checkCondition(front->getRecord().getCondition()) > checkCondition(condition))
			{
				front->setNext(newPatient);
				newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
				newPatient->setNext(NULL);
				rear = newPatient;
			}
			else if (checkCondition(front->getRecord().getCondition()) < checkCondition(condition))
			{
				newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
				newPatient->setNext(front);
				front = newPatient;
			}
			else
			{
				rear = newPatient;
				newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
				newPatient->setNext(NULL);
				front->setNext(newPatient);
			}
		}
		else // If there are two or more than two patients in a Queue
		{
			if (checkCondition(front->getRecord().getCondition()) < checkCondition(condition))
			{
				newPatient->setNext(front);
				newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
				front = newPatient;
			}
			else
			{
				PatientRecord* previous = front;
				PatientRecord* current = front->getNext();
				while (previous->getNext() != NULL)
				{
					if (checkCondition(condition) > checkCondition(current->getRecord().getCondition()))
					{
						previous->setNext(newPatient);
						newPatient->setNext(current);
						newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
						break;

					}
					else if (current == rear && checkCondition(condition) < checkCondition(current->getRecord().getCondition()))
					{
						rear = newPatient;
						newPatient->setNext(NULL);
						newPatient->setRecord(name, dateOfBirth, bloodGroup, condition);
						current->setNext(newPatient);
						break;

					}
					else
					{
						previous = previous->getNext();
						current = current->getNext();
					}
				}
			}
		}
		noOfPatients++;
	}
	// ************* REMOVING THE PATIENT *************
	void removePatient(string name)
	{
		if (isEmpty())
		{
			cout << "Cannot	Remove ! Emergency Ward is already empty.\n";
		}
		else
		{
			PatientRecord* current = front;
			if (current == front && current->getRecord().getName() == name)
			{
				front = front->getNext();
				delete current;
			}
			else
			{
				while (current->getNext()->getRecord().getName() != name)
				{
					current = current->getNext();
				}
				if (current->getNext() == rear && current->getNext()->getRecord().getName() == name)
				{
					delete current->getNext();
					current->setNext(NULL);
					rear = current;
				}
				else
				{
					PatientRecord* removingPatient = current->getNext();
					current->setNext(current->getNext()->getNext());
					delete removingPatient;
				}
			}
			noOfPatients--;
		}
	}
	// ************* DISPLAYING THE QUEUE *************
	void display()
	{
		if (isEmpty())
		{
			cout << "Cannot	Display ! Emergency Ward is already empty.\n";
		}
		else
		{
			PatientRecord* current = front;
			cout << "\n\t        - E M E R G E N C Y    W A R D -\n";
			cout << "\nName\tBirth Date\tBlood Group\tCondition\n";
			cout << "-----------------------------------------------------\n";
			while (current != NULL)
			{
				cout << current->getRecord().getName() << "\t" << current->getRecord().getDateOfBirth() << "\t" << current->getRecord().getBloodGroup() << "\t\t" << current->getRecord().getCondition() << "\n";
				current = current->getNext();
			}
		}
	}
	bool isEmpty()
	{
		return(noOfPatients == 0);
	}
};
#endif
