#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "../task1/Employee.h"
#include <time.h>
#include <fstream>

class PullRequest 
{
private:
	Employee* employee;
	int employeeid;
	string changetime;
	string filename;//ticketid_code
	string code;
public:
	PullRequest();
	PullRequest(int employeeid, string changetime, string filename,string code);

	PullRequest(const PullRequest& rhs);
	PullRequest& operator=(const PullRequest& rhs);

	int get_employeeid() const;
	string get_filename() const;
	string get_code() const;
	string get_changetime() const;
	Employee* get_employee() const;

	void set_filename(string filename);
	void set_changetime(string changetime);

	void set_employeeid(int employeeid);
	void set_code(string code);
	void set_employee(Employee* employee);
	
	~PullRequest();
};