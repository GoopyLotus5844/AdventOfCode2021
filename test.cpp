//
// Created by HPste on 12/10/2021.
//
#include <iostream>
#include <array>
#include <unordered_map>
#include <vector>
#include "test.h"
#include "types.h"
#include "util.h"

void test(){
    /*std::unordered_map<int, int> thing;
    thing.insert(std::pair<int, int>(5, 10));
    std::cout << thing[5] << std::endl;
    std::cout << thing[100] << std::endl;*/

    /*std::array<int, 4> thing {5, 4, 8, 2};
    int n = thing.back();
    std::cout << n << std::endl;*/

    /*std::string thing = "  H ll o there ";
    std::string del = " ";
    std::vector<std::string> thing1 = split(thing, del);
    std::cout << "poggers" << std::endl;*/

    int *board = new int[10];
    board[3] = 5;
    board[9] = 11;
    for(int i = 0; i < 10; i++) std::cout << board[i];
}
