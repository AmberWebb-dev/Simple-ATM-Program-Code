//-----------------------------------------------------------------------------------------------
//Program name:  Program3.cpp
//Author:  Amber Webb
//Date:  11/02/2022
//Input:  requests information input from user
//Output:  displays output on the console
//Description:  This program defines a bank account as an ADT and implements the basic properties of a bank account.
//-----------------------------------------------------------------------------------------------

#include "CheckingAccount.hpp"
#include "BankAccount.hpp"
#include <iostream>

using namespace std;

//***********************************************************************************************


void Checking::SetCheck(string first, string last, int account, double balance, double interest){
    MinimumBalance = 5.00;
    ServiceCharge = 1.00;
    SetData(first, last, account, balance, interest);
    
}

//**********************************************************************************************

void Checking::GetMin(double& balance, float minus){
    if((balance - minus) <= MinimumBalance && balance > 0){
        balance = balance - minus;
        GetCharge(balance, minus);
    }else {
        Bank::getWithdrawl(minus, balance);
    }
}

//***********************************************************************************************

void Checking::GetCharge(double& balance, float minus){
    cout << "\nNOTICE: Balance has fallen below $5, a service charge of $1 has been taken from your remaining funds!" << endl;
    balance = balance - ServiceCharge;
    Bank::getWithdrawl(minus, balance);
}

//***********************************************************************************************

ostream& operator<< (ostream& out, const Checking& chkAcc){
    chkAcc.Bank::PrintData();
    return out;
}

//***********************************************************************************************

Checking Checking::operator+(const float add){
    Checking chk = *this;
    chk.getDeposit(add);
    return chk;
}

//***********************************************************************************************

Checking::Checking(string first, string last, int account, double balance, double interest){
    SetCheck(first, last, account, balance, interest);
}

//***********************************************************************************************

Checking::Checking(){
    MinimumBalance = 5.00;
    ServiceCharge = 1.00;
}

//***********************************************************************************************
