#include "../task1/Positons/Employee.h"

Employee::Employee() : name("Unknown"), id(0), salary(0), xp(0) 
{}

Employee::Employee(string name, int id, int salary, int xp) : name(name), id(id), salary(salary), xp(xp) 
{}

Employee::Employee(const Employee& other) 
{
	copyFrom(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other) 
	{
		copyFrom(other);
	}
	return *this;
}

bool Employee::operator==(const Employee& other) 
{
	if (this->get_id() == other.get_id())return 0;
	else return 1;
}

void Employee::copyFrom(const Employee& other) 
{
	name = other.name;
	id = other.id;
	salary = other.salary;
	xp = other.xp;
}

string Employee::get_name() const 
{
	return name;
}


int Employee::get_id() const 
{
	return id;
}

int Employee::get_salary() const
{
	return salary;
}

int Employee::get_xp() const
{
	return xp;
}

string Employee::get_position() const 
{
	return position;
}

void Employee::print() const 
{
	cout << "Id: " << id << endl;
	cout << "Salary: " << salary << endl;
	cout << "XP: " << xp << endl;
	cout << "Position: " << position << endl;
}

