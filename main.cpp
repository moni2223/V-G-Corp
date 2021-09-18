#include "Developer.h"
#include "Analyst.h"
#include "QA.h"
#include "TeamLead.h"

int main()
{
    VandG_Corp v(25000);
    VandGira vg;
    PullRequest p;

    Employee** arr = new Employee*[8];

    arr[0] = new Developer("Ivan Ivanov", 68, 3000, 3); //OK
    arr[1] = new Developer("Simeon Rangelov", 27, 1500, 1); //OK
    arr[2] = new Analyst("Petur Stoqnov", 33, 1000, 1); //OK
    arr[3] = new Analyst("Georgi Sabev", 44, 1500, 2);
    arr[4] = new QA("John Wick", 99, 1300, 2); //OK
    arr[5] = new QA("QA Ivanov", 34, 1800, 3);//OK
    arr[6] = new TeamLead("Shef Shefov", 1, 5000, 8); //OK
    arr[7] = new TeamLead("Petur Jekov", 2, 7500, 10);//OK,but budget is going low.

    for (int i = 0; i < 8; i++)
        v.add_employee(arr[i]); //OK

    vg.add_Ticket(arr[0]);//Error, the employee is Developer.
    vg.add_Ticket(arr[4]);//OK
    vg.add_Ticket(arr[5]);//OK
    vg.add_Ticket(arr[6]);//OK
    vg.add_Ticket(arr[7]);//OK

    vg.EstimateTicket(arr[6], vg.get_ticket_by_id(0), 15000);//OK
    vg.EstimateTicket(arr[7], vg.get_ticket_by_id(1), 25320);//OK
    vg.EstimateTicket(arr[1], vg.get_ticket_by_id(2), 33000);//Error, the employee is not TeamLead
    vg.EstimateTicket(arr[7], vg.get_ticket_by_id(2), 33000);//OK
    vg.EstimateTicket(arr[7], vg.get_ticket_by_id(3), 39000);//OK

    vg.editTicketDescription(arr[0], vg.get_ticket_by_id(0), "Problem in the DB of the website."); //Error, (Developer)
    vg.editTicketDescription(arr[2], vg.get_ticket_by_id(0), "Problem with the route of the registration page."); //OK (QA)
    vg.editTicketDescription(arr[3], vg.get_ticket_by_id(1), "Problem in the DB of the website."); //OK (QA)
    vg.editTicketDescription(arr[3], vg.get_ticket_by_id(2), "Problem with main page."); //OK (QA)
    vg.editTicketDescription(arr[7], vg.get_ticket_by_id(3), "Problem with buttons"); //OK (TeamLead)

    vg.assignTicket(arr[0]);//OK (Developer)
    vg.assignTicket(arr[1]);//OK (Developer)
    vg.assignTicket(arr[6]);//OK (TeamLead)
    vg.assignTicket(arr[7]);//OK (TeamLead)
    vg.assignTicket(arr[0]);//No free tickets.

    //WriteCode (from ToDo to InProgess) only Developer and TeamLead
    vg.WriteCode(vg.get_ticket_by_id(0), p,"<html> \n <body>\n <h1>My first PHP page< / h1>  \n < / body>");//OK
    vg.WriteCode(vg.get_ticket_by_id(0), p, "YEEES");//OK
    vg.WriteCode(vg.get_ticket_by_id(1), p, "<?php echo 'Hello World!';? > ");//OK
    vg.WriteCode(vg.get_ticket_by_id(2), p, "console.log('Hi')");//OK
    vg.WriteCode(vg.get_ticket_by_id(3), p, "cout<<123<<endl;");//OK
  
    vg.moveTicket(arr[0], vg.get_ticket_by_id(0), "InReview");//Error,this is not the current developer for this ticket.
    vg.moveTicket(arr[7], vg.get_ticket_by_id(0), "InReview");//OK
    vg.moveTicket(arr[0], vg.get_ticket_by_id(3), "InReview");//OK
    vg.moveTicket(arr[1], vg.get_ticket_by_id(1), "InReview");//Error,this is not the current developer for this ticket.
    vg.moveTicket(arr[1], vg.get_ticket_by_id(2), "InReview");//OK
    vg.moveTicket(arr[6], vg.get_ticket_by_id(1), "InReview");//OK

    vg.assignTicket(arr[1]);//OK (Developer)
    vg.assignTicket(arr[0]);//OK (Developer)
    vg.assignTicket(arr[7]);//OK (TeamLead)
    vg.assignTicket(arr[6]);//OK (TeamLead)

    vg.moveTicket(arr[6], vg.get_ticket_by_id(0), "InTesting");//OK
    vg.moveTicket(arr[7], vg.get_ticket_by_id(2), "InTesting");//Error,this is not the current developer for this ticket.
    vg.moveTicket(arr[1], vg.get_ticket_by_id(3), "InTesting");//OK
    vg.moveTicket(arr[0], vg.get_ticket_by_id(2), "InProgress");//OK
    vg.moveTicket(arr[7], vg.get_ticket_by_id(0), "ToDo");//From InReview to ToDo is impossible.
    
    vg.assignTicket(arr[5]);//OK (QA)
    vg.assignTicket(arr[7]);//OK (TeamLead)
    vg.assignTicket(arr[6]);//OK (TeamLead)
    vg.assignTicket(arr[4]);//OK (QA)

    vg.moveTicket(arr[5], vg.get_ticket_by_id(0), "InProgress");//OK
    vg.moveTicket(arr[4], vg.get_ticket_by_id(3), "Done");//OK

    vg.print_id_state();

    //vg.print_all_tickets(); CAN PRINT ALL TICKETS WITH THE FULL INFORMATION
}



/*
after line [31-33]
ticket[0], ticket[1], ticket[2], ticket[3]


after line [35-37] 
ticket[0].profit = 15000
ticket[1].profit = 25320
ticket[2].profit = 33000
ticket[3].profit = 39000

after line [39-41]
ticket[0].description = Problem with the route of the registration page.
ticket[1].description = Problem in the DB of the website.
ticket[2].description = Problem with main page.
ticket[3].description = Problem with buttons.

till here all tickets.state = ToDo

after line [54-59]
ticket[0].state=InProgress;
ticket[1].state=InProgress;
ticket[2].state=InProgress;
ticket[3].state=InProgress;

after line [61-65]
ticket[0].state=InReview;
ticket[1].state=InProgress;
ticket[2].state=InReview;
ticket[3].state=InReview;

after line [73-77]
ticket[0].state=InTesting;
ticket[1].state=InReview;
ticket[2].state=InProgress;
ticket[3].state=InTesting;

after line [84-85]
ticket[0].state=InProgress;
ticket[1].state=InReview;
ticket[2].state=InProgress;
ticket[3].state=Done;
*/