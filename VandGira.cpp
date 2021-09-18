#include "VandGira.h"

VandGira::VandGira() :board({}) {}

void VandGira::add_Ticket(Employee* employee) 
{
	if (employee->get_position() == "Developer" || employee->get_position() == "Analyst")
	{
		cout << employee->get_name()<< " is not allowed to create ticket." << "He/She is "<< employee->get_position() <<"." << endl;
		return;
	}

	Ticket* ptrt=new Ticket;
	//ptrt = &t;
	ptrt->set_id(board.size());
	ptrt->set_creator(employee);

	board.push_back(ptrt);
}

void VandGira::editTicketDescription(Employee* current, Ticket* ticket, string description)
{
	if (current->get_position() == "Developer" || current->get_position() == "QA") 
	{
		cout <<current->get_name()<< " doesn't have the permission to change description. He/She is " <<current->get_position()
			<< "."<< endl;
		return;
	}

	ticket->set_description(description);
}

void VandGira::WriteCode(Ticket* ticket, PullRequest pullrequest, string code) 
{
	if (ticket->get_current_full_info()->get_position() == "Developer" || ticket->get_current_full_info()->get_position()=="TeamLead")
	{
			time_t my_time = time(NULL);
			string filename = to_string(ticket->get_id()) + "len" + to_string(code.length());

			string time = ctime(&my_time);

			pullrequest.set_employee(ticket->get_current_full_info());
			pullrequest.set_employeeid(ticket->get_current_full_info()->get_id());
			pullrequest.set_code(code);
			pullrequest.set_filename(filename);
			pullrequest.set_changetime(time);

			ticket->set_PullRequest(pullrequest);
			ticket->set_state("InProgress");
			ticket->set_last_time();
	}

	else 
		cout << ticket->get_current_full_info()->get_name() << " can't write code. He/She must be Developer" <<"."<< endl;
}

void VandGira::EstimateTicket(Employee* current, Ticket* ticket, int profit) 
{
	if (current->get_position() == "TeamLead")
	{
		ticket->set_profit(profit);
	}
	else cout << "Profit change was unsuccessfull.The employee must be TeamLead" << endl;
}

bool VandGira::doCodeReview(Employee* current, Ticket* ticket, string answer) 
{
	if (answer == "Yes")
	{
		if (ticket->get_state() == "InReview")
		{
			if ((ticket->get_current_full_info() == current) == 1)
			{
				ticket->set_current(nullptr);
				return 1;
			}
			else cout << "Error.This employee is already assigned to this ticket." << endl;
			return 0;
		}
		else cout << "Error. The ticket is not InReview." << endl;
		return 0;
	}
	else return 0;
}

void VandGira::moveTicket(Employee* current,Ticket* ticket,string state)
{
	if (current->get_position() == "QA") 
	{
		if (ticket->get_state() == "InTesting" && state=="Done") 
		{
			ticket->set_state("Done");
			ticket->set_current(nullptr);
		}
		
		if (ticket->get_state() == "InTesting" && state=="InProgress") 
		{
			ticket->set_state("InProgress");
			ticket->set_current(ticket->get_pullrequest().get_employee());
		}

		else cout << "This employee doesnt have permission to move this ticket" << endl;
	}


	if ((current->get_position() == "Developer" || current->get_position() == "TeamLead")
		&& (ticket->get_current_full_info() == current || ticket->get_current() == false))
	{
		if (state == "InReview" && ticket->get_state() == "InProgress")
		{
			if (ticket->get_pullrequest().get_employeeid() != 0)
			{
				ticket->set_state("InReview");
				ticket->set_current(nullptr);
			}
		}

		if (state == "InTesting" && ticket->get_state() == "InReview")
		{
			if (this->doCodeReview(current, ticket, "Yes") == 1)
			{
				ticket->set_current(nullptr);
				ticket->set_state("InTesting");
			}
			else cout << "Ticket movement failed" << endl;
		}

		if (state == "InProgress" && ticket->get_state() == "InReview") 
		{
			ticket->set_current(ticket->get_pullrequest().get_employee());
			ticket->set_state("InProgress");
		}
	}

	else
		cout << "Error occured.Probably the ticket is assigned to someone else." << endl;
}

Ticket* VandGira::getNextByState(State state) 
{
	int highest = 0;
	int id = 0;

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i]->get_profit() > highest && board[i]->get_current() == false && board[i]->get_State() == state)
		{
			highest = board[i]->get_profit();
			id = i;
		}
	}
	return get_ticket_by_id(id);
}

void VandGira::assignTicket(Employee* current) 
{
	if (current->get_position() == "QA")
	{
		if(getNextByState(InTesting) == nullptr) getNextByState(InTesting)->set_current(current);
		
		else cout << "There are no free tickets." << endl;
	}
	else if (current->get_position() == "Developer")
	{
		int highest = 0;
		int id = 0;

		for (int i = 0; i < board.size(); i++)
		{
			if (board[i]->get_profit() > highest && board[i]->get_current() == false)
			{
				highest = board[i]->get_profit();
				id = i;
			}
		}
		if(highest > 100) get_ticket_by_id(id)->set_current(current);

		else cout << "There are no free tickets." << endl;

	}
	else if (current->get_position() == "TeamLead")
	{
		int highest = 0;
		int id = 0;

		for (int i = 0; i < board.size(); i++)
		{
			if (board[i]->get_profit() > highest && board[i]->get_current() == false)
			{
				highest = board[i]->get_profit();
				id = i;
			}
		}
		if(highest > 100)get_ticket_by_id(id)->set_current(current);

		else cout << "There are no free tickets." << endl;

	}
}

Ticket* VandGira::get_ticket_by_id(int id) 
{
	return board[id];
}

void VandGira::print_all_tickets() const
{
	cout << "//------------------------------//" << endl;
	for (int i = 0; i < board.size(); i++)
	{
		board[i]->print();
	}
}

void VandGira::print_id_state() const 
{
	for (int i = 0; i < board.size(); i++)
	{
		cout << "Ticket id: " << board[i]->get_id() << endl;
		cout << "Ticket State: " << board[i]->get_state() << endl;
	}
}


void VandGira::filterByState(State state)
{
	std::sort(board.begin(), board.end());
}
int rankk(State state) 
{
	switch (state)
	{
	case State::ToDo:
		return 1;

	case State::InProgress:
		return 2;

	case State::InReview:
		return 3;

	case State::Done:
		return 4;
	
	default: 
		return 99;
	}
}
bool operator<(State left, State right)
{
	return rankk(left) < rankk(right);
}