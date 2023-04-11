#include<iostream>
#include<string>4
#include"Functions.h"
#include"Patient.h"
using namespace std;
#ifndef PatientRecord_H
#define PatientRecord_H
class PatientRecord
{
private:
	Patient record;
	PatientRecord* next;
public:
	PatientRecord() // Default Constructor
	{
		next = NULL;
	}
	void setRecord(string name, string dateOfBirth, string bloodGroup, string condition)
	{
		record.setName(name);
		record.setDateOfBirth(dateOfBirth);
		record.setBloodGroup(bloodGroup);
		record.setCondition(condition);
	}
	void setNext(PatientRecord* next)
	{
		this->next = next;
	}
	Patient getRecord()
	{
		return record;
	}
	PatientRecord* getNext()
	{
		return next;
	}

};
#endif