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

int countPaths1(CaveMap &caves, std::unordered_set<std::string> &pathSet, std::string &start){
    pathSet.insert(start);
    int count = 0;

    for(std::string cave : caves[start]){
        if(cave == "start" || (islower(cave.at(0)) && pathSet.find(cave) != pathSet.end())){
            continue;
        }
        if(cave == "end") count++;
        else count += countPaths1(caves, pathSet, cave);
    }
    pathSet.erase(start);
    return count;
}

int countPaths2(CaveMap &caves, std::unordered_set<std::string> &pathSet, std::string &start, bool canRepeat, bool isRepeat){
    pathSet.insert(start);
    int count = 0;

    for(std::string cave : caves[start]){
        if(cave == "end") {
            count++;
            continue;
        }
        if(cave == "start") continue;

        bool canRepeatNext = canRepeat;
        if(islower(cave.at(0)) && pathSet.find(cave) != pathSet.end()){
            if(canRepeatNext) canRepeatNext = false;
            else continue;
        }
        count += countPaths2(caves, pathSet, cave, canRepeatNext, canRepeatNext != canRepeat);
    }
    if(!isRepeat) pathSet.erase(start);
    return count;
}

CaveMap makeCaveMap(){
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
    return caves;
}

int day12part1(){
    CaveMap caves = makeCaveMap();
    std::string start = "start";
    std::unordered_set<std::string> set {};
    return countPaths1(caves, set, start);
}

int day12part2(){
    CaveMap caves = makeCaveMap();
    std::string start = "start";
    std::unordered_set<std::string> set {};
    return countPaths2(caves, set, start, true, false);
}
