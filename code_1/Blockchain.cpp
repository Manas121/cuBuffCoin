#include<iostream>
#include <sstream>
 
#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>
 
using namespace std;
 
Blockchain::Blockchain() {//constructor, creates a new block genesis and pushes the block into the pending list
   Transaction genesis("BFC","BFC",0);
   pending.push_back(genesis);
 
   Block gBlock(pending, time(nullptr), "In the beginning..");
   chain.push_back(gBlock);
 
   Transaction freeMoney("BFC","make money by mining",0);
   pending.push_back(freeMoney);
 
   difficulty = 4;
   miningReward = 10;
  
}
 
Block Blockchain::getLatestBlock() {//returns the last block in the list
   return chain.back();
}
 
void Blockchain::addTransaction(string src, string dst, int coins) {//creates a new transaction, src whos paying, dst who recieving, coins is how much they need to pay
   // TODO
 
   int balance = getBalanceOfAddress(src);
   if (balance>=coins) {
       Transaction newTransaction(src,dst,coins);
       pending.push_back(newTransaction);
   }
   else
   {
       cout << "insufficient balance!" << "\n";
   }
  
}
 
//incomplete
bool Blockchain::isChainValid() {//checks if the blockchain is valid
   // TODO
   for(size_t i = 1; i < chain.size(); i++) {//traversing through each loop
   //only checking hashcode-difficulty condition
       if (chain[i-1].calculateHash() != chain[i].getPreviousHash())//checks weather your previous hash is equal to 
       {
           return false;
       }
       for (unsigned int j = 0; j < difficulty; j++ ) {//goes throguh each transaction
           if (chain[i].getHash()[j] != '0')//hash value for however many difficluty values
           {
               return false;
           }
       }
   }
 
 
   return true;
}
 
bool Blockchain::minePendingTransactions(string minerAddress) {/
   // TODO
 
 
   Block newBlock (pending, time(nullptr), chain.back().getHash());
 
   newBlock.mineBlock(difficulty);
 
   pending.clear();
 
   chain.push_back(newBlock);
 
   Transaction newTransaction("BFC", minerAddress, miningReward);
 
   pending.push_back(newTransaction);
 
   return true;
 
}
 
int Blockchain::getBalanceOfAddress(string address) {//calcualting the balance of the address. Address is a person
   // TODO
 
   int balance  = 0;
 
  
   //to traverse each block
   for (size_t i = 0; i < chain.size(); i++) {//traverses through the block that are in the chain
 
       //to traverse each transaction within the block
       for (size_t j = 0; j < chain[i].getTransactions().size(); j++) {
 
           if (chain[i].getTransactions()[j].getSender() == address) {
              
               if (balance - chain[i].getTransactions()[j].getAmount() >= 0)//checking if they have enough money
               balance  = balance - chain[i].getTransactions()[j].getAmount();//if they do, subtract money from the current balance
               else
               balance = 0;
 
 
           }
 
           if (chain[i].getTransactions()[j].getReceiver() == address) {
 
 
               balance  = balance + chain[i].getTransactions()[j].getAmount();//add the balance
 
 
           }
 
 
       }  
 
 
   }
 
   return balance;
}
 
void Blockchain::prettyPrint() {//prints
   // TODO
   for(size_t i = 0; i < chain.size(); i++)
   {
       cout << chain[i].toString();
       for(size_t j = 0; j < chain[i].getTransactions().size(); j++) {
           cout << chain[i].getTransactions()[j].toString();
       }
   }
}
