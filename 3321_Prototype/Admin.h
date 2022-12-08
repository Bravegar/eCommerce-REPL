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
};
