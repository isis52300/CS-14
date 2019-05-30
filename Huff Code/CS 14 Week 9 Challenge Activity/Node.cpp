//
//  Node.cpp
//  CS 14 Week 9 Challenge Activity
//
//  Created by Isis Dumas on 5/28/19.
//  Copyright © 2019 Isis Dumas. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

#include "Node.h"



Node::Node() : data('~'), occurance(1), huff(""), left(nullptr), right(nullptr), parent(nullptr) {}
Node::Node(int o) : data('~'), occurance(o), huff(""), left(nullptr), right(nullptr), parent(nullptr) {}
Node::Node(char d) : data(d), occurance(1), huff(""), left(nullptr), right(nullptr), parent(nullptr) {}
Node::Node(char d, string h) : data(d), occurance(1), huff(h), left(nullptr), right(nullptr), parent(nullptr) {}

char Node::Data() { return data; }
int Node::Occurance() { return occurance; }
string Node::Huff() { return huff; }
Node* Node::Right() { return right; }
Node* Node::Left() { return left; }
Node* Node::Parent() {return parent; }

void Node::IncreaseOccurance() { ++occurance; }
void Node::ChangeHuff(string h) { huff = h; }
void Node::ChangeData(char d) { data = d; }
void Node::SetRight(Node* n) { right = n; }
void Node::SetLeft(Node* n) { left = n; }
void Node::SetParent(Node* n) { parent = n; }
void Node::SetHuff(string h) { huff = h; }
