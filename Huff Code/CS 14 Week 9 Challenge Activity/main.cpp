//
//  main.cpp
//  CS 14 Week 9 Challenge Activity
//
//  Created by Isis Dumas on 5/28/19.
//  Copyright © 2019 Isis Dumas. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Trie.h"

int main() {
    
    Table t;
    Trie T;
    string test = "", add, fileName;
    int option;
    
    do {
        cout << "Choose an option: " << endl
        << "1. Encode a text file" << endl
        << "2. Encode a input text" << endl;
        cin >> option;
        cin.clear();
        cin.ignore(256, '\n');
        cout << endl;
    } while (option != 1 && option != 2);
    
    if (option == 1) {
    
        cout << "Enter a file name: " << endl;
        getline(cin, fileName);
        
        ifstream fin(fileName);
        
        if (!fin) {
            cout << "Error opening " << fileName << endl;
            exit(1);
        }
        
        while (!fin.eof()) {
            getline(fin, add);
            test += add;
            test += '\n';
            fin.ignore();
        }
        
        fin.close();
        
    }
    else {
        cout << "Enter text: " << endl;
        getline(cin, test);
    }
    
    for (unsigned i = 0; i < test.size(); ++i) {
        t.AddToTable(test.at(i));
    }
    
    t.SortTable();
    
    T.MakeTrie(t);
    
    T.Encode();
    
    
    cout << endl;
    t.PrintEncoding(test);
    cout << endl;
    
    t.PrintTable();
    
    return 0;
}
