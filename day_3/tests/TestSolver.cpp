#include "Day3Solver.cpp" 
#include <cassert>
#include <iostream>

using namespace std;

void testSolver() {
    cout << "Starting tests for Solver..." << endl;
    
    Day3Solver<string> solver;

    vector<string> rawRows = solver.readInput("../tests/input/input.txt");
    
    vector<vector<string>> rows = solver.parse(rawRows);
    
    cout << "\nParsed data (" << rows.size() << " rows):" << endl;
    for (const auto &row : rows) {
        for (const auto &token : row) {
            cout << token << " ";
        }
        cout << endl;
    }
    
    // Solve part 1
    int result1 = solver.solvePt1(rows);
    cout << "Result Pt1: " << result1 << endl;
    
    // Suppose we expect 161:
    bool test1Passed = (result1 == 161);
    assert(test1Passed);
    cout << "\nPart 1 test passed successfully!" << endl;
}

int main() {
    testSolver();
    return 0;
}
