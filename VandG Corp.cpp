#include "VandG Corp.h"

VandG_Corp::VandG_Corp() :budget(0) 
{}

VandG_Corp::VandG_Corp(int budget) : budget(budget) 
{}

void VandG_Corp::add_employee(Employee* current) 
{
	int wagesbudget = 0;
	for (int i = 0; i < all_employees.size(); i++)
	{
		wagesbudget += all_employees[i]->get_salary();
	}

	if (budget - (wagesbudget + current->get_salary()) < 1000)
	{
		cout << "Budget is going low." << endl;
		return;
	}

	for (int i = 0; i < all_employees.size(); i++)
	{
		if (all_employees[i]->get_id() == current->get_id()) 
		{
			cout << "We already have employee with that id." << endl;
			return;
		}
	}
    all_employees.push_back(current);
}

void VandG_Corp::remove_employee(Employee* current) 
{
	for (int i = 0; i < all_employees.size(); i++)
	{
		if (all_employees[i]->get_id() == current->get_id())
		{
			if (i == 0) 
				all_employees.erase(all_employees.begin());
			
			else
				all_employees.erase(all_employees.begin() + i - 1);
			
			return;
		}
	}
}

void VandG_Corp::print() const
{
	for (int i = 0; i < all_employees.size(); i++)
	{
		cout << "Position: " << all_employees[i]->get_position() << endl;
		cout << "Full Name: " << all_employees[i]->get_name() << endl;
		cout << "ID: " << all_employees[i]->get_id() << endl;
		cout << "Salary: " << all_employees[i]->get_salary() << "lv." << endl;
		cout << "Experience: " << all_employees[i]->get_xp() << "years." << endl;
		cout << "//--------------------------------//" << endl;
	}
}

bool VandG_Corp::check_if_employee_exist(int id) 
{
	for (int i = 0; i < all_employees.size(); i++)
	{
		if (all_employees[i]->get_id() == id)return 1;
	}
	return 0;
}

Employee* VandG_Corp::get_employee(int id) const 
{
	for (int i = 0; i < all_employees.size(); i++)
	{
		if (all_employees[i]->get_id() == id)return all_employees[i];
	}
	return 0;
}

VandG_Corp::~VandG_Corp() 
{
	for (int i = 0; i < all_employees.size(); i++)
	{
		delete all_employees[i];
	}
}
