#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string userName, email, password;
    fstream file;

public:
    void login()
    {
        string search, spassword;
        cout << "-------------LOGIN---------------" << endl;
        cout << "Enter Your Username :";
        getline(cin, search);
        cout << "Enter Your Password :";
        getline(cin, spassword);
        file.open("loginData.txt", ios::in);
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
        while (!file.eof())
        {
            if (userName == search)
            {
                if (password == spassword)
                {
                    cout << "\n Account Login is Successful" << endl;
                    cout << "Username : " << userName << endl;
                    cout << "Password : " << password << endl;
                    cout << "Email ID : " << email << endl;
                }
                else
                {
                    cout << "Password is incorrect" << endl;
                }
            }
            getline(file, userName, '*');
            getline(file, email, '*');
            getline(file, password, '\n');
        }
        file.close();
    }
    void signUP()
    {
        cout << "Enter Your User Name : ";
        getline(cin, userName);
        cout << "Enter your email address :";
        getline(cin, email);
        cout << "Enter your password :";
        getline(cin, password);
        file.open("loginData.txt", ios ::out | ios ::app);
        file << userName << "*" << email << "*" << password << endl;
        file.close();
    }
    void forgotpassword()
    {
        string sname, semail;
        cout << "\n Enter Your Username :" << endl;
        getline(cin, sname);
        cout << "\nEnter Your Email Address :" << endl;
        getline(cin, semail);
        file.open("loginData.txt", ios::in);
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
        while (!file.eof())
        {
            if (sname == userName)
            {
                if (semail == email)
                {
                    cout << "Bravo ! Account Found ....!" << endl;
                    cout << "Your password is :: " << password << endl;
                }
                else
                {
                    cout << "Incorrect Email ID" << endl;
                }
            }
            else
            {
                cout << "Credentials Invalid ...." << endl;
            }
            getline(file, userName, '*');
            getline(file, email, '*');
            getline(file, password, '\n');
        }
        file.close();
    }
} obj;
int main()
{
    char choice;
    cout << "1-Login" << endl;
    cout << "2-Sign Up" << endl;
    cout << "3-Forgot Password" << endl;
    cout << "4-Exit" << endl;
    cout << "Enter your choice :: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUP();
        break;
    case '3':
        obj.forgotpassword();
        break;
    case '4':
        return 0;
        break;
    default:
        "Invalid Selection";
        break;
    }

    return 0;
}