#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "../task1/Employee.h"
#include "../task1/PullRequest.h"
#include <time.h>

enum State { 
	ToDo = 0,
	InProgress = 1,
	InReview = 2,
	InTesting = 3,
	Done = 4 
};

class Ticket 
{
private:
	int id;
	string description;
	int profit;
	PullRequest pullrequest;
	string condition;
	Employee* current;//Developer
	Employee* creator; //QA or TeamLead
	string last_time_of_change;
	void copyFrom(const Ticket& rhs);
public:
	State state;

	Ticket();
	
	Ticket(int id, string description, int profit, PullRequest pullrequest,State state,
		Employee* current, Employee* creator, string last_time_of_change);
	
	Ticket(int id, string description, int profit, State state,Employee* current,
		Employee* creator, string last_time_of_change); //this constructor is when the ticket is not started (ToDo)
	
	Ticket(const Ticket& rhs);

	Ticket& operator=(const Ticket& rhs);

	string get_time() const;
	int get_id() const;
	bool get_current() const;
	Employee* get_current_full_info() const;
	string get_state() const;
	PullRequest get_pullrequest() const;
	int get_profit() const;
	State get_State() const;

	void set_description(string description);
	void set_creator(Employee* creator);
	void set_current(Employee* current);
	void set_id(int id);
	void set_PullRequest(PullRequest pullrequest);
	void set_last_time();
	void set_state(string state);
	void set_profit(int profit);

	void print() const;

};


