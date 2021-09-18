#include "../task1/Positons/QA.h"

QA::QA() :Employee("Unknown", 0, 0, 0) {}

QA::QA(string name, int id, int salary, int xp) : Employee(name, id, salary, xp) 
{
	set_position();
}

void QA::set_position() 
{
	position = "QA";
	return;
}
