#include <iostream>
#include <fstream>
#include <vector>
#include "reader.h"
using namespace std;

vector<string> readLines(string path){
  string text;
  ifstream File(path);
  vector<string> lines;
  while(getline(File, text)){
    lines.push_back(text);
  }
  return lines;
}

vector<int> readIntLines(string path){
  vector<string> lines = readLines(path);
  vector<int> data;
  for(string line : lines) data.push_back(stoi(line));
  return data;
}