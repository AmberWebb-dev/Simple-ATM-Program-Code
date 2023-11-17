//-----------------------------------------------------------------------------------------------
//Program name:  Program3.cpp
//Author:  Amber Webb
//Date:  11/02/2022
//Input:  requests information input from user
//Output:  displays output on the console
//Description:  This program defines a bank account as an ADT and implements the basic properties of a bank account.
//-----------------------------------------------------------------------------------------------

#include <stdio.h>
#include "BankAccount.hpp"
#include <iostream>

using namespace std;

int Bank::staticAccount;

//***********************************************************************************************


void Bank::SetData(string first, string last, int account, double balance, double interest){
    First = first;
    Last = last;
    AccNum = account;
    Balance = balance;
    Interest = interest;
}

//***********************************************************************************************

int Bank::getAccount(int account){
    if (AccNum == account){
        Bank::PrintData();
        return (1);
    }
    return (0);
}

//***********************************************************************************************

double Bank::getDeposit(float add) {
    Balance = Balance + add;
    return Balance;
}

//***********************************************************************************************

double Bank::getWithdrawl(float minus, double balance){
    Balance = balance;
    if (Balance < minus){
        cout << "\nInsufficient Funds!" << endl;
    }
    if (Balance > minus){
        Balance = Balance - minus;
    }
    return Balance;
}

//***********************************************************************************************

double Bank::getInterest(){
    double newInterest = (Interest / 100) * Balance;
    Balance = Balance - newInterest;
    return Balance;
}

//***********************************************************************************************

void Bank::PrintData()const{
    cout << "\n***********************************************************" << endl;
    cout << "\tCustomer Name: " << First << ' ' << Last << endl;
    cout << "\tAccount Number: " << AccNum << endl;
    cout << "\tBalance: $" << Balance << endl;
    cout << "\tInterest: " << Interest << "%" << endl;
    cout << "***********************************************************\n" << endl;

}

//***********************************************************************************************

Bank::Bank(string first, string last, int account, double balance, double interest){
    SetData(first, last, account, balance, interest);
}

//***********************************************************************************************

Bank::Bank(){
    First = "";
    Last = "";
    AccNum = 0;
    Balance = 0;
    Interest = 0;
}

//***********************************************************************************************
