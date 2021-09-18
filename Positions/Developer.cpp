#include "../task1/Positons/Developer.h"

Developer::Developer() :Employee("Unknown", 0, 0, 0) {}

Developer::Developer(string name, int id, int salary, int xp) : Employee(name, id, salary, xp) 
{
	set_position();
}

void Developer::set_position()
{
	position = "Developer";
	return;
}