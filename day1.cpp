#include <iostream>
#include <vector>
#include "day1.h"
#include "reader.h"

using namespace std;

int day1part1() {
    vector<int> lines = readIntLines("../input.txt");

    int count = 0;
    for (int i = 1; i < lines.size(); i++) {
        if (lines[i] > lines[i - 1]) count++;
    }
    return count;
}

int day1part2() {
    vector<int> data = readIntLines("../input.txt");

    int count = 0;
    for (int i = 3; i < data.size(); i++) {
        if (data[i] > data[i - 3]) count++;
    }
    return count;
}