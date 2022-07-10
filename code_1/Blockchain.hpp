#pragma once
#include<iostream>
#include "Block.hpp"
#include "Transaction.hpp"
 
#include <vector>
 
using namespace std;
 
class Blockchain {
   private:
       unsigned int difficulty;
       vector<Block> chain;
       vector<Transaction> pending;
       int miningReward;
 
   public:
      Blockchain();
      void addTransaction(string src, string dst, int coins);
      bool isChainValid();
      bool minePendingTransactions(string minerAddress);
      int getBalanceOfAddress(string address);
      void prettyPrint();
 
   private:
       Block getLatestBlock();
};
