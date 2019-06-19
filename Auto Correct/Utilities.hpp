//
//  Utilities.cpp
//  Auto Correct
//
//  Created by Harshavardhan K on 16/06/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <chrono>
using namespace std::chrono;

template<typename T> void initialize_2D_array(T** *array, int rows, int cols, T with_value = 0) {
    
    *array = new T*[rows];
    
    for(int i = 0; i < rows; i++)
        (*array)[i] = new T[cols];
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*array)[i][j] = with_value;
    
}

template <typename T> void print_vector(std::vector<T>& list) {
    
   // size_t length = list.size();
    
    for(auto element: list) {
        std::cout << element << " ";
    }
    
    std::cout << std::endl;
}

//MARK:- TIMER FUNCTIONS
void time_function(void  (*function) (void)) {
    
    auto start = high_resolution_clock::now();
    
    function();
    
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    std::cout << "Execution time: " << duration.count() << "us" << std::endl;
}

#endif

