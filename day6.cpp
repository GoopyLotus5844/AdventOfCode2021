//
// Created by HPste on 12/12/2021.
//

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <chrono>
#include "reader.h"
#include "day5.h"
#include "util.h"
#include "types.h"

u64 day6part1(){
    std::string input = readLines("../input.txt")[0];
    std::vector<int> fish = splitToInt(input, ",");
    std::array<u64, 9> sim{};
    for(int f : fish) sim[f]++;

    for(int i = 0; i < 256; i++){
        u64 zero = sim[0];
        for(int n = 0; n < 8; n++){
            sim[n] = sim[n + 1];
            if(n == 6) sim[6] += zero;
        }
        sim[8] = zero;
    }

    u64 count = 0;
    for(u64 s : sim) count += s;
    return count;
}

