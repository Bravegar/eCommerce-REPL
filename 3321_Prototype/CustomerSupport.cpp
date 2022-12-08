#include "CustomerSupport.h"
#include<string>
#include<iostream>
using namespace std;

string CustomerSupport::getInquiry()
{
	return inquiry;
}

void CustomerSupport::setInquiry(string user_input)
{
	/*The inquiry is a string so that the user can type in
	any problem they have*/
	inquiry = user_input;
}

void CustomerSupport::updateIssueStatus(int user_input)
{
	/*Assuming that the user_input can be 1 for true 
	and 0 for false, it's easier to have the issue 
	status to be a bool*/
	if (user_input == 1)
		issueResolved = true;
	else
		issueResolved = false;
}
bool CustomerSupport::getIssueResolved()
{
	return issueResolved;
}
