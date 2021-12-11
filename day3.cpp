//
// Created by HPste on 12/10/2021.
//
#include <vector>
#include <array>
#include <iostream>
#include "reader.h"
#include "day3.h"

#define BITS 12

int day3part1(){
    std::vector<std::string> data = readLines("input.txt");
    std::array<int, BITS> one{};

    for(std::string line : data){
        std::string::iterator it;
        for (it = line.begin(); it != line.end(); it++) {
            if(*it == '1') one[it - line.begin()]++;
        }
    }

    unsigned int number = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] > data.size() / 2) number |= 1UL << (BITS - i - 1);
    }
    return (int) (number * (~number & (1 << BITS) - 1));
}
