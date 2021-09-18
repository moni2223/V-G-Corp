#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee 
{
private:
	string name;
	int id;
	int salary;
	int xp;
	void copyFrom(const Employee& other);
public:
	string position;//what position does the employee takes

	Employee(); //default constructor

	Employee(string name, int id, int salary, int xp); //four-args constructor
	
	Employee(const Employee& other); //copy

	Employee& operator=(const Employee& other);

	bool operator==(const Employee& other);

	virtual void set_position() = 0;

	string get_name() const;
	int get_id() const;
	int get_salary() const;
	int get_xp() const;
	string get_position() const;
	
	void print() const;
	
	virtual ~Employee() 
	{
		name = "";
		id = salary = xp = 0;
	}

																											   
	// moveTicket(<type> ticket,TicketState); vsichki mogat da go pravqt
	// void assignTicket(<type> ticket); vsichki mogat da go pravqt


};