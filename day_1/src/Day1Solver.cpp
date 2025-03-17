#include "Solver.hpp" 

class Day1Solver : public Solver {
public:
    int solvePt1(const vector<vector<int>> &data) override {
        vector<int> leftValues;
        vector<int> rightValues;

        for (const vector<int>& row : data) {
            int left = row[0];
            leftValues.push_back(left);
            int right = row[1];
            rightValues.push_back(right);
        }
    
        

        binaryInsertionSort(rightValues);
        binaryInsertionSort(leftValues);
        
        int result = 0;
        for (size_t i = 0; i < leftValues.size(); i++) { 
            result += abs(leftValues[i] - rightValues[i]);
        }
        return result;
    }

    int solvePt2(const vector<vector<int>> &data) override {

        vector<int> leftValues;
        vector<int> rightValues;

        for (const vector<int>& row : data) {
            int left = row[0];
            leftValues.push_back(left);
            int right = row[1];
            rightValues.push_back(right);
        }
    
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
};