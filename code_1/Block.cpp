#include<iostream>
#include <sstream>
 
 
#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"
 
using namespace std;
 
Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {//constructor
   nonce = -1;
   transactions = _transactions;
   previousHash = _previousHash;
   timestamp = _timestamp;
   hash = calculateHash();
}


vector <Transaction> Block::getTransactions() {//returning the transactions

return transactions;

}


string Block::getPreviousHash() {//return the previous hash

return previousHash;

}

string Block::getHash() {

return hash;

}



 
void Block::setPreviousHash(string _previousHash) {//set previous hash- sets the value of previous hash
   // TODO
 
previousHash = _previousHash;
 
 
}
 
string Block::calculateHash() {//calcuautes the value using sha256 function
   // TODO
 
string _block = toString();
 
return sha256(_block);
 
 
}
 
void Block::mineBlock(unsigned int difficulty) {//keep calculating the hash value until the however many digits are equal to zero, and \however many depends on the difficulty
   // TODO
 
   bool condition  = false;//
 
   while (condition == false) {
 
       hash = calculateHash();
 
       bool internalCondition = true;
 
       for (int i = 0; i < difficulty; i++) {
 
           if(hash[i]!= '0')
               internalCondition = false;
       }
 
       
       if (internalCondition == true)
           condition = true;
        else
        nonce++;//every time you run through the loop, you increase the nonce value goes down.
   }
 
 
}
 
string Block::toString() {//takes eveything in the block and converts everything into string and the transaction within each block.
   // TODO
 
   stringstream ss;
   ss << "\n" << "Nonce: " << nonce  << "\n" <<"Timestamp " << timestamp << "\n" << "Prevhash " << previousHash << "\n" << "Hash: " << hash << "\n";
 
   for (int i = 0; i < transactions.size(); i++) {
 
   ss << transactions[i].toString();
 
   ss << "\n";
 
   }
 
   return ss.str();
 
  
}
