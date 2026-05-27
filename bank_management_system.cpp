#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int choice;

    int accountNumber;
    char name[50];
    float balance;

    do
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "     BANK MANAGEMENT SYSTEM" << endl;
        cout << "==================================" << endl;

        cout << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display Accounts" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        if(choice == 1)
        {
            ofstream writeFile("bank.txt", ios::app);

            cout << endl;
            cout << "Enter Account Number : ";
            cin >> accountNumber;

            cout << "Enter Customer Name : ";
            cin >> name;

            cout << "Enter Balance : ";
            cin >> balance;

            writeFile << accountNumber << " "
                      << name << " "
                      << balance << endl;

            writeFile.close();

            cout << endl;
            cout << "Account Created Successfully." << endl;
        }

        else if(choice == 2)
        {
            ifstream readFile("bank.txt");

            cout << endl;
            cout << "===== CUSTOMER RECORDS =====" << endl;

            while(readFile >> accountNumber >> name >> balance)
            {
                cout << endl;
                cout << "Account Number : " << accountNumber << endl;
                cout << "Customer Name  : " << name << endl;
                cout << "Balance        : " << balance << endl;

                cout << "------------------------" << endl;
            }

            readFile.close();
        }

        else if(choice == 3)
        {
            ifstream readFile("bank.txt");
            ofstream tempFile("temp.txt");

            int accNo;
            float deposit;
            bool found = false;

            cout << endl;
            cout << "Enter Account Number : ";
            cin >> accNo;

            while(readFile >> accountNumber >> name >> balance)
            {
                if(accountNumber == accNo)
                {
                    cout << "Enter Deposit Amount : ";
                    cin >> deposit;

                    balance = balance + deposit;

                    found = true;

                    cout << endl;
                    cout << "Money Deposited Successfully." << endl;
                }

                tempFile << accountNumber << " "
                         << name << " "
                         << balance << endl;
            }

            readFile.close();
            tempFile.close();

            remove("bank.txt");
            rename("temp.txt", "bank.txt");

            if(found == false)
            {
                cout << endl;
                cout << "Account Not Found." << endl;
            }
        }

        else if(choice == 4)
        {
            ifstream readFile("bank.txt");
            ofstream tempFile("temp.txt");

            int accNo;
            float withdraw;
            bool found = false;

            cout << endl;
            cout << "Enter Account Number : ";
            cin >> accNo;

            while(readFile >> accountNumber >> name >> balance)
            {
                if(accountNumber == accNo)
                {
                    cout << "Enter Withdraw Amount : ";
                    cin >> withdraw;

                    if(withdraw <= balance)
                    {
                        balance = balance - withdraw;

                        cout << endl;
                        cout << "Money Withdrawn Successfully." << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Insufficient Balance." << endl;
                    }

                    found = true;
                }

                tempFile << accountNumber << " "
                         << name << " "
                         << balance << endl;
            }

            readFile.close();
            tempFile.close();

            remove("bank.txt");
            rename("temp.txt", "bank.txt");

            if(found == false)
            {
                cout << endl;
                cout << "Account Not Found." << endl;
            }
        }

        else if(choice == 5)
        {
            ifstream readFile("bank.txt");

            int accNo;
            bool found = false;

            cout << endl;
            cout << "Enter Account Number : ";
            cin >> accNo;

            while(readFile >> accountNumber >> name >> balance)
            {
                if(accountNumber == accNo)
                {
                    cout << endl;
                    cout << "Account Number : " << accountNumber << endl;
                    cout << "Customer Name  : " << name << endl;
                    cout << "Current Balance: " << balance << endl;

                    found = true;
                }
            }

            if(found == false)
            {
                cout << endl;
                cout << "Account Not Found." << endl;
            }

            readFile.close();
        }

        else if(choice == 6)
        {
            cout << endl;
            cout << "Program Closed Successfully." << endl;
        }

        else
        {
            cout << endl;
            cout << "Invalid Choice." << endl;
        }

    } while(choice != 6);

    return 0;
}
