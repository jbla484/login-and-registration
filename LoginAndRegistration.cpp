#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
    //Public member functions
public:
    //Blank contructor
    User() {

    }
    //Registration function call to add input into array
    void registering(string username, string password) {
        this->username = username;
        this->password = password;

        accounts.push_back(username);
        accounts.push_back(password);
        ++count; ++count;
    }
    //Login function call to check if account exists
    void login(string username, string password) {
        count = 0;
        while (count < accounts.size()) {
            if (username == accounts[count]) {
                ++count;
                if (password == accounts[count]) {
                    cout << "\nSuccessfully logged in!" << endl;
                    ++count;
                }
                else {
                    cout << "\nWrong credentials!" << endl;
                    ++count;
                }

            }
            else {
                cout << "No such username!" << endl;
                ++count;
                ++count;
            }
        }
    }
    //Private data members
private:
    string username;
    string password;
    vector<string> accounts{};
    int count = 0;
};

int main()
{
    string username, password;
    char response;
    User users;
    //Intro message
    cout << "Welcome to James' login and registration program!" << endl;
    cout << "Enter \"q\" to close the program." << endl << endl;
    //Looping until the user enters 'q'
    do {
        cout << "Login or Register? ( l / r ): " << endl;
        cin >> response;
        //Switch statement for login and registration choices
        switch (response) {
            //Login statement asks the user for their username and password and then 
            //calls the login function with the username and password parameters
        case 'l':
            cout << "\nEnter your username: " << endl;
            cin >> username;
            cout << "\nEnter your password: " << endl;
            cin >> password;
            users.login(username, password);
            cout << endl;
            break;
            //Registering statement asks the user to enter a desired username and password and then 
            //calls the registering function with the username and password parameters
        case 'r':
            cout << "\nEnter a username: " << endl;
            cin >> username;
            cout << "\nEnter a password: " << endl;
            cin >> password;
            users.registering(username, password);
            cout << "\nThanks for registering!" << endl << endl;
            break;
            //Anything else other than 'l' or 'r'
        default:
            cout << "\nWrong choice, try again." << endl << endl;
            break;
        }
    } while (response != 'q');
}
