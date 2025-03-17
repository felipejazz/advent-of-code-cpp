#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <chrono>
#include <sys/resource.h>

using namespace std;

class Solver {
protected:
    int binarySearch(const vector<int>& array, int item, int low, int high);
    void binaryInsertionSort(vector<int>& array);
    unordered_map<int, int> countOccurrences(vector<int> origin, vector<int> destination);

public:
    virtual ~Solver() {}

    vector<string> readInput(const string &filePath);
    vector<vector<int>> parse(const vector<string> &rows);
    long getMemoryUsage();
    

    chrono::high_resolution_clock::time_point getTime();
    long calculateDuration(chrono::high_resolution_clock::time_point startTime, 
                          chrono::high_resolution_clock::time_point endTime);

    virtual int solvePt1(const vector<vector<int>> &data) = 0;
    virtual int solvePt2(const vector<vector<int>> &data) = 0;
};

#endif