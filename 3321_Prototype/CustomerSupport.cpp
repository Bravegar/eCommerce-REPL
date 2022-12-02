#include "CustomerSupport.h"
#include<string>

bool issueResolved = false;
string inquiry;

string getInquiry()
{
	return inquiry;
}
void setInquiry(string user_input)
{
	/*The inquiry is a string so that the user can type in
	any problem they have*/
	inquiry = user_input;
}

void updateIssueStatus(int user_input)
{
	/*Assuming that the user_input can be 1 for true 
	and 0 for false, it's easier to have the issue 
	status to be a bool*/
	 issueResolved = user_input;
}
bool getIssueResolved()
{
	return issueResolved;
}
void setIssueResolved(int user_input)
{
	issueResolved = user_input;
}
