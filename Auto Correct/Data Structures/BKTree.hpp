//
//  BKTree.cpp
//  Auto Correct
//
//  Created by Harshavardhan K on 17/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//
#include <iostream>
#include <vector>
#include "Edit_Distance.hpp"
using namespace std;

#define MAX_LEN_WORD 10
#define MAX_WORDS 100
#define TOLERANCE 2

class BKNode {
    
    string word;
    
public:
    
    int* next;
    
    BKNode(string word) {
        
        this->word = word;
        next = new int[2 * MAX_LEN_WORD];
        
        for(int i = 0; i < MAX_LEN_WORD; i++) {
            next[i] = 0;
        }
    }
    
    BKNode() {}
    
   // BKNode() {std::cout << "Empty initialization of BKNode\n";}
    
    string get_word() {return word;}
   // int* get_next() {return next;}
    
    void description() {
        std::cout << word << " ";
        
        if(next) {
            std::cout << "Has next\n";
        }
    }
    
    
};

class BKTree {
    
    BKNode* root;
    
   // vector<BKNode*> *ALL_NODES = new vector<BKNode*>(20);
    BKNode TREE[MAX_WORDS]; //TODO:- CONVER TO VECTOR<BKNODE*> LATER
    
    //HELPER VARIABLES
    int index_pointer;
    int size;
    
public:
    
    BKTree(string root_word) {
        
        root = new BKNode(root_word);
        //TREE = new BKNode[MAX_WORDS];
        index_pointer = 0;
        size = 0;
        
    }
    
    void add(BKNode*, BKNode*);
    vector<string> get_similar_words(BKNode& root, string& word);
    
    
    //SETTERS
    
    //GETTERS
   // vector<BKNode&>* get_ALL_NODES() {return ALL_NODES;}
    BKNode* get_root() {return root;}
    
    //UTILITIES
    void print_tree_nodes();
    
};

void BKTree::add(BKNode* root, BKNode* current) {
    
    if(root->get_word() == "") {
        root = current;
        size = 0;
        return;
    }
    
    int edits = edit_distance(root->get_word(), current->get_word(), root->get_word().length(), current->get_word().length());
    
    
    if(TREE[root->next[edits]].get_word() == "") {
       // cout << TREE[root->next[edits]].get_word() << " ";
        index_pointer++;
        TREE[index_pointer] = *current;
        root->next[edits] = index_pointer;
        
        size++;
        
    } else {
        size++;
        add(&TREE[root->next[edits]], current);
        
        
    }
    
}

vector<string> BKTree::get_similar_words(BKNode &root, string &word) {
    
    vector<string> similar_nodes;
    
    if(root.get_word() == "") {
        cout << "Empty tree\n";
        return similar_nodes;
    }
    
    int edits = edit_distance(root.get_word(), word, root.get_word().length(), word.length());
    
    if(edits <= TOLERANCE) {
        similar_nodes.push_back(root.get_word());
    }
    
    int start = edits - TOLERANCE;
    
    if(start < 0) {
        start = 1;
    }
    
    while(start < edits + TOLERANCE) {
        
        vector<string> temp = get_similar_words(TREE[root.next[edits]], word);
        
        for(auto element: temp) {
            similar_nodes.push_back(element);
        }
        
        start++;
    }
    
    return similar_nodes;
}

void BKTree::print_tree_nodes() {
    
    if(size != 0) {
        
        for(int i = 0; i < size; i++) {
            cout << TREE[i].get_word() << endl;
        }
        
    } else {
        std::cout << "Tree empty\n";
    }
}

//MARK:- NAIVE APPROACH WITH STRUCTS...
