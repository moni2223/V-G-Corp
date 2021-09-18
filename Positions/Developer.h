#pragma once
#include "../task1/Positons/Employee.h"

class Developer : public Employee
{
public:
	Developer();
	Developer(string name, int id, int salary, int xp);

	virtual void set_position() override;

	//void WriteCode(<type> ticket,string code);
	//void doCodeReview(<type> ticket);
	virtual ~Developer() {};
};