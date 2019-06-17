//
//  Edit_Distance.hpp
//  Auto Correct
//
//  Created by Harshavardhan K on 16/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef Edit_Distance_hpp
#define Edit_Distance_hpp

#include <iostream>
using namespace std;

int edit_distance_naive(string wordA, string wordB, size_t lengthA, size_t lengthB);
int edit_distance(string, string, size_t, size_t);
void test_edit_distance();
#endif /* Edit_Distance_hpp */
