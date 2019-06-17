//
//  BKTree.cpp
//  Auto Correct
//
//  Created by Harshavardhan K on 17/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//
#include <iostream>
#include "Edit_Distance.hpp"
using namespace std;

#define MAX_LEN_WORD 10
#define MAX_WORDS 100
#define TOLERANCE 2

class BKNode {
    
    string word;
    
    int* next;
    
public:
    
    BKNode(string word) {
        
        this->word = word;
        next = new int[2 * MAX_LEN_WORD];
        
        for(int i = 0; i < MAX_LEN_WORD; i++) {
            next[i] = 0;
        }
    }
    
    BKNode() {std::cout << "Empty initialization of BKNode\n";}
    
    string get_word() {return word;}
    int* get_next() {return next;}
};

class BKTree {
    
    BKNode* root;
    
    vector<BKNode*> *ALL_NODES;
    
public:
    
    void add();
    
};

//MARK:- NAIVE APPROACH WITH STRUCTS...
