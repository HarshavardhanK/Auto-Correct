//
//  Edit_Distance.cpp
//  Auto Correct
//
//  Created by Harshavardhan K on 16/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "Edit_Distance.hpp"


int edit_distance_naive(string wordA, string wordB, int lengthA, int lengthB) {
    
    if(lengthA == 0) {
        return lengthB;
    }
    
    if(lengthB == 0) {
        return lengthA;
    }
    
    if(wordA[lengthA - 1] == wordB[lengthB - 1]) {
        return edit_distance(wordA, wordB, lengthA - 1, lengthB - 1);
    }
    
    int insert = edit_distance(wordA, wordB, lengthA, lengthB - 1);
    int replace = edit_distance(wordA, wordB, lengthA - 1, lengthB - 1);
    int remove = edit_distance(wordA, wordB, lengthA - 1, lengthB);
    
    return 1 + min(insert, min(replace, remove));
}

int edit_distance(string wordA, string wordB, int lengthA, int lengthB) {
    
    int edit_distance_arr[lengthA + 1][lengthB + 1];
    // initialize_2D_array(&edit_distance_arr, lengthA + 1, lengthB + 1, 0);
    
    
    for(int i = 0; i <= lengthA; i++) {
        
        for(int j = 0; j <= lengthB; j++) {
            
            if(i == 0)
                edit_distance_arr[i][j] = j;
            
            else if(j == 0)
                edit_distance_arr[i][j] = i;
            
            else if(wordA[i - 1] == wordB[j - 1]) {
                edit_distance_arr[i][j] = edit_distance_arr[i - 1][j - 1];
                
            } else {
                
                int insert = edit_distance_arr[i][j - 1];
                int replace = edit_distance_arr[i - 1][j - 1];
                int remove = edit_distance_arr[i - 1][j];
                
                edit_distance_arr[i][j] = 1 + min(insert, min(replace, remove));
            }
            
           // cout << edit_distance_arr[i][j] << " ";
        }
    }
    
    return edit_distance_arr[lengthA][lengthB];
}

void test_edit_distance() {
    
    string wordA = "Hello how are you? Its been a long time since seeing you. Are you doing well tonight?";
    string wordB = "Hello ho r u? Its ben a logn time sinc seeing u. Ar you doin well tonigh?";
    
    int lengthA = (int)wordA.length();
    int lengthB = (int)wordB.length();
    
    cout << edit_distance(wordA, wordB, lengthA, lengthB) << endl;
}
