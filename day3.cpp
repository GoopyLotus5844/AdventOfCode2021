//
// Created by HPste on 12/10/2021.
//
#include <vector>
#include <array>
#include <iostream>
#include "reader.h"
#include "day3.h"
#include "types.h"

#define BITS 12

int day3part1v1(){
    std::vector<std::string> data = readLines("../input.txt");
    std::array<int, BITS> one{};

    for(std::string line : data){
        std::string::iterator it;
        for (it = line.begin(); it != line.end(); it++) {
            if(*it == '1') one[it - line.begin()]++;
        }
    }

    u32 number = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] > data.size() / 2) number |= 1 << (BITS - i - 1);
    }
    return (int) (number * (~number & (1 << BITS) - 1));
}

//actually slower this is so sad
int day3part1v2(){
    std::vector<u32> data = readBinaryLines("../input.txt");
    std::array<u32, BITS> one{};

    for(u32 line : data){
        for(int i = 0; i < BITS; i++){
            one[i] += line & 1;
            line >>= 1;
        }
    }

    u32 number = 0;
    for(int i = 0; i < one.size(); i++){
        if(one[i] > data.size() / 2) number |= 1 << i;
    }
    return (int) (number * (~number & (1 << BITS) - 1));
}

u32 getRating(std::vector<u32> data, bool common){
    for(int n = BITS - 1; n >= 0; n--){
        unsigned int one = 0;
        for(u32 line : data){
            one += (line >> n) & 1;
        }

        bool moreOne = one >= data.size() - one;
        for(int i = (int) data.size() - 1; i >= 0; i--){
            u32 value = data[i];
            if((value >> n & 1) ^ moreOne ^ !common) {
                data[i] = data[data.size() - 1];
                data.pop_back();
            }
        }
        if(data.size() == 1) return data[0];
    }
}

int day3part2(){
    std::vector<unsigned int> data = readBinaryLines("../input.txt");
    return (int) getRating(data, true) * (int) getRating(data, false);
}