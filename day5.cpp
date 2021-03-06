//
// Created by HPste on 12/12/2021.
//

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "reader.h"
#include "day5.h"
#include "util.h"

#define SIZE 1000

std::vector<std::array<int, 4>> createLines(){
    std::vector<std::string> data = readLines("../input.txt");
    std::vector<std::array<int, 4>> lines(data.size());
    for(int i = 0; i < data.size(); i++) {
        std::vector<std::string> s1 = split(data[i], " -> ");
        std::vector<std::string> first = split(s1[0], ",");
        std::vector<std::string> second = split(s1[1], ",");
        lines[i][0] = stoi(first[0]);
        lines[i][1] = stoi(first[1]);
        lines[i][2] = stoi(second[0]);
        lines[i][3] = stoi(second[1]);
    }
    return lines;
}

std::vector<int> createBoard(std::vector<std::array<int, 4>>& lines, bool diag){
    std::vector<int> board(SIZE * SIZE);
    for(std::array<int, 4> line : lines){
        if(line[0] == line[2]){
            int dy = line[3] > line[1] ? 1 : -1;
            int range = std::abs(line[3] - line[1]);
            for(int i = 0; i <= range; i++) board[(line[1] + i * dy) * SIZE + line[0]]++;
        }
        else if(line[1] == line[3]){
            int dx = line[2] > line[0] ? 1 : -1;
            int range = std::abs(line[2] - line[0]);
            for(int i = 0; i <= range; i++) board[line[1] * SIZE + (line[0] + i * dx)]++;
        }
        else if(diag){
            int dy = line[3] > line[1] ? 1 : -1;
            int dx = line[2] > line[0] ? 1 : -1;
            int range = std::abs(line[2] - line[0]);
            for(int i = 0; i <= range; i++) board[(line[1] + (i * dy)) * SIZE + (line[0] + i * dx)]++;
        }
    }
    return board;
}

int countBoard(std::vector<int>& board){
    int count = 0;
    for(int i = 0; i < SIZE * SIZE; i++){
        if(board[i] > 1) count++;
    }
    return count;
}

int day5part1(){
    std::vector<std::array<int, 4>> lines = createLines();
    std::vector<int> board = createBoard(lines, false);
    return countBoard(board);
}

int day5part2(){
    std::vector<std::array<int, 4>> lines = createLines();
    std::vector<int> board = createBoard(lines, true);
    return countBoard(board);
}