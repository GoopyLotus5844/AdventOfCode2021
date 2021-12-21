//
// Created by HPste on 12/20/2021.
//

#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include "reader.h"
#include "util.h"
#include "day12.h"

typedef std::unordered_map<std::string, std::vector<std::string>> CaveMap;
typedef std::pair<std::string, std::vector<std::string>> MapPair;

int countPaths(CaveMap &caves, std::unordered_set<std::string> &pathSet, std::string &start){
    pathSet.insert(start);
    std::vector<std::string> current = caves[start];
    int count = 0;

    for(std::string cave : current){
        if(cave == "start" || (islower(cave.at(0)) && pathSet.find(cave) != pathSet.end())){
            continue;
        }
        if(cave == "end") count++;
        else count += countPaths(caves, pathSet, cave);
    }
    pathSet.erase(start);
    return count;
}

int day12part1(){
    std::vector<std::string> lines = readLines("../input.txt");
    CaveMap caves{};

    for(std::string line : lines){
        std::vector<std::string> parts = split(line, "-");
        if(caves.find(parts[0]) == caves.end()) {
            caves.insert(MapPair(parts[0], std::vector<std::string> {parts[1]}));
        }
        else caves[parts[0]].push_back(parts[1]);

        if(caves.find(parts[1]) == caves.end()) {
            caves.insert(MapPair(parts[1], std::vector<std::string> {parts[0]}));
        }
        else caves[parts[1]].push_back(parts[0]);
    }

    std::string start = "start";
    std::unordered_set<std::string> set {};
    return countPaths(caves, set, start);
}
