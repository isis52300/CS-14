//
//  Trie.h
//  CS 14 Week 9 Challenge Activity
//
//  Created by Isis Dumas on 5/28/19.
//  Copyright © 2019 Isis Dumas. All rights reserved.
//

#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "Node.h"

class Table {
    
private:
    
    list<Node*> table;
    
public:
    
    list<Node*> GetTable();
    void AddToTable(Node*);
    void AddToTable(char);
    void SortTable();
    void PrintTable();
    void RemoveDuplicateHuffs();
    void PrintEncoding(string);
    Node* FindCharacter(char);
    
};

class Trie {
    
private:
    
    Node *root;
    
public:
    
    void MakeTrie(Table&);
    void Encode();
    void Encode(Node*, string);
    
    
    
};

#endif /* Trie_h */
