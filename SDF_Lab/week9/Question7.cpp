#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string Username = "Jay";
    long password = 288;

    try
    {
        string user;
        int pass;

        cin >> user;
        cin >> pass;

        if (pass < 0)
            throw "invalid password";

        if (user == "")
            throw "empty username";

        if (user != Username || password != pass)
            throw "Incorrect username or password.";

        cout << "Login successfully";
    }
    catch (const char *s)
    {
        cout<<s;
    }
    return 0;
}