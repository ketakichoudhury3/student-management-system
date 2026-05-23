#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string customerName;
    float balance;

    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "\nAccount Created Successfully!\n";
    }

    void displayAccount()
    {
        cout << "\n--------------------------------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << customerName;
        cout << "\nBalance        : " << balance;
        cout << "\n--------------------------------\n";
    }
};

BankAccount accounts[100];
int totalAccounts = 0;

void createNewAccount()
{
    accounts[totalAccounts].createAccount();
    totalAccounts++;
}

void displayAllAccounts()
{
    if (totalAccounts == 0)
    {
        cout << "\nNo Accounts Available!\n";
        return;
    }

    for (int i = 0; i < totalAccounts; i++)
    {
        accounts[i].displayAccount();
    }
}

void depositMoney()
{
    int accNo;
    float amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accountNumber == accNo)
        {
            found = true;

            cout << "Enter Deposit Amount: ";
            cin >> amount;

            accounts[i].balance += amount;

            cout << "\nMoney Deposited Successfully!\n";
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void withdrawMoney()
{
    int accNo;
    float amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accountNumber == accNo)
        {
            found = true;

            cout << "Enter Withdraw Amount: ";
            cin >> amount;

            if (amount <= accounts[i].balance)
            {
                accounts[i].balance -= amount;

                cout << "\nMoney Withdrawn Successfully!\n";
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void saveDataToFile()
{
    ofstream file("bankdata.txt");

    for (int i = 0; i < totalAccounts; i++)
    {
        file << accounts[i].accountNumber << endl;
        file << accounts[i].customerName << endl;
        file << accounts[i].balance << endl;
    }

    file.close();

    cout << "\nData Saved Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n======================================";
        cout << "\n       BANK MANAGEMENT SYSTEM";
        cout << "\n======================================";

        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Save Data";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createNewAccount();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                displayAllAccounts();
                break;

            case 5:
                saveDataToFile();
                break;

            case 6:
                cout << "\nThank You for Using Bank Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}