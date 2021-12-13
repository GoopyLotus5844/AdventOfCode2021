//
// Created by HPste on 12/11/2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include "reader.h"
#include "util.h"
#include "day4.h"
#include "types.h"

#define SIZE 5

bool checkWin(std::unordered_map<int, int>& board, std::vector<int>& numbers){
    std::array<int, 10> line{};
    for(int& number : numbers) {
        if(board.find(number) == board.end()) continue;
        int n = board[number];
        int r = n / 5;
        int c = n % 5;
        line[r]++;
        line[c + 5]++;
    }
    return std::any_of(line.begin(), line.end(), [](int &i){return i == SIZE;});
}

void fillBoards(std::vector<std::unordered_map<int, int>> &boards, std::vector<std::string> &lines){
    std::unordered_map<int, int> board;

    for(int i = 2; i < lines.size(); i++){
        if(i % (SIZE + 1) == 1) {
            boards[i / (SIZE + 1) - 1] = board;
            board.clear();
            continue;
        }
        std::vector<int> row = splitToInt(lines[i]);
        for(int n = 0; n < row.size(); n++) {
            board.insert(std::pair<int, int>(row[n], ((i - 2) % (SIZE + 1)) * SIZE + n));
        }
    }
    boards[boards.size() - 1] = board;
}

int day4part1(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::vector<std::unordered_map<int, int>> boards((lines.size() - 1) / (SIZE + 1));
    fillBoards(boards, lines);

    std::vector<int> nums = splitToInt(lines[0], ",");
    std::vector<int> current{};
    current.reserve(nums.size());

    for(int &num : nums){
        current.push_back(num);
        for(std::unordered_map<int, int> &b : boards){
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

int day4part2(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::vector<std::unordered_map<int, int>> boards((lines.size() - 1) / (SIZE + 1));
    fillBoards(boards, lines);

    std::vector<int> nums = splitToInt(lines[0], ",");
    std::vector<int> current{};
    current.reserve(nums.size());

    std::vector<bool> win(boards.size());
    for(int &num : nums){
        current.push_back(num);
        for(int i = 0; i < boards.size(); i++){
            if(checkWin(boards[i], current) && !win[i]) {
                win[i] = true;
                if(std::any_of(win.begin(), win.end(), [](bool hasWon){return !hasWon;})) continue;
                int total = 0;
                for (auto & itr : boards[i]) {
                    bool exists = std::find(std::begin(current), std::end(current), itr.first) != std::end(current);
                    if(!exists) total += itr.first;
                }
                return total * current.back();
            }
        }
    }
    return 0;
}