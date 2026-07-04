/*Write a C++ program for the following description. [CO2, 10 Marks]
In a secure building, access is granted only if a user possesses both a valid ID and biometric
authentication. Additionally, group access is allowed only if all users satisfy access conditions.Write a
C++ program to implement the above access control system using operator overloading.
1. Create a class Access with:
 hasID (bool)
 hasBiometric (bool)
Implement a parameterized constructor to initialize the access credentials.
Implement a member function:
 bool isAccessGranted() const
 Returns true if both access conditions are satisfied for a user.
Overload logical AND operator (&&) to check group access. The operator should return a new
Access object. Group access is granted only if both objects have valid access
In the main() function:
 Accept access details for two users
 Display the individual access status of each user
 Display the group access status using the overloaded && operator
Sample input :
User 1: Has ID : 1
Has Biometric: 1
User 2: Has ID : 1
Has Biometric: 0
Sample output :
User 1: Access Granted
User 2: Access Denied
Group Access Check: Access Denied*/

#include<iostream>
using namespace std;
class Access{
    bool id;
    bool bio;
    public :
    Access(){}
    Access(int i , int b)
    {
        if(i==1)
        id=true;
        else
        id=false;

        if(b==1)
        bio=true;
        else
        bio=false;
    }

    bool isAccessGranted() const
    {
        if(id&&bio)
        {
            return true;
        }
        return false;
    }

    Access operator&&(const Access &other) const
    {
        bool groupGranted =
            this->isAccessGranted() && other.isAccessGranted();

        // return a new Access object
        return Access(groupGranted, groupGranted);
    }
    
    bool operator&&(const Access &obj)
    {
        if(id==obj.id && bio==obj.bio)
        return true;

        return false;
    }

};
int main()
{
    int n;
    cout<<"Enter number of the user : ";
    cin>>n;
     
    Access user[n];
    for(int i=0;i<n;i++)
    {
        int id,bio;
        cout<<"User "<<i+1<<endl;
        cout<<"ID : ";
        cin >> id;
        cout<<"Biometrix : ";
        cin >>bio;

        user[i]= Access(id,bio);
    }
    bool group=false;
    for(int i=0;i<n;i++)
    {
        if(user[i].isAccessGranted())
        {
            cout<<"User "<<i+1<<" : Access Granted ."<<endl;
        }
        else{
            group=true;
            cout<<"User "<<i+1<<" : Access Denied ."<<endl;
        }
    }
    if(group)
    {
        cout<<"Group Access Check : Access Denied .";
    }else{
        cout<<"Group Access Check : Access Granted .";
    }

    
    return 0;
}
/*#include <iostream>
using namespace std;

class Access
{
    bool hasID;
    bool hasBiometric;

public:
    Access()
    {
        hasID = false;
        hasBiometric = false;
    }

    Access(bool id, bool bio)
    {
        hasID = id;
        hasBiometric = bio;
    }

    bool isAccessGranted() const
    {
        return hasID && hasBiometric;
    }

    // overload &&
    Access operator&&(const Access &other) const
    {
        bool groupGranted =
            this->isAccessGranted() && other.isAccessGranted();

        // return a new Access object
        return Access(groupGranted, groupGranted);
    }
};

int main()
{
    int id, bio;

    cout << "User 1: Has ID : ";
    cin >> id;
    cout << "Has Biometric : ";
    cin >> bio;

    Access user1(id, bio);

    cout << "User 2: Has ID : ";
    cin >> id;
    cout << "Has Biometric : ";
    cin >> bio;

    Access user2(id, bio);

    // Individual access
    if (user1.isAccessGranted())
        cout << "User 1: Access Granted" << endl;
    else
        cout << "User 1: Access Denied" << endl;

    if (user2.isAccessGranted())
        cout << "User 2: Access Granted" << endl;
    else
        cout << "User 2: Access Denied" << endl;

    // Group access using overloaded &&
    Access group = user1 && user2;

    if (group.isAccessGranted())
        cout << "Group Access Check: Access Granted" << endl;
    else
        cout << "Group Access Check: Access Denied" << endl;

    return 0;
}*/