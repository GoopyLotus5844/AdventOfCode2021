//
// Created by HPste on 12/10/2021.
//
#include <iostream>
#include <array>
#include <unordered_map>
#include "test.h"

void test(){
    /*std::unordered_map<int, int> thing;
    thing.insert(std::pair<int, int>(5, 10));
    std::cout << thing[5] << std::endl;
    std::cout << thing[100] << std::endl;*/

    std::array<int, 4> thing {5, 4, 8, 2};
    int n = thing.back();
    std::cout << n << std::endl;
}
