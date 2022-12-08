#pragma once
#include <string>
#include <vector>
using namespace std;

class Admin
{
    int adminID, phone, selection;
    string FName, LName, address, email;
    bool banStatus;

public:
    void AdminManageUser(int);
    string getFName (string FName);
    string getLName (string LName);
    string getAddress (string address);
    string getPhone (int phone);
    string getEmail (string email);
    bool setBan();
};
