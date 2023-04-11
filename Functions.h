#include<iostream>
#include<string>
using namespace std;
#ifndef Functions_H
#define Functions_H
int checkCondition(string condition)
{
	if (condition == "Shock")
		return 1;
	else if (condition == "Major Trauma")
		return 2;
	else if (condition == "Unconscious")
		return 3;
	else if (condition == "Respiratory Arrest")
		return 4;
	else if (condition == "Unresponsive")
		return 5;
	else
		return 0;
}

bool nameFormat(string name)
{
	int size = name.length();
	bool check = NULL;
	for (int i = 0; i < size; i++)
	{
		if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))
			check = true;
		else
		{
			check = false;
			break;
		}
	}
	return check;
}

bool bloodGroupFormat(string bloodGroup)
{
	int size = bloodGroup.length();
	bool check = NULL;
	if ((bloodGroup[0] == 65 || bloodGroup[0] == 66 || bloodGroup[0] == 79) && (bloodGroup[1] == 43 || bloodGroup[1] == 45) && size == 2)
		check = true;
	else if (bloodGroup[0] == 65 && bloodGroup[1] == 66 && (bloodGroup[2] == 43 || bloodGroup[2] == 45) && size == 3)
		check = true;
	else
		check = false;
	return check;
}

bool birthDateFormat(string birthDate)
{
	int size = birthDate.length();
	bool check = NULL;
	for (int i = 0; i < size; i++)
	{
		if (birthDate[i] >= 48 || birthDate[i] <= 57 || birthDate[i] == 45)
			check = true;
		else
		{
			check = false;
			break;
		}
	}
	if (size == 10 && check)
		return true;
	else
		return false;
}
#endif
