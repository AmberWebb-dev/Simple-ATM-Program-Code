//-----------------------------------------------------------------------------------------------
//Program name:  Program3.cpp
//Author:  Amber Webb
//Date:  11/02/2022
//Input:  requests information input from user
//Output:  displays output on the console
//Description:  This program defines a bank account as an ADT and implements the basic properties of a bank account.
//-----------------------------------------------------------------------------------------------

#ifndef CheckingAccount_hpp
#define CheckingAccount_hpp

#include <stdio.h>
#include <iostream>
#include "BankAccount.hpp"

class Checking: public Bank{
    
    //overloaded operator used to call print
    friend std::ostream& operator<< (std::ostream&,  const Checking&);

public:
    //function to set bank account data
    //PRE: none
    //POST: all values are set accordingly including inherited data
    void SetCheck(std::string first, std::string last, int account, double balance, double interest);
     
    //function to check if the balance is under $5
    //PRE: balance and minus variables both hold values
    //POST: proper steps are takenn depending on the balance
    void GetMin(double& balance, float minus);
     
    //function to take away the service charge
    //PRE: the balance must be between $0 and $5
    //POST: balance is updated with the service charge removed
    void GetCharge(double& balance, float minus);
    
    //function to make a deposit into an account
    //PRE:
    //POST: the customers balance is updated
    Checking operator+(const float);
    
    //constructor with parameters
    //PRE: none
    //POST: setCheck is called to set values
    Checking(std::string first, std::string last, int account, double balance, double interest);
    
    //default constructor
    //PRE: none
    //POST: MinimumBalance = 5.00 and ServiceCharge = 1.00
    Checking();
    
private:
    double MinimumBalance;
    double ServiceCharge;
};

#endif /* CheckingAccount_hpp */
