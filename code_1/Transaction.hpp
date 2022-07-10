#pragma once
#include<iostream>
using namespace std;

class Transaction {
private:
    string sender;
    string receiver;
    int amount;

public:
    Transaction(string _sender, string _receiver, int amount);

    string getSender();
    string getReceiver();
    int getAmount();

    string toString();
};