#include <vector>
#include <iostream>

using namespace std;

vector<string> tokenize(string& s, string del = " ") {
    int start = 0;
    int end = s.find(del);
    while(end == start){
        start++;
        end = s.find(del, start);
    }

    vector<string> split;
    while (end != -1) {
        split.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
        while(end == start){
            start++;
            end = s.find(del, start);
        }
    }
    split.push_back(s.substr(start, end - start));
    return split;
}

vector<int> tokenizeToInt(string& s, string del = " "){
    vector<string> split = tokenize(s, del);
    vector<int> ints(split.size());
    for(int i = 0; i < split.size(); i++) ints[i] = stoi(split[i]);
    return ints;
}