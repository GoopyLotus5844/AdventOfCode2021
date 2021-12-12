//
// Created by HPste on 12/11/2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include "reader.h"
#include "util.h"
#include "day4.h"
#include "types.h"

#define SIZE 5

bool checkWin(std::unordered_map<int, int>& board, std::vector<int>& numbers){
    std::array<int, 12> line{};

    for(int& number : numbers) {
        if(board.find(number) == board.end()) continue;
        int n = board[number];
        int r = n / 5;
        int c = n % 5;
        line[r]++;
        line[c + 5]++;
        if(r == c) line[10]++;
        if(r + c == 4) line[11]++;
    }

    for(int i : line) {
        if(i == SIZE) {
            return true;
        }
    }
    return false;
}

int day4part1(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::vector<int> nums = tokenizeToInt(lines[0], ",");
    std::vector<std::unordered_map<int, int>> boards(((lines.size() - 1) / (SIZE + 1)));
    std::unordered_map<int, int> board;
    std::unordered_map<int, int> cleanBoard = board;

    for(int i = 2; i < lines.size(); i++){
        if(i % (SIZE + 1) == 1) {
            boards[i / (SIZE + 1) - 1] = board;
            board = cleanBoard;
            continue;
        }
        std::vector<int> row = tokenizeToInt(lines[i], " ");
        for(int n = 0; n < row.size(); n++) {
            board.insert(std::pair<int, int>(row[n], ((i - 2) % (SIZE + 1)) * SIZE + n));
        }
    }
    boards[boards.size() - 1] = board;

    std::vector<int> current{};
    current.reserve(nums.size());
    for(int num : nums){
        current.push_back(num);
        for(std::unordered_map<int, int> b : boards){
            if(checkWin(b, current)){
                int total = 0;
                for (auto & itr : b) {
                    bool exists = std::find(std::begin(current), std::end(current), itr.first) != std::end(current);
                    if(!exists) total += itr.first;
                }
                return total * current.back();
            }
        }
    }
    return 0;
}