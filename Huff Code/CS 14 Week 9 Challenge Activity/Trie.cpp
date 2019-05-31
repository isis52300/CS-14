//
//  Trie.cpp
//  CS 14 Week 9 Challenge Activity
//
//  Created by Isis Dumas on 5/28/19.
//  Copyright © 2019 Isis Dumas. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#include "Node.h"
#include "Trie.h"

list<Node*> Table::GetTable() { return table; }

void Table::AddToTable(Node* node) {
    for (list<Node*>::iterator it = table.begin(); it != table.end(); ++it) {
        if ((*it)->Data() == node->Data()) {
            (*it)->IncreaseOccurance();
            return;
        }
    }
    table.push_back(node);
}

void Table::AddToTable(char d) {
    
    Node *node = new Node(d);
    AddToTable(node);
    
}

void Table::SortTable() {
    
    for (list<Node*>::iterator it = table.begin(); it != table.end(); ++it) {
        for (list<Node*>::iterator jit = table.begin(); jit != table.end(); ++jit) {
            if ((*jit)->Occurance() > (*it)->Occurance()) {
                swap(*it, *jit);
            }
        }
    }
    
    
}


void Trie::MakeTrie(Table &table) {
    
    list<Node*> t = table.GetTable();
    list<Node*> pointers, pointers2;
    Node *left, *right, *parent;
    
    
    while (t.size() > 1) {
        
        left = t.front(); t.pop_front();
        right = t.front(); t.pop_front();
        
        parent = new Node(left->Occurance() + right->Occurance());
        left->SetParent(parent); right->SetParent(parent);
        parent->SetLeft(left); parent->SetRight(right);
        
        pointers.push_back(parent);
        
    }
    
    if (!t.empty()) {
        pointers.push_back(t.front()); t.pop_front();
    }
    
    while (pointers.size() > 1) {
        while (pointers.size() > 1) {
            
            right = pointers.back(); pointers.pop_back();
            left = pointers.back(); pointers.pop_back();
            
            parent = new Node(left->Occurance() + right->Occurance());
            left->SetParent(parent); right->SetParent(parent);
            parent->SetLeft(left); parent->SetRight(right);
            
            pointers2.push_back(parent);
            
        }
        
        if (!pointers.empty()) {
            pointers2.push_back(pointers.back());
        }
        
        pointers = pointers2;
        
        pointers2.resize(0);
        
    }
    
    root = pointers.front(); pointers.pop_front();
}

void Trie::Encode() {
    
    Encode(root, "");
    
}

void Trie::Encode(Node* curr, string huff) {
    
    if (curr == nullptr) {
        if (huff.size() > 0) { huff.resize(huff.size() - 1); }
        return;
    }
    
    Encode(curr->Left(), huff + "0");
    curr->SetHuff(huff);
    Encode(curr->Right(), huff + "1");
    
}

void Table::PrintEncoding(string s) {
    
    Node *curr;
    
    for (unsigned i = 0; i < s.size(); ++i) {
        
        curr = FindCharacter(s.at(i));
        cout << curr->Huff() << ' ';
        
        if (curr->Data() == '\n') {
            cout << endl << endl;
        }
        
    }
    
    
    
}

Node* Table::FindCharacter(char c) {
    
    for (list<Node*>::iterator it = table.begin(); it != table.end(); ++it) {
        if ((*it)->Data() == c) {
            return *it;
        }
    }
    
    return nullptr;
}


void Table::PrintTable() {
    
    for (list<Node*>::iterator it = table.begin(); it != table.end(); ++it) {
        cout << (*it)->Data() << ' ' << (*it)->Huff() << endl;
    }
}

