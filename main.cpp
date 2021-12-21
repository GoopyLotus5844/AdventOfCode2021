#include <iostream>
#include <chrono>
#include "test.h"
#include "day3.h"
#include "day4.h"
#include "test.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"
#include "day9.h"
#include "day10.h"
#include "types.h"

using namespace std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    u64 answer = day10part2();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
    cout << answer << endl;
    //test();
    return 0;
}