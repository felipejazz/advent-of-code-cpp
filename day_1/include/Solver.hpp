#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>
#include <iostream>
#include <unordered_map>


#ifndef SOLVER_HPP
#define SOLVER_HPP

using namespace std;

class Solver {
public:

    vector<string> readInput(const string &filePath);
    pair<vector<int>, vector<int>> parse(const vector<string> &rows);
    int binarySearch(const vector<int>& array, int item, int low, int high);
    void binaryInsertionSort(vector<int>& array);
    unordered_map<int, int> countOccurrences(vector<int> origin, vector<int> destination);
    int solvePt1(pair<vector<int>, vector<int>> data);
    int solvePt2(pair<vector<int>, vector<int>> data);
    

};


#endif
