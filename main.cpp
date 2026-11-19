#include <iostream>
#include <fstream>

#include "account.h"
#include "transaction.h"

using namespace std;

int main()
{
    account customer1(10001, "Samiha", 10000);
    account customer2(10002, "Tasnim", 5000);

    int choice;
    int transactionID = 100;

    do
    {
        cout << "\n====================================" << endl;
        cout << "       BANKING PAYMENT SYSTEM" << endl;
        cout << "====================================" << endl;

        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Transfer Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Transaction History" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
        // Deposit
        case 1:
        {
            double amount;

            cout << "\nEnter deposit amount: ";
            cin >> amount;

            customer1.deposit(amount);

            cout << "Current Balance: "
                 << customer1.getBalance() << endl;

            break;
        }

        // Withdraw
        case 2:
        {
            double amount;

            cout << "\nEnter withdrawal amount: ";
            cin >> amount;

            customer1.withdraw(amount);

            cout << "Current Balance: "
                 << customer1.getBalance() << endl;

            break;
        }

        // Transfer
        case 3:
        {
            double amount;

            cout << "\nEnter transfer amount: ";
            cin >> amount;

            Transaction t;

            transactionID++;

            t.setTransactionID(transactionID);
            t.setSender(customer1.getAccountNumber());
            t.setReceiver(customer2.getAccountNumber());
            t.setAmount(amount);

            customer1.transfer(customer2, amount, t);

            cout << "\nTransaction Details" << endl;
            cout << "Transaction ID: "
                 << t.getTransactionID() << endl;

            cout << "Sender: "
                 << t.getSender() << endl;

            cout << "Receiver: "
                 << t.getReceiver() << endl;

            cout << "Amount: "
                 << t.getAmount() << endl;

            cout << "Status: "
                 << t.getStatus() << endl;


            // Save transaction to file
            ofstream file("transaction.txt", ios::app);

            if(file.is_open())
            {
                file << "-----------------------------" << endl;
                file << "Transaction ID: "
                     << t.getTransactionID() << endl;

                file << "Sender: "
                     << t.getSender() << endl;

                file << "Receiver: "
                     << t.getReceiver() << endl;

                file << "Amount: "
                     << t.getAmount() << endl;

                file << "Status: "
                     << t.getStatus() << endl;

                file.close();
            }
            else
            {
                cout << "Unable to open transaction file." << endl;
            }

            break;
        }

        // Check balance
        case 4:
        {
            cout << "\n--- Customer 1 ---" << endl;
            customer1.checkBalance();

            cout << "\n--- Customer 2 ---" << endl;
            customer2.checkBalance();

            break;
        }

        // Transaction history
        case 5:
        {
            ifstream file("transaction.txt");

            if(file.is_open())
            {
                string line;

                cout << "\n===== Transaction History ====="
                     << endl;

                while(getline(file, line))
                {
                    cout << line << endl;
                }

                file.close();
            }
            else
            {
                cout << "No transaction history found."
                     << endl;
            }

            break;
        }

        // Exit
        case 6:
            cout << "\nThank you for using Banking Payment System!"
                 << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again."
                 << endl;
        }

    }
    while(choice != 6);

    return 0;
}
