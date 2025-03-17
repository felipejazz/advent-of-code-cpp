#include "Solver.hpp"

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


pair<vector<int>, vector<int>> Solver::parse(const vector<string> &rows) {
    vector<int> leftValues;
    vector<int> rightValues;

    for (const string &row : rows) {
        istringstream iss(row);
        int esquerda, direita;
        if (iss >> esquerda >> direita) {
            leftValues.push_back(esquerda);
            rightValues.push_back(direita);
        }
    }
    return make_pair(leftValues, rightValues);
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
        // Se já foi contado, pula para o próximo elemento
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


int Solver::solvePt1(pair<vector<int>, vector<int>> data) {

    vector<int> leftValues = data.first;
    vector<int> rightValues = data.second;

    binaryInsertionSort(rightValues);
    binaryInsertionSort(leftValues);

    int result = 0;

    for(int i = 0; i < leftValues.size(); i++){
        int leftValue = leftValues[i];
        int righValue = rightValues[i];
        int sub = abs(leftValue - righValue);

        result += sub;

    }

    return result;

}

int Solver::solvePt2(pair<vector<int>, vector<int>> data) {

    vector<int> leftValues = data.first;
    vector<int> rightValues = data.second;

    unordered_map mappedOcurrences = countOccurrences(leftValues, rightValues);
    
    int result = 0;

    for(int i = 0; i < leftValues.size(); i++){
        int leftValue = leftValues[i];
        int occurences = mappedOcurrences[leftValue];
        int tempCalculation = leftValue * occurences;

        result += tempCalculation;
    }

    return result;

}