//-----------------------------------------------------------------------------------------------
//Program name:  Program3.cpp
//Author:  Amber Webb
//Date:  11/02/2022
//Input:  requests information input from user
//Output:  displays output on the console
//Description:  This program defines a bank account as an ADT and implements the basic properties of a bank account.
//-----------------------------------------------------------------------------------------------

#include <iostream>
//#include "BankAccount.hpp"
#include "CheckingAccount.hpp"
#include <iomanip>

using namespace std;

int main() {
    Checking bank[20];
//    Bank bank[20];
    int Menu = 0, subMenu = 0;
    float interest = 0.0;
    double total = 0.0;
    int accountNumber = 100;
    int account;
    float deposit = 0.0, withdraw = 0.0;
    string first, last;
    int x = 0;

    do {
        
        cout << "/n-----------------------------------------------------" << endl;
        cout << "\tMenu" << endl;
        cout << "1---Add a Customer" << endl;
        cout << "2---View all Customers" << endl;
        cout << "3---Update Customer Information" << endl;
        cout << "4---Exit Menu" << endl;
        cout << "-----------------------------------------------------\n" << endl;

        cout << "Please Type the Number of your Selection and hit Enter: ";
        cin >> Menu;
        
        switch (Menu) {
                
            //Add customer
            case 1:
                // not allowing more entrys than the array allows
                if (x > 20) {
                    cout << "You have reached your limit in adding customers ;)" << endl;
                }
                
                //retrieving customer information from user
                cout << "Enter Customer Name (First Last): ";
                cin >> first >> last;;
                
                cout << "Enter interest as a percent: ";
                cin >> interest;
                
                cout << "Enter amount to deposit to open the account: $";
                cin >> total;
                
                // call setData
                bank[x].SetData(first, last, accountNumber, total, interest);
                
                //updating account number for new user
                accountNumber = accountNumber + 1;
                x++;
                
                break;
                
            //View customers
            case 2:
                
                for (int i = 0; i < x; i++){
                    //call printdata
                    cout << bank[i];
//                    bank[i].PrintData();
                }
                break;
                
            // update customers
            case 3:
                
                cout << "Please enter account number: ";
                cin >> account;
                for (int n = 0; n < x; n++){
                    int found = 0;
                    //call getaccount
                    found = bank[n].getAccount(account);
                    if (found){
                        do {
                            
                            cout << "\n-----------------------------------------------------" << endl;
                            cout << "\tMenu" << endl;
                            cout << "1---Make a Withdrawl" << endl;
                            cout << "2---Make a Deposit" << endl;
                            cout << "3---View Account" << endl;
                            cout << "4---Update with interest" << endl;
                            cout << "5---Exit Menu" << endl;
                            cout << "-----------------------------------------------------\n" << endl;
                            
                            cout << "Please make a selection: ";
                            cin >> subMenu;
                            
                            switch (subMenu) {
                                    
                                //make a withdraw
                                case 1:
                                    cout << "Enter amount to Withdraw: $";
                                    cin >> withdraw;
                                    //call getwithdrawl
//                                    bank[n].getWithdrawl(withdraw);
                                    bank[n].GetMin(total, withdraw);
                                    break;
                                    
                                //make a deposit
                                case 2:
                                    cout << "Enter amount to Deposit: $";
                                    cin >> deposit;
                                    //call getdeposit
                                    bank[n] = bank[n] + deposit;
//                                    bank[n].getDeposit(deposit);
                                    break;
                                    
                                //View account
                                case 3:
                                    //call printdata
                                    cout << bank[n];
//                                    bank[n].PrintData();
                                    break;
                                    
                                //update interest
                                case 4:
                                    // call getinterest
                                    bank[n].getInterest();
                                    break;
                                    
                                //exit sub menu
                                case 5:
                                    cout << "...Redirecting to main Menu" << endl;
                                    break;
                            }
                        } while (subMenu != 5);
                    }
                    if (!found){
                        cout << "Invalid customer Account Number!" << endl;
                    }
                }
                    break;
                
                // exit program
                case 4:
                cout << "Thank you!" << endl;
                    break;
                    
                };
        }while (Menu != 4);
    
    
    return 0;
}
