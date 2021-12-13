#include <iostream>
#include <vector>
#include <string>
#include "day2.h"
#include "reader.h"
#include "util.h"

using namespace std;

int day2part1() {
    vector<string> lines = readLines("../input.txt");

    int pos = 0;
    int depth = 0;
    for (string str: lines) {
        vector<string> result = split(str);
        if (result[0] == "forward") pos += stoi(result[1]);
        else if (result[0] == "up") depth -= stoi(result[1]);
        else depth += stoi(result[1]);
    }

    return pos * depth;
}

int day2part2() {
    vector<string> lines = readLines("../input.txt");

    int pos = 0;
    int depth = 0;
    int aim = 0;
    for (string str: lines) {
        vector<string> result = split(str);
        int val = stoi(result[1]);
        if (result[0] == "forward") {
            pos += val;
            depth += aim * val;
        } else if (result[0] == "up") aim -= val;
        else aim += val;
    }

    return pos * depth;
}