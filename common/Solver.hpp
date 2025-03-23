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

template<typename T>

class Solver {
protected:
    int binarySearch(const vector<T>& array, T item, int low, int high);
    void binaryInsertionSort(vector<T>& array);
    unordered_map<T, int> countOccurrences(vector<T> origin, vector<T> destination);


public:
    virtual ~Solver() {}

    vector<string> readInput(const string &filePath);
    vector<vector<T>> parse(const vector<string> &rows);
    
    long getMemoryUsage();
    

    chrono::high_resolution_clock::time_point getTime();
    long calculateDuration(chrono::high_resolution_clock::time_point startTime, 
                          chrono::high_resolution_clock::time_point endTime);

    virtual int solvePt1(const vector<vector<T>> &data) = 0;
    virtual int solvePt2(const vector<vector<T>> &data) = 0;
};


long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

template <typename T>
vector<string> Solver<T>::readInput(const string &filePath) {
    vector<string> rows;
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return rows;
    }
    string row;
    while (getline(file, row)) {
        rows.push_back(row);
    }
    file.close();
    return rows;
}
template <typename T>
vector<vector<T>> Solver<T>::parse(const vector<string> &rows) {
    vector<vector<T>> parsedData;
    for (const string &row : rows) {
        istringstream iss(row);
        vector<T> parsedsT;
        T value;
        while (iss >> value) {
            parsedsT.push_back(value);
        }
        parsedData.push_back(parsedsT);
    }
    return parsedData;
}

template <typename T>
int Solver<T>::binarySearch(const vector<T>& array, T item, int low, int high) {
    if (high <= low) {
        return (item > array[low] ? (low + 1) : low);
    }

    int mid = (low + high) / 2;

    if (array[mid] == item) { 
        return mid + 1;
    } else if (item > array[mid]) {
        return binarySearch(array, item, mid + 1, high);
    } else {
        return binarySearch(array, item, low, mid - 1);
    }
    
}

template <typename T>
unordered_map<T, int> Solver<T>::countOccurrences(vector<T> origin, vector<T> destination) {
    unordered_map<T, int> map;
    
    int destinationSize = destination.size();

    for (const T &originElement : origin) {
        if (map.find(originElement) != map.end()) {
            continue;
        }
        int tempIndex = 0;
        while (tempIndex < destinationSize) { 
            if (destination[tempIndex] == originElement) {
                if (map.find(originElement) == map.end()) {
                    map[originElement] = 0;
                }
                map[originElement] += 1;
            }
            tempIndex++;
        }
    }
    return map;
}


template <typename T>
void Solver<T>::binaryInsertionSort(vector<T>& array) {
    int arraySize = array.size();

    for (int i = 1; i < arraySize; i++) {
        T key = array[i];
        int j = i-1;

        int pos = binarySearch(array, key, 0, j);

        while (j >= pos) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    return;
}

template <typename T>
long Solver<T>::getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    
    return usage.ru_maxrss;
    
};

template <typename T>
chrono::high_resolution_clock::time_point Solver<T>::getTime() {
    return chrono::high_resolution_clock::now();
}


template <typename T>
long Solver<T>::calculateDuration(chrono::high_resolution_clock::time_point startTime,
                              chrono::high_resolution_clock::time_point endTime) {
    return chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
}

#endif