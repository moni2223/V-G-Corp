#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "../task1/Ticket.h"


class VandG_Corp
{
private:
	vector <Employee*> all_employees;
	int budget;
public:
	VandG_Corp();
	VandG_Corp(int budget);

	void add_employee(Employee* current);
	void remove_employee(Employee* current);

	bool check_if_employee_exist(int id);

	Employee* get_employee(int id) const;
	void print() const;
	~VandG_Corp();
};