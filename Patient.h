#include<iostream>
#include<string>4
#include"Functions.h"
using namespace std;
#ifndef Patient_H
#define Patient_H
class Patient
{
private:
	string name;
	string dateOfBirth;
	string bloodGroup;
	string condition;
public:
	Patient() // Default Constructor
	{
		name = "";
		dateOfBirth = "";
		bloodGroup = "";
		condition = "";
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setDateOfBirth(string dateOfBirth)
	{
		this->dateOfBirth = dateOfBirth;
	}
	void setBloodGroup(string bloodGroup)
	{
		this->bloodGroup = bloodGroup;
	}
	void setCondition(string condition)
	{
		this->condition = condition;
	}
	string getName()
	{
		return name;
	}
	string getDateOfBirth()
	{
		return dateOfBirth;
	}
	string getBloodGroup()
	{
		return bloodGroup;
	}
	string getCondition()
	{
		return condition;
	}
};
#endif