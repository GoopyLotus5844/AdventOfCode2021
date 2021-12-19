//
// Created by HPste on 12/14/2021.
//

#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include "reader.h"
#include "util.h"
#include "day8.h"

int day8part1(){
    std::vector<std::string> input = readLines("../input.txt");
    int total = 0;
    for(std::string &line : input){
        std::vector<std::string> data = split(line, " ");
        for(int i = 11; i < 15; i++) {
            int length = (int) data[i].length();
            if(length == 2 || length == 4 || length == 3 || length == 7) total ++;
        }
    }
    return total;
}

std::vector<std::string> getDigitTypes(std::vector<std::string> &data){
    std::array<int, 6> order {2, 4, 3, 7, 5, 6};
    std::vector<std::string> result{};
    result.reserve(10);

    for(int o : order) {
        for (int n = 0; n < 10; n++) {
            if (data[n].length() == o) result.push_back(data[n]);
        }
    }
    return result;
}

int getNumber(std::vector<int> segs){
    std::array<bool, 7> disp{};
    for(int seg : segs) disp[seg] = true;
    if(disp[0] && disp[6] && !disp[3]) return 0;
    if(!disp[0] && !disp[6] && disp[3]) return 4;
    if(disp[2] && !disp[0]) return 1;
    if(disp[0] && !disp[5]) return 2;
    if(disp[6] && !disp[1]) return 3;
    if(disp[4] && !disp[2]) return 6;
    if(disp[1] && !disp[2]) return 5;
    if(disp[0] && !disp[1]) return 7;
    if(!disp[4]) return 9;
    return 8;
}

bool in(char c, std::string &str){
    return str.find(c) != std::string::npos;
}

int day8part2(){
    std::vector<std::string> input = readLines("../input.txt");

    int total = 0;
    for(std::string &line : input) {
        std::string available = "abcdefg";
        std::vector<std::string> data = split(line, " ");
        std::vector<std::string> types = getDigitTypes(data);
        std::unordered_map<char, int> format {};

        std::string::iterator it;
        for (it = available.begin(); it != available.end(); it++) {
            if(in(*it, types[2]) && in(*it, types[3]) && !in(*it, types[0]) && !in(*it, types[1])) {
                format.insert(std::pair<char, int>(*it, 0));
            }
            else if(in(*it, types[1]) && in(*it, types[3]) && !in(*it, types[0]) && !in(*it, types[2])) {
                if(in(*it, types[4]) + in(*it, types[5]) + in(*it, types[6]) == 1) format.insert(std::pair<char, int>(*it, 1));
                else format.insert(std::pair<char, int>(*it, 3));
            }
            else if(in(*it, types[0]) && in(*it, types[1]) && in(*it, types[2]) && in(*it, types[3])) {
                if(in(*it, types[7]) + in(*it, types[8]) + in(*it, types[9]) == 2) format.insert(std::pair<char, int>(*it, 2));
                else format.insert(std::pair<char, int>(*it, 5));
            }
            else if(in(*it, types[3]) && !in(*it, types[0]) && !in(*it, types[1]) && !in(*it, types[2])) {
                if(in(*it, types[4]) + in(*it, types[5]) + in(*it, types[6]) == 3) format.insert(std::pair<char, int>(*it, 6));
                else format.insert(std::pair<char, int>(*it, 4));
            }
        }

        int value = 0;
        for(int i = 11; i < 15; i++){
            std::vector<int> segs{};
            segs.reserve(data[i].length());
            for(it = data[i].begin(); it != data[i].end(); it++) segs.push_back(format[*it]);
            value = value * 10 + getNumber(segs);
        }
        total += value;
    }
    return total;
}