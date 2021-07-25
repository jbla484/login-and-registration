#include <iostream>
#include <string>
using namespace std;

class User {
public:
    User() {

    }
    void resistering(string username, string password) {
        this->username = username;
        this->password = password;

        accounts[count] = username;
        ++count;
        accounts[count] = password;
        ++count;
    }
    void login(string username, string password) {
        count = 0;
        while (count <= 100) {
            if (username == accounts[count]) {
                ++count;
                if (password == accounts[count]) {
                    cout << "\nSuccessfully logged in!" << endl;
                    ++count;
                }
                else {
                    cout << "\nWrong credentials!" << endl << endl;
                    ++count;
                }
                
            }
            else {
                ++count;
                ++count;
            }
        }  
    }
private:
    string username;
    string password;
    string accounts[100];
    int count = 0;
};

int main()
{
    string username, password;
    char response;
    User users;

    cout << "Welcome to James' login and registration program!" << endl;
    cout << "Enter \"q\" to close the program." << endl << endl;

    do {
        cout << "Login or Register? ( l / r ): " << endl;
        cin >> response;

        switch (response) {
        case 'l':
            cout << "\nEnter your username: " << endl;
            cin >> username;
            cout << "\nEnter your password: " << endl;
            cin >> password;
            users.login(username, password);
            cout << endl;
            break;
        case 'r':
            cout << "\nEnter a username: " << endl;
            cin >> username;
            cout << "\nEnter a password: " << endl;
            cin >> password;
            users.resistering(username, password);
            cout << "\nThanks for registering!" << endl << endl;
            break;
        default:
            cout << "\nWrong choice, try again." << endl << endl;
            break;
        }
    } while (response != 'q');
}
