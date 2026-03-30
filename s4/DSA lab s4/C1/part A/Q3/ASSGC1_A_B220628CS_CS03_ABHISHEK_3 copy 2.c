//problem
/*
3. You are responsible for designing a system to manage an emergency room (ER) using a priority
queue(max heap). Patients arrive at the ER and are characterized by their name, condition
severity (priority), and admit time(admitTime). The system needs to support the following
functions:
• main(): Repeatedly reads an input character from the menu list through the terminal and
execute menu driven operations accordingly.The Menu list is [‘a’,’t’,’c’,’d’,’u’,’p’,’e’].The pro-
gram ends on input ‘e’.
• admitPatient(priorityQ,name,priority,admitTime): Add a new patient to the ER with
their name, condition severity(priority), and admit time.
• treatNextPatient(priorityQ): Treat the next patient in the ER with high severity. If
multiple patients have the same severity, treat the one who was admitted first. Discharges
the patient after treatment.
• checkNextPatient(priorityQ): Print the details(space separated) of the next patient to be
treated without removing them from the priority queue.
• dischargePatient(priorityQ,name,admitTime): Discharge a specific patient from the
ER based on their name and admitTime.
• updateConditionSeverity(priorityQ,name,admitTime, newPriority): Update the con-
dition severity of a specific patient currently in the ER. This operation may change the pa-
tient’s position in the priority queue.
• printAllPatients(priorityQ): Print the details (space separated) of all patients (each pa-
tient in a new line) in the priority order. Consider admitting time for patients with the same
priority.
Input format:
• Each line of input contains two parts separated by a space; the first part is a character from the
menu list [’a’,’t’,’c’,’d’,’u’,’p’,’e’], and the second part contains parameters (space separated)
according to the menu option.
• Input ‘a’ followed by patient name (string), priority (int), and admit time (string) calls the
function admitPatient(priorityQ,name,priority,admitTime), which pushes a new node contain-
ing these patient details into the priority queue.
• Input ‘t’ calls the function treatNextPatient(priorityQ), which prints(space separated) and
removes the patient node with high priority.
• Input ‘c’ calls the function checkNextPatient(priorityQ), which prints(space separated) the
patient with high priority.
• Input ‘d’ followed by patient name and admit time calls the function dischargePatient(priorityQ,
name,admitTime), which removes the specific patient node from the priority queue.
• Input ‘u’ followed by patient name, admit time, and new priority calls the function update-
ConditionSeverity(priorityQ,name,admitTime, newPriority), which updates the priority of the
specific patient node.
• Input ‘p’ calls the function printAllPatients(priorityQ), which prints the details (space separ-
ated) of all the patients, each patient in a new line following the priority order.
• Input ‘e’ terminates the execution of the program.
Output format:
• Line contains string(patient name), integer(priority) and string(admit time).
Sample Input 1:
a John 3 08:30
a Mary 2 08:45
a Bob 4 09:00
p
t
p
d Mary 08:45
p
a Ramesh 5 11:30
u John 08:30 6
c
p
e
Sample Output 1 :
Bob 4 09:00
John 3 08:30
Mary 2 08:45
Bob 4 09:00
John 3 08:30
Mary 2 08:45
John 3 08:30
John 6 08:30
John 6 08:30
Ramesh 5 11:30
Sample Input 2:
a James 7 10:30
a Kumar 2 11:27
a Chitra 3 12:00
a Ahmed 9 14:00
a Kunal 7 18:00
p
t
d Kumar 11:27
p
c
u Chitra 12:00 9
d Kunal 18:00
p
e
5
Sample Output 2 :
Ahmed 9 14:00
James 7 10:30
Kunal 7 18:00
Chitra 3 12:00
Kumar 2 11:27
Ahmed 9 14:00
James 7 10:30
Kunal 7 18:00
Chitra 3 12:00
James 7 10:30
Chitra 9 12:00
James 7 10:30
*/
//solution
#include<stdio.h>
