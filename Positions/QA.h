#pragma once
#include "../task1/Positons/Employee.h"
#include "../Ticket.h"
#include "../VandGira.h"
#include "../VandG Corp.h"
#include <time.h>

class QA : public Employee
{
public:
	QA();

	QA(string name, int id, int salary, int xp);

	virtual void set_position() override;


	virtual ~QA() {};
};