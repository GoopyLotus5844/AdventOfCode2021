#include <vector>
#include <iostream>

using namespace std;

vector<string> tokenize(string s, string del = " ") {
    int start = 0;
    int end = s.find(del);
    vector<string> split;
    while (end != -1) {
        split.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    split.push_back(s.substr(start, end - start));
    return split;
}