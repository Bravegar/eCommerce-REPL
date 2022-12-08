#include "Admin.h"
#include <iostream>
#include <string>
using namespace std;

void Admin::AdminManageUser(int select)
{
    Admin option;
    cout << "Enter (1) to update First name,\nEnter (2) to update Last name,\nEnter (3) to update Address info,\n"
        "Enter (4) to update Phone number,\nEnter (5) to update Email,\nEnter (6) to update ban status.";
    cin >> select;

    switch (select)
    {
    case 1:
        option.getFName(FName);
        break;
    case 2:
        option.getLName(LName);
        break;
    case 3:
        option.getAddress(address);
        break;
    case 4:
        option.getPhone(phone);
        break;
    case 5:
        option.getEmail(email);
        break;
    case 6:
        option.setBan();
        break;
    default:
        cout << "Please enter a valid selection." << endl;
    }
}

string Admin::getFName(string FName)
{
    return string();
}

string Admin::getLName(string LName)
{
    return string();
}

string Admin::getAddress(string address)
{
    return string();
}

string Admin::getPhone(int phone)
{
    return string();
}

string Admin::getEmail(string email)
{
    return string();
}

bool Admin::setBan()
{
    return false;
}
