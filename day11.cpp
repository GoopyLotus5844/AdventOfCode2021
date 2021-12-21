//
// Created by HPste on 12/20/2021.
//

#include <vector>
#include <string>
#include <array>
#include <stack>
#include <algorithm>
#include "reader.h"
#include "day10.h"
#include "types.h"
#include "day11.h"

#define SIZE 10

int day11part1(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::array<int, SIZE * SIZE> grid {};
    for(int i = 0; i < lines.size(); i++){
        std::string::iterator it;
        for (it = lines[i].begin(); it != lines[i].end(); it++) {
            grid[i * SIZE + (it - lines[i].begin())] = *it - '0';
        }
    }

    int flashes = 0;
    for(int i = 0; i < 100; i++){
        for(int & n : grid) n++;
        while(true){
            bool updates = false;
            for(int n = 0; n < grid.size(); n++){
                if(grid[n] > 9){
                    flashes++;
                    updates = true;
                    bool left = n % SIZE == 0;
                    bool top = n < SIZE;
                    bool bottom = n / SIZE == SIZE - 1;
                    bool right = n % SIZE == SIZE - 1;
                    if(!left && !top) grid[n - SIZE - 1]++;
                    if(!top) grid[n - SIZE]++;
                    if(!right && !top) grid[n - SIZE + 1]++;
                    if(!left) grid[n - 1]++;
                    if(!right) grid[n + 1]++;
                    if(!left && !bottom) grid[n + SIZE - 1]++;
                    if(!bottom) grid[n + SIZE]++;
                    if(!right && !bottom) grid[n + SIZE + 1]++;
                    grid[n] *= -1;
                }
            }
            if(!updates) break;
        }
        for(int &n : grid) {
            if(n < 0 || n > 9) n = 0;
        }
    }

    return flashes;
}

int day11part2(){
    std::vector<std::string> lines = readLines("../input.txt");
    std::array<int, SIZE * SIZE> grid {};
    for(int i = 0; i < lines.size(); i++){
        std::string::iterator it;
        for (it = lines[i].begin(); it != lines[i].end(); it++) {
            grid[i * SIZE + (it - lines[i].begin())] = *it - '0';
        }
    }


    for(int i = 0; i < 1000; i++){
        for(int & n : grid) n++;
        int flashes = 0;
        while(true){
            bool updates = false;
            for(int n = 0; n < grid.size(); n++){
                if(grid[n] > 9){
                    flashes++;
                    updates = true;
                    bool left = n % SIZE == 0;
                    bool top = n < SIZE;
                    bool bottom = n / SIZE == SIZE - 1;
                    bool right = n % SIZE == SIZE - 1;
                    if(!left && !top) grid[n - SIZE - 1]++;
                    if(!top) grid[n - SIZE]++;
                    if(!right && !top) grid[n - SIZE + 1]++;
                    if(!left) grid[n - 1]++;
                    if(!right) grid[n + 1]++;
                    if(!left && !bottom) grid[n + SIZE - 1]++;
                    if(!bottom) grid[n + SIZE]++;
                    if(!right && !bottom) grid[n + SIZE + 1]++;
                    grid[n] *= -1;
                }
            }
            if(!updates) break;
        }
        if(flashes == 100) return i + 1;
        for(int &n : grid) {
            if(n < 0 || n > 9) n = 0;
        }
    }
}