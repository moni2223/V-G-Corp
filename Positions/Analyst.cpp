#include "../task1/Positons/Analyst.h"

Analyst::Analyst() :Employee("Unknown", 0, 0, 0) {}

Analyst::Analyst(string name, int id, int salary, int xp) : Employee(name, id, salary, xp) 
{
	set_position();
}

void Analyst::set_position() 
{
	position = "Analyst";
	return;
}
