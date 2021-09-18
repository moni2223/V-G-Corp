#pragma once
#include "../task1/VandG Corp.h"
#include "../task1/PullRequest.h"
#include <algorithm> 

class VandGira
{
private:
	vector <Ticket*> board;
public:

	VandGira();
	
	void add_Ticket(Employee* employee);//add Empty Ticket (only QA && TeamLead)
    void editTicketDescription(Employee* current, Ticket* ticket, string description);//edit Description (only Analyst && TeamLead)
	void moveTicket(Employee* current, Ticket* ticket,string state);//QA,TeamLead,Developer
	void assignTicket(Employee* current);//Everyone

	void WriteCode(Ticket* ticket,PullRequest pullrequest, string code);//Developer,TeamLead
	bool doCodeReview(Employee* current, Ticket* ticket, string answer);//Developer,TeamLead

	void EstimateTicket(Employee* current, Ticket* ticket, int profit);//TeamLead

	Ticket* getNextByState(State state);
	void filterByState(State state);


	Ticket* get_ticket_by_id(int id);

	void print_all_tickets() const;

	void print_id_state() const;
};