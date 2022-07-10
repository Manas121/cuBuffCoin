#pragma once
#include<iostream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {
private:

    long long nonce; // An arbitrary number crucial in mining
    time_t timestamp; // Time when mined 
    vector <Transaction> transactions; //vector of transactions // moved from private
    string previousHash;
    string hash;

    
    
public:
    


    Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash);

    vector <Transaction> getTransactions();
    string getPreviousHash();
    string getHash();

    void setPreviousHash(string hash);
    string calculateHash();
    void mineBlock(unsigned int nDifficulty);
    string toString();
};

