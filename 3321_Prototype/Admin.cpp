#include "Admin.h"
#include <iostream>

void Admin::AdminManageUser(int select)
{
  cout << "Enter (1) to update First name,\nEnter (2) to update Last name,\nEnter (3) to update Address info,\n"
    "Enter (4) to update Phone number,\nEnter (5) to update Email,\nEnter (6) to update ban status."
  cin >> select;
  
  switch(select)
  {
    case 1:
      setFName(input);
      break;
    case 2:
      setLName(input);
      break:
    case 3:
      setAddress(input);
      break;
    case 4:
      setPhone(input);
      break;
    case 5:
      setEmail(input);
      break;
    case 6:
      setBan(input);
      break;
    default:
      cout << "Please enter a valid selection." << endl;
  }
    
