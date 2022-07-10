#include<iostream>
#include <sstream>

#include"Transaction.hpp"
using namespace std;

Transaction::Transaction(string _sender, string _receiver, int _amount) {
    sender = _sender; 
    receiver = _receiver; 
    amount = _amount;
}

string Transaction::getSender() {
    return sender;
}

string Transaction::getReceiver() {
    return receiver;
}

int Transaction::getAmount() {
    return amount;
}

string Transaction::toString() {
    stringstream ss;
    ss << "(" << sender <<", " << receiver << ", " << amount << ")";
    return ss.str();
}