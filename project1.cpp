#include<iostream>
#include<fstream>
#include<string>
#include<limits>
using namespace std;

class temp{
    string userName, Email, password;
    string searchName, searchEmail, searchPassword;
    fstream file;

    public:
    void signUp();
    void login();
    void forget();
}obj;

int main() {
    char choice;
    while(true){
        cout<<"\n1- Sign Up";
        cout<<"\n2- Login";
        cout<<"\n3- Forgot Password";
        cout<<"\n4- Exit";
        cin>>choice;

        switch(choice) {
            case '1': 
            obj.signUp();
            break;
            case '2': 
            obj.login();
            break;
            case '3': 
            obj.forget();
            break;
            case '4': 
            return 0;
            default:
            cout<<"Invalid selection.\n Please try again.";
        }
    }
}

void temp::signUp() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\nEnter Username: ";
    getline(cin, userName); 
    cout<<"\nEnter Email: ";
    getline(cin, Email);
    cout<<"\nEnter Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
    cout << "\nRegistration Succesful!\\n";
}

void temp::login() {
    cout << "\n------- LOGIN -------";
    cout << "\nEnter User Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchName);
    cout << "Enter Password: ";
    getline(cin, searchPassword);

    file.open("loginData.txt", ios::in); 
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
        if (userName == searchName && password == searchPassword) { 
            cout << "\nLogin Successful!\n";
            cout << "\nUsername: "<< userName <<endl;
            cout << "\nEmail: " << Email <<endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found) {
        cout << "\nInvalid Username or Password!";
    }
}

void temp::forget() {
    cout << "\nEnter your User Name: "; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchName);
    cout << "Enter your Email Address: "; 
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in); 
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*')) {
        if (userName == searchName && Email == searchEmail) {
            cout << "\nAccount Found!";
            cout << "\nYour Password is: " << password << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found) {
        cout << "\nRecord Not Found!";
    }
}