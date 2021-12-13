#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "reader.h"

using namespace std;

vector<string> readLines(const string& path) {
    string text;
    ifstream File(path);
    vector<string> lines;
    while (getline(File, text)) {
        lines.push_back(text);
    }
    return lines;
}

vector<int> readIntLines(const string& path) {
    string text;
    ifstream File(path);
    vector<int> lines;
    while (getline(File, text)) {
        lines.push_back(stoi(text));
    }
    return lines;
}

vector<unsigned int> readBinaryLines(const string& path){
    string text;
    ifstream File(path);
    vector<unsigned int> lines;
    while (getline(File, text)) {
        lines.push_back(stoi(text, nullptr, 2));
    }
    return lines;
}