//
// Created by HPste on 12/10/2021.
//
#include <vector>
#include <array>
#include <iostream>
#include "reader.h"
#include "day3.h"

#define BITS 5

int day3part1v1(){
    std::vector<std::string> data = readLines("../input.txt");
    std::array<int, BITS> one{};

    for(std::string line : data){
        std::string::iterator it;
        for (it = line.begin(); it != line.end(); it++) {
            if(*it == '1') one[it - line.begin()]++;
        }
    }

    unsigned int number = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] > data.size() / 2) number |= 1 << (BITS - i - 1);
    }
    return (int) (number * (~number & (1 << BITS) - 1));
}

//actually slower this is so sad
int day3part1v2(){
    std::vector<unsigned int> data = readBinaryLines("../input.txt");
    std::array<unsigned int, BITS> one{};

    for(unsigned int line : data){
        for(int i = 0; i < BITS; i++){
            one[i] += line & 1;
            line >>= 1;
        }
    }

    unsigned int number = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] > data.size() / 2) number |= 1 << i;
    }
    return (int) (number * (~number & (1 << BITS) - 1));
}

int day3part2(){
    std::vector<unsigned int> data = readBinaryLines("../input.txt");

    std::vector<int> indexes(data.size());

    for(int n = 0; n < BITS; n++){

        unsigned int one = 0;
        for(int index : indexes){
            one += (data[index] >> n) & 1;
        }

        bool moreOne = one >= data.size() / 2;
        for(uint64_t i = indexes.size(); i >= 0; i--){
            moreOne ^ i;
        }
    }

    return 0;
}
