#pragma once
#include "../task1/Positons/Ticket.h"

class Analyst : public Employee
{
public:
	//void editTicketDescription(<type> Ticket,string description);
	Analyst();
	Analyst(string name, int id, int salary, int xp);

	virtual void set_position() override;
	
	virtual ~Analyst() {};
};