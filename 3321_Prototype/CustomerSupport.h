#pragma once
#include <string>
#include <iostream>
using namespace std;

class CustomerSupport {
private:
	bool issueResolved = false;
	string inquiry = "";
public:
	string getInquiry();
	void setInquiry(string user_input);
	bool getIssueResolved();
	void updateIssueStatus(int user_input);
};

