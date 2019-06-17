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
    
   // vector<BKNode*> *ALL_NODES = new vector<BKNode*>(20);
    BKNode TREE[MAX_WORDS]; //TODO:- CONVER TO VECTOR<BKNODE*> LATER
    
    //HELPER VARIABLES
    int index_pointer;
    
public:
    
    BKTree(string root_word) {
        
        root = new BKNode(root_word);
        index_pointer = 0;
        
    }
    
    void add(BKNode*, BKNode*);
    
    
    //SETTERS
    
    //GETTERS
   // vector<BKNode&>* get_ALL_NODES() {return ALL_NODES;}
    
};

void BKTree::add(BKNode* root, BKNode* current) {
    
    if(root->get_word() == "") {
        root = current;
        return;
    }
    
    int edits = edit_distance(root->get_word(), current->get_word(), root->get_word().length(), current->get_word().length());
    
    
    if(TREE[root->get_next()[edits]].get_word() == "") {
        index_pointer++;
        TREE[index_pointer] = *current;
        root->get_next()[edits] = index_pointer;
        
    } else {
        add(&TREE[root->get_next()[edits]], current);
    }
    
}

//MARK:- NAIVE APPROACH WITH STRUCTS...
