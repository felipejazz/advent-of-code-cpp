#include "Solver.hpp" 


template <typename T>
class Day1Solver : public Solver<T> {
public:
    int solvePt1(const vector<vector<T>> &data) override {
        vector<T> leftValues;
        vector<T> rightValues;

        for (const vector<T>& row : data) {
            T left = row[0];
            leftValues.push_back(left);
            T right = row[1];
            rightValues.push_back(right);
        }
    
        

        this->binaryInsertionSort(rightValues);
        this->binaryInsertionSort(leftValues);
        
        int result = 0;
        for (size_t i = 0; i < leftValues.size(); i++) { 
            result += abs(leftValues[i] - rightValues[i]);
        }
        return result;
    }

    int solvePt2(const vector<vector<T>> &data) override {

        vector<T> leftValues;
        vector<T> rightValues;

        for (const vector<T>& row : data) {
            T left = row[0];
            leftValues.push_back(left);
            T right = row[1];
            rightValues.push_back(right);
        }
    
        unordered_map mappedOcurrences = this->countOccurrences(leftValues, rightValues);
        
        int result = 0;
    
        for(int i = 0; i < leftValues.size(); i++){
            T leftValue = leftValues[i];
            T occurences = mappedOcurrences[leftValue];
            int tempCalculation = leftValue * occurences;
    
            result += tempCalculation;
        }
    
        return result;
    
    }
};