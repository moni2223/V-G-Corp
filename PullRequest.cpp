#include "PullRequest.h"

PullRequest::PullRequest() :employeeid(0), changetime(""), filename("") {}

PullRequest::PullRequest(int employeeid,string changetime,string filename,string code): employeeid(employeeid),
changetime(changetime), filename(filename) ,code(code)
{}

PullRequest::PullRequest(const PullRequest& rhs) 
{
	employee = rhs.employee;
	employeeid = rhs.employeeid;
	changetime = rhs.changetime;
	filename = rhs.filename;
	code = rhs.code;
}
PullRequest& PullRequest::operator=(const PullRequest& rhs) 
{
	if (this != &rhs) 
	{
		employeeid = rhs.employeeid;
		changetime = rhs.changetime;
		filename = rhs.filename;
	}
	return *this;
}

int PullRequest::get_employeeid() const 
{
	return employeeid;
}

string PullRequest::get_filename() const
{
	return filename;
}

string PullRequest::get_code() const 
{
	return code;
}

string PullRequest::get_changetime() const 
{
	return changetime;
}

Employee* PullRequest::get_employee() const 
{
	return employee;
}

void PullRequest::set_filename(string filename) 
{
	this->filename = filename;
	filename += ".txt";
	ofstream file(filename);

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return;
	}

	file << code << endl;

	file.close();


}

void PullRequest::set_employeeid(int employeeid) 
{
	this->employeeid = employeeid;
}

void PullRequest::set_code(string code)
{
	this->code = code;
}

void PullRequest::set_changetime(string changetime) 
{
	this->changetime = changetime;
}

void PullRequest::set_employee(Employee* employee) 
{
	this->employee = employee;
}

PullRequest::~PullRequest() 
{
	filename = code = "";
}