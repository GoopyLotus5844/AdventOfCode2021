//
// Created by HPste on 12/16/2021.
//

#include <vector>
#include <string>
#include <array>
#include "reader.h"
#include "day9.h"

std::vector<std::vector<int>> makeGrid(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::vector<std::vector<int>> grid {};
    grid.reserve(lines.size());
    for(std::string line : lines){
        std::string::iterator it;
        std::vector<int> row {};
        row.reserve(line.size());
        for(it = line.begin(); it != line.end(); it++){
            row.push_back(*it - '0');
        }
        grid.push_back(row);
    }
    return grid;
}

std::vector<std::pair<int, int>> listLow(std::vector<std::vector<int>> &grid){
    std::vector<std::pair<int, int>> low{};
    int w = (int) grid[0].size();
    int h = (int) grid.size();
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            int n = grid[y][x];
            if(y != 0 && grid[y - 1][x] <= n) continue;
            if(x != 0 && grid[y][x - 1] <= n) continue;
            if(y != h - 1 && grid[y + 1][x] <= n) continue;
            if(x != w - 1 && grid[y][x + 1] <= n) continue;
            low.emplace_back(x, y);
        }
    }

    return low;
}

int fill(int x, int y, std::vector<std::vector<int>> &grid){
    if(grid[y][x] == 9) return 0;
    int total = 1;
    int w = (int) grid[0].size();
    int h = (int) grid.size();
    int n = grid[y][x];
    grid[y][x] *= -1;

    if(y != 0 && grid[y - 1][x] >= n) total += fill(x, y - 1, grid);
    if(x != 0 && grid[y][x - 1] >= n) total += fill(x - 1, y, grid);
    if(y != h - 1 && grid[y + 1][x] >= n) total += fill(x, y + 1, grid);
    if(x != w - 1 && grid[y][x + 1] >= n) total += fill(x + 1, y, grid);
    return total;
}

int day9part1(){
    std::vector<std::vector<int>> grid = makeGrid();
    std::vector<std::pair<int, int>> low = listLow(grid);

    int total = 0;
    for(std::pair<int, int> point : low){
        total += grid[point.second][point.first] + 1;
    }
    return total;
}

int day9part2(){
    std::vector<std::vector<int>> grid = makeGrid();
    std::vector<std::pair<int, int>> low = listLow(grid);

    std::array<int, 3> big {0, 0, 0};
    int smallest = 0;
    for(std::pair<int, int> point : low){
        int size = fill(point.first, point.second, grid);
        if(size > big[smallest]) big[smallest] = size;
        for(int i = 0; i < big.size(); i++){
            if(big[i] < big[smallest]) smallest = i;
        }
    }

    return big[0] * big[1] * big[2];
}