//
//  Auto_Correct.hpp
//  Auto Correct
//
//  Created by Harshavardhan K on 16/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef Auto_Correct_hpp
#define Auto_Correct_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "BinarySTree.hpp"
#include "Edit_Distance.hpp"

string naive_autocorrect(string word) {
    
    string path = "/Users/HarshavardhanK/Desktop/Code Files/Sublime/C++/Dict.txt";
    
    string dic[] = {"act", "Hello", "Hey", "Hola", "Help", "Apple", "America", "Banana", "Breakfast", "fuck"};
    
    vector<string> naive_vect;
    
    istringstream iss(word);
    
    vector<string> input_vect = {istream_iterator<string>{iss},
        istream_iterator<string>{}};
    
    fstream dictionary_file;
    dictionary_file.open(path, ios::in);
    
    if(!dictionary_file) {
        cout << "File empty, or doesnt exist\n";
        exit(0);
    }
    
    //string word;
    
    while(!dictionary_file.eof()) {
        dictionary_file >> word;
        naive_vect.push_back(word);
    }
    
    dictionary_file.close();
    
    int min_edit = 10;
    string nearest = "Ain't working";
    int len = (int)word.length();
    
    for(auto& str: dic) {
        
        int edit = edit_distance(str, word, str.length(), len);
        
        // min_edit = min(edit, min_edit);
        
        if(edit < min_edit) {
            min_edit = edit;
            nearest = str;
            
        }
        
        if(word.compare(str) == 0) {
            return "No changes!";
        }
    }
    
    return "Did you mean \'" + nearest + "\'?";
}

class AugmentedBST: public BinaryTree<string> {
    
    string replacement;
    int min_edit;
    
    
public:
    
    AugmentedBST() {
        replacement = "";
        min_edit = 10;
    }
    
    string get_correct(string word) {
        
        min_edit = 10;
        
        BinaryTreeNode<string> *run = search(BinaryTree<string>::get_root(), word);
        
        if(run != NULL) {
            if(run->data.compare(word) == 0) {
                return run->data;
            }
        }
        
        return  replacement;
    }
    
    BinaryTreeNode<string>* search(BinaryTreeNode<string>* node, string key) {
        
        if(node == NULL || node->data == key) {
            return node;
        }
        
        int dist = edit_distance(node->data, key, (int)node->data.length(), (int)key.length());
        
        if(dist < min_edit) {
            min_edit = dist;
            replacement = node->data;
        }
        
        if(key > node->data) {
            return search(node->right, key);
            
        } else {
            return search(node->left, key);
        }
    }
    
};

class Autocorrect {
    
    AugmentedBST *tree;
    string replacement;
    
    vector<string> input_string_vec;
    // vector<string> output_string_vec;
    
    void fill_tree() {
        
        string path = "/Users/HarshavardhanK/Desktop/Code Files/Sublime/C++/Dict.txt";
        string word;
        
        fstream dictionary_file;
        dictionary_file.open(path, ios::in);
        
        if(!dictionary_file) {
            cout << "File empty, or doesnt exist\n";
            return;
        }
        
        
        while(!dictionary_file.eof()) {
            dictionary_file >> word;
            tree->insert(word);
        }
        
        dictionary_file.close();
    }
    
    void input_format(string entered) {
        
        istringstream iss(entered);
        
        input_string_vec = {istream_iterator<string>{iss},
            istream_iterator<string>{}};
    }
    
    string autocorrect() {
        
        string res;
        
        for(int i = 0; i < input_string_vec.size(); i++) {
            res  = tree->get_correct(input_string_vec[i]) + " ";
            // cout << input_string_vec[0];
            replacement += res;
            // cout << replacement;
        }
        
        return replacement;
    }
    
public:
    
    Autocorrect() {
        tree = new AugmentedBST();
        replacement = "";
    }
    
    
    void suggest_correct(string entered) {
        
        fill_tree();
        // tree->print_helper();
        input_format(entered);
        
        string res = autocorrect();
        cout << "Did you mean \'" << res <<"\'?"  << endl;
    }
    
};


#endif /* Auto_Correct_hpp */
