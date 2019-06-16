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

int edit_distance(string wordA, string wordB, int lengthA, int lengthB);
int edit_distance_dynamic(string, string, int, int);
void test_edit_distance();
#endif /* Edit_Distance_hpp */
