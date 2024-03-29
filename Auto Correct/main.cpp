//
//  main.cpp
//  Auto Correct
//
//  Created by Harshavardhan K on 16/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include <iostream>

//#include "Edit_Distance.hpp"
#include "Utilities.hpp"
#include "BKTree.hpp"
//#include "BKTree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
   // cout << edit_distance("hello", "helo", 5, 4) << endl;
   // time_function(test_edit_distance);
    
    BKTree* tree = new BKTree("hello");
    BKNode* root = tree->get_root();
    
    tree->add(root, new BKNode("help"));
    tree->add(root, new BKNode("helo"));
   // tree->add(root, new BKNode("hello"));
    string word = "hep";
    
    //vector<string> similar = tree->get_similar_words(*root, word);
    
    //print_vector(similar);
    
    
    cout << root->get_word() << endl;
    
    tree->print_tree_nodes();
    return 0;
}
