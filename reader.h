#ifndef READER_H
#define READER_H

std::vector<std::string> readLines(const std::string& path);
std::vector<int> readIntLines(const std::string& path);
std::vector<unsigned int> readBinaryLines(const std::string& path);

#endif