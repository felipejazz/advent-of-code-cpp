#include "Solver.hpp"



long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

vector<string> Solver::readInput(const string &filePath) {
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

vector<vector<int>> Solver::parse(const vector<string> &rows) {
    vector<vector<int>> parsedData;
    for (const string &row : rows) {
        istringstream iss(row);
        vector<int> numbers;
        int value;
        while (iss >> value) {
            numbers.push_back(value);
        }
        parsedData.push_back(numbers);
    }
    return parsedData;
}

int Solver::binarySearch(const vector<int>& array, int item, int low, int high) {
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


unordered_map<int, int> Solver::countOccurrences(vector<int> origin, vector<int> destination) {
    unordered_map<int, int> map;
    
    int destinationSize = destination.size();

    for (const int &originElement : origin) {
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


void Solver::binaryInsertionSort(vector<int>& array) {
    int arraySize = array.size();

    for (int i = 1; i < arraySize; i++) {
        int key = array[i];
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

long Solver::getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    
    return usage.ru_maxrss;
    
};

chrono::high_resolution_clock::time_point Solver::getTime() {
    return chrono::high_resolution_clock::now();
}

long Solver::calculateDuration(chrono::high_resolution_clock::time_point startTime,
                              chrono::high_resolution_clock::time_point endTime) {
    return chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
}