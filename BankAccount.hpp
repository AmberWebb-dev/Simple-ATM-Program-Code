//-----------------------------------------------------------------------------------------------
//Program name:  Program3.cpp
//Author:  Amber Webb
//Date:  11/02/2022
//Input:  requests information input from user
//Output:  displays output on the console
//Description:  This program defines a bank account as an ADT and implements the basic properties of a bank account.
//-----------------------------------------------------------------------------------------------

#ifndef bankAccount_h
#define bankAccount_h
#include <iostream>

class Bank{
public:
    
    //function to set bank account data
    //PRE: none
    //POST: First = first, Last = last, AccNum = account, Interest = interest, Balance = balance
    void SetData(std::string first, std::string last, int account, double balance, double interest);
    
    //function to retrieve accunt attached to an account number
    //PRE: account variable is filled
    //POST: checks for the Account number that matches user input and prints customer if customer is found
    int getAccount(int);
   
    //function to make a deposit into an account
    //PRE: variables add and Balance hold a value
    //POST: Balance is returned after adding add to the total
    double getDeposit(float);
    
    //function to withdraw from an account, includes balance error checking (cannot withdraw more than is in the account).
    //PRE: minus variable holds value as well as balance
    //POST: Balance is returned with its new value
    double getWithdrawl(float, double);
    
    //function to update the balance with its interest
    //PRE: variable interest and balance must have a value
    //POST: Balance is updated with the new value that takes out the interest
    double getInterest();
    
    //function to print all customer data
    //PRE: none
    //POST: all data is output to console
    void PrintData() const;
    
    //constructor with parameters
    //PRE: none
    //POST: First = first, Last = last, AccNum = account, Interest = interest, Balance = balance
    Bank(std::string first, std::string last, int account, double balance, double interest);
    
    //default constructor
    //PRE: none
    //POST: First = "", Last = "", AccNum = 0, Balance = 0, Interest = 0
    Bank();
    
    //private member variables
private:
    std::string First, Last;
    int AccNum;
    double Balance;
    double Interest;
    static int staticAccount;
    
};

#endif /* bankAccount_h */
