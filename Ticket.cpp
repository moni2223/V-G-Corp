#include "../task1/Ticket.h"

Ticket::Ticket() :id(0), description(""), profit(0), pullrequest({}),state(ToDo),
current(nullptr), creator(nullptr), last_time_of_change("") 
{
	condition = "ToDo";
}

Ticket::Ticket(int id, string description, int profit, PullRequest pullrequest,State state,
	Employee* current, Employee* creator, string last_time_of_change) :
	id(id), description(description), profit(profit), pullrequest(pullrequest), state(state), current(current), creator(creator)
{
	set_last_time();
}

Ticket::Ticket(int id, string description, int profit, State state,Employee* current
	,Employee* creator, string last_time_of_change) :
	id(id), description(description), profit(profit), pullrequest(),
	state(state), current(current), creator(creator) 
{
	set_last_time();
}


void Ticket::set_last_time() 
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	string str(buffer);

	last_time_of_change = str;
}

string Ticket::get_time() const
{
	return last_time_of_change;
}

int Ticket::get_id() const 
{
	return id;
}

bool Ticket::get_current()const 
{
	if (current == nullptr)
		return 0;
	
	else return 1;
}

string Ticket::get_state()const 
{
	return condition;
}
State Ticket::get_State() const 
{
	return state;
}

Employee* Ticket::get_current_full_info() const 
{
	return current;
}

PullRequest Ticket::get_pullrequest() const 
{
	return pullrequest;
}

int Ticket::get_profit() const 
{
	return profit;
}

Ticket::Ticket(const Ticket& rhs) 
{
	copyFrom(rhs);
}

Ticket& Ticket::operator=(const Ticket& rhs) 
{
	if (this != &rhs) copyFrom(rhs); 

	return *this;
}

void Ticket::copyFrom(const Ticket& rhs) 
{
	id = rhs.id;
	description = rhs.description;
	profit = rhs.profit;
	pullrequest = rhs.pullrequest;
	condition = rhs.condition;
	current = rhs.current;
	creator = rhs.creator;
	last_time_of_change = rhs.last_time_of_change;
}

void Ticket::set_description(string description) 
{
	this->description = description;
}

void Ticket::set_creator(Employee* creator) 
{
	this->creator = creator;
}

void Ticket::set_id(int id) 
{
	this->id = id;
}

void Ticket::set_PullRequest(PullRequest pullrequest) 
{
	this->pullrequest = pullrequest;
}

void Ticket::set_current(Employee* current) 
{
	this->current = current;
}

void Ticket::set_state(string state) 
{
	condition = state;
	if (state == "InProgress")this->state = InProgress;
	if (state == "InReview")this->state = InReview;
	if (state == "InTesting")this->state = InTesting;
	if (state == "Done")this->state = Done;
}

void Ticket::set_profit(int profit) 
{
	this->profit = profit;
}

void Ticket::print() const
{
	cout << "Id of Ticket: " << id << endl;
	cout << "Description of ticket: " << description << endl;
	cout << "Profit: " << profit << endl;

	if (pullrequest.get_changetime() != "") {
		cout << "Pullrequest:";
		cout << "ID : " << pullrequest.get_employeeid() << ", ";
		cout << "Time: " << pullrequest.get_changetime() << ", ";
		cout << "Filename: " << pullrequest.get_filename() << endl;
	}

	cout << "State: " << condition << endl;
	if (current != nullptr)
	{
		cout << "Current employee:" << endl;
		cout << "{" << endl;
		current->print();
		cout << "}" << endl;
		cout << endl;
	}


	cout << "Creator: " << endl;
	cout << "{" << endl;
	creator->print();
	cout << "}" << endl;

	cout << "Time of last change: " << last_time_of_change << endl;
	cout << "//------------------------------//" << endl;
}