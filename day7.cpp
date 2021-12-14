//
// Created by HPste on 12/13/2021.
//

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "reader.h"
#include "util.h"
#include "day7.h"

int day7part1(){
    std::string input = readLines("../input.txt")[0];
    std::vector<int> crabs = splitToInt(input, ",");
    std::sort(crabs.begin(), crabs.end());
    int center = (int) crabs.size() / 2;
    int median = (crabs[center - 1] + crabs[center]) / 2;

    int total = 0;
    for(int crab : crabs) total += std::abs(crab - median);
    return total;
}

int calcTotal(std::vector<int>& crabs, int n){
    int total = 0;
    for(int crab : crabs) {
        int diff = std::abs(crab - n);
        total += diff * (diff + 1) / 2;
    }
    return total;
}

int day7part2(){
    std::string input = readLines("../input.txt")[0];
    std::vector<int> crabs = splitToInt(input, ",");

    int sum = 0;
    for(int crab : crabs) sum += crab;
    int avg = sum / (int) crabs.size();

    int t1 = calcTotal(crabs, avg);
    int t2 = calcTotal(crabs, avg + 1);
    int step = t2 < t1 ? 1 : -1;

    while(true){
        avg += step;
        t2 = calcTotal(crabs, avg);
        if(t1 < t2) return t1;
        t1 = t2;
    }
}
