#include "Day2Solver.cpp"
#include <iostream>
#include <chrono>
#include <sys/resource.h>

using namespace std;

int main() {
    Day2Solver solver;
    vector<string> rows = solver.readInput("../src/input/input.txt");
    vector<vector<int>> colsPairs = solver.parse(rows);
    
    auto startTimePart1 = solver.getTime();
    int result1 = solver.solvePt1(colsPairs);
    auto endTimePart1 = solver.getTime();
    auto durationPart1 = solver.calculateDuration(startTimePart1, endTimePart1);
    long memUsagePart1 = solver.getMemoryUsage();

    auto startTimePart2 = solver.getTime();
    int result2 = solver.solvePt2(colsPairs);
    auto endTimePart2 = solver.getTime();
    auto durationPart2 = solver.calculateDuration(startTimePart2, endTimePart2);
    long memUsagePart2 = solver.getMemoryUsage();

    cout << "Part 1:" << endl;
    cout << "  Result: " << result1 << endl;
    cout << "  Time taken: " << durationPart1 << " ms" << endl;
    cout << "  Memory usage: " << memUsagePart1 << " KB" << endl;

    cout << "\nPart 2:" << endl;
    cout << "  Result: " << result2 << endl;
    cout << "  Time taken: " << durationPart2 << " ms" << endl;
    cout << "  Memory usage: " << memUsagePart2 << " KB" << endl;

    return 0;
}
