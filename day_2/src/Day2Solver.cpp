#include "Solver.hpp" 
#include <vector>
#include <cstdlib>

using namespace std;

bool isRowSafePt(const vector<int>& row) {
    if (row.size() < 2) return false;
    
    bool directionSet = false;
    bool increasing;
    
    for (int i = 1; i < row.size(); ++i) {
        int current = row[i - 1];
        int next = row[i];
        int diff = current - next;
        int absolute_diff = abs(diff);
        
        if (absolute_diff < 1 || absolute_diff > 3) return false;
        
        if (!directionSet) {
            increasing = (diff > 0);
            directionSet = true;
        } else {
            bool currentDirection = (diff > 0);
            if (currentDirection != increasing) return false;
        }
    }
    return true;
}

template <typename T>
class Day2Solver : public Solver<T> {
public:
    int solvePt1(const vector<vector<T>> &data) override {
        int counter = 0;
        for (const vector<T>& row : data) {
            if (isRowSafePt(row)) {
                counter++;
            }
        }
        return counter;
    }

    int solvePt2(const vector<vector<T>> &data) override {
        int counter = 0;
        for (const vector<T>& row : data) {
            if (isRowSafePt(row)) {
                counter++;
                continue;
            }
            
            bool canBeSafe = false;
            for (int i = 0; i < row.size(); ++i) {
                vector<int> modifiedRow;
                modifiedRow.reserve(row.size() - 1);
                for (int j = 0; j < row.size(); ++j) {
                    if (j != i) {
                        modifiedRow.push_back(row[j]);
                    }
                }
                if (isRowSafePt(modifiedRow)) {
                    canBeSafe = true;
                    break;
                }
            }
            
            if (canBeSafe) {
                counter++;
            }
        }
        return counter;
    }
};


