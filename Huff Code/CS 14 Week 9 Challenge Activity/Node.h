//
//  Node.h
//  CS 14 Week 9 Challenge Activity
//
//  Created by Isis Dumas on 5/28/19.
//  Copyright © 2019 Isis Dumas. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>

using namespace std;

class Node {
    
private:
    
    char data;
    int occurance;
    string huff;
    Node *left;
    Node *right;
    Node *parent;
    
public:
    
    Node();
    Node(char);
    Node(int);
    Node(char, string);
    
    char Data();
    int Occurance();
    string Huff();
    Node* Right();
    Node* Left();
    Node* Parent();
    
    void IncreaseOccurance();
    void ChangeHuff(string);
    void ChangeData(char);
    void SetRight(Node*);
    void SetLeft(Node*);
    void SetParent(Node*);
    void SetHuff(string);
    
};

#endif /* Node_h */
