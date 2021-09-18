#pragma once
#include "../task1/Positons/Employee.h"
#include "../VandGira.h"
#include "../VandG Corp.h"

class TeamLead : public Employee
{
public:
	TeamLead();
	TeamLead(string name, int id, int salary, int xp);

	virtual void set_position() override;

	virtual ~TeamLead() {};
};