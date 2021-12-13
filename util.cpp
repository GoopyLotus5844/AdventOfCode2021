#include <vector>
#include <iostream>
#include <string>
#include "types.h"

using namespace std;

vector<string> split(string& s, string del = " "){
    size_t start = 0;
    size_t end = s.find(del);
    std::vector<string> split;
    while(end != std::string::npos){
        if(end == start) {
            start += del.size();
            end = s.find(del, start);
            continue;
        }
        split.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    split.push_back(s.substr(start, end - start));
    return split;
}

vector<int> splitToInt(string& s, string del = " "){
    vector<string> result = split(s, del);
    vector<int> ints(result.size());
    for(int i = 0; i < result.size(); i++) ints[i] = stoi(result[i]);
    return ints;
}