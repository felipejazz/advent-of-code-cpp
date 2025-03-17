#include "Solver.hpp"
#include <iostream>
#include <chrono>
#include <sys/resource.h>

using namespace std;

// Função auxiliar para obter o uso de memória (ru_maxrss em kilobytes)
long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

int main() {
    Solver solver;
    vector<string> rows = solver.readInput("../src/input/input.txt");
    pair<vector<int>, vector<int>> colsPairs = solver.parse(rows);
    
    auto startTimePart1 = chrono::high_resolution_clock::now();
    int result1 = solver.solvePt1(colsPairs);
    auto endTimePart1 = chrono::high_resolution_clock::now();
    auto durationPart1 = chrono::duration_cast<chrono::milliseconds>(endTimePart1 - startTimePart1).count();
    long memUsagePart1 = getMemoryUsage();

    auto startTimePart2 = chrono::high_resolution_clock::now();
    int result2 = solver.solvePt2(colsPairs);
    auto endTimePart2 = chrono::high_resolution_clock::now();
    auto durationPart2 = chrono::duration_cast<chrono::milliseconds>(endTimePart2 - startTimePart2).count();
    long memUsagePart2 = getMemoryUsage();

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
