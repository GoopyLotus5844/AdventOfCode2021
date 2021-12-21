//
// Created by HPste on 12/18/2021.
//

#include <vector>
#include <string>
#include <array>
#include <stack>
#include <algorithm>
#include "reader.h"
#include "day10.h"
#include "types.h"

int getScorePart1(char &c){
    if(c == ')') return 3;
    if(c == ']') return 57;
    if(c == '}') return 1197;
    return 25137;
}

int getScorePart2(char &c){
    if(c == '(') return 1;
    if(c == '[') return 2;
    if(c == '{') return 3;
    return 4;
}

int day10part1(){
    std::vector<std::string> lines = readLines("../input.txt");
    int total = 0;

    for(std::string line : lines){
        std::string::iterator it;
        std::stack<char> data;
        for (it = line.begin(); it != line.end(); it++) {
            if(*it == '(' || *it == '[' || *it == '{' || *it == '<') data.push(*it);
            else{
                int diff = *it - data.top();
                if(diff == 2 || diff == 1) data.pop();
                else {
                    total += getScorePart1(*it);
                    break;
                }
            }
        }
    }

    return total;
}

uint64_t day10part2(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::vector<u64> scores;

    for(std::string line : lines) {
        std::string::iterator it;
        std::stack<char> data;
        bool valid = true;
        u64 score = 0;
        for (it = line.begin(); it != line.end(); it++) {
            if(*it == '(' || *it == '[' || *it == '{' || *it == '<') data.push(*it);
            else{
                int diff = *it - data.top();
                if(diff == 2 || diff == 1) data.pop();
                else {
                    valid = false;
                    break;
                }
            }
        }
        if(!valid) continue;
        while((int) data.size() > 0){
            score = score * 5 + getScorePart2(data.top());
            data.pop();
        }
        scores.push_back(score);
    }

    std::sort(scores.begin(), scores.end());
    return scores[scores.size() / 2];
}