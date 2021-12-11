#include <iostream>
#include <vector>
#include "day2.h"
#include "reader.h"
#include "util.h"

using namespace std;

int day2part1() {
    vector<string> lines = readLines("../input.txt");

    int pos = 0;
    int depth = 0;
    for (string str: lines) {
        vector<string> split = tokenize(str);
        if (split[0] == "forward") pos += stoi(split[1]);
        else if (split[0] == "up") depth -= stoi(split[1]);
        else depth += stoi(split[1]);
    }

    return pos * depth;
}

int day2part2() {
    vector<string> lines = readLines("../input.txt");

    int pos = 0;
    int depth = 0;
    int aim = 0;
    for (string str: lines) {
        vector<string> split = tokenize(str);
        int val = stoi(split[1]);
        if (split[0] == "forward") {
            pos += val;
            depth += aim * val;
        } else if (split[0] == "up") aim -= val;
        else aim += val;
    }

    return pos * depth;
}