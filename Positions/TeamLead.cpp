#include "../task1/Positions/TeamLead.h"

TeamLead::TeamLead() :Employee("Unknown", 0, 0, 0) {}

TeamLead::TeamLead(string name, int id, int salary, int xp) : Employee(name, id, salary, xp) 
{
	set_position();
}

void TeamLead::set_position() 
{
	position = "TeamLead";
}

