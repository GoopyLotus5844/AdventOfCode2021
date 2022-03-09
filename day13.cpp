//
// Created by HPste on 3/6/2022.
//

#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include <set>
#include <iostream>
#include "reader.h"

class PointHash {
public:
    std::size_t operator()(const std::array<int, 2> arr) const {
        return 1024 * arr[0] + arr[1];
    }
};

int day13part1(){
    std::vector<std::string> lines = readLines("../input.txt");
    int overlap = 0;
    int fold = 655;

    std::unordered_set<std::array<int, 2>, PointHash> points;
    int index = 0;
    while(true){
        if(lines[index].empty()) break;
        std::size_t comma = lines[index].find(",");
        std::array<int, 2> point {stoi(lines[index].substr(0, comma)),
                                  stoi(lines[index].substr(comma + 1))};
        points.insert(point);
        index++;
    }

    for(std::array<int, 2> point : points){
        if(point[0] < fold){
            int flipX = fold + (fold - point[0]);
            std::array<int, 2> flipPoint {flipX, point[1]};
            if(points.find(flipPoint) != points.end()) overlap++;
        }
    }

    return (int) points.size() - overlap;
}

int day13part2(){
    std::vector<std::string> lines = readLines("../input.txt");

    std::unordered_set<std::array<int, 2>, PointHash> points;
    int index = 0;
    while(true){
        if(lines[index].empty()) break;
        std::size_t comma = lines[index].find(",");
        std::array<int, 2> point {stoi(lines[index].substr(0, comma)),
                                  stoi(lines[index].substr(comma + 1))};
        points.insert(point);
        index++;
    }

    for(int i = index + 1; i < lines.size(); i++){
        int fold = stoi(lines[i].substr(13));
        bool horizontal = lines[i].substr(11, 1) == "x";
        std::unordered_set<std::array<int, 2>, PointHash> newPoints;
        for(const std::array<int, 2>& point : points){
            if(horizontal){
                if(point[0] > fold) {
                    std::array<int, 2> flip {fold + (fold - point[0]), point[1]};
                    newPoints.insert(flip);
                }
                else {
                    std::array<int, 2> copy = point;
                    newPoints.insert(copy);
                }
            }
            else{
                if(point[1] > fold) {
                    std::array<int, 2> flip {point[0], fold + (fold - point[1])};
                    newPoints.insert(flip);
                }
                else {
                    std::array<int, 2> copy = point;
                    newPoints.insert(copy);
                }
            }
        }
        points = newPoints;
    }

    for(int y = 0; y < 6; y++){
        for(int x = 0; x < 39; x++){
            std::array<int, 2> point {x, y};
            if(points.find(point) != points.end()){
                std::cout << "#";
            }
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}