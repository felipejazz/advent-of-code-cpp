#include "Day3Solver.cpp" 
#include <cassert>
#include <iostream>

using namespace std;

void testSolver() {
    cout << "Starting tests for Solver..." << endl;
    
    Day3Solver<string> solver;

    vector<string> rawRowsPt1 = solver.readInput("../tests/input/input.txt");
    
    vector<vector<string>> rowsPt1 = solver.parse(rawRowsPt1);
    
    cout << "\nParsed data (" << rawRowsPt1.size() << " rows):" << endl;
    for (const auto &row : rowsPt1) {
        for (const auto &token : row) {
            cout << token << " ";
        }
        cout << endl;
    }

    int result1 = solver.solvePt1(rowsPt1);
    cout << "Result Pt1: " << result1 << endl;
    
    bool test1Passed = (result1 == 161);
    assert(test1Passed);
    cout << "\nPart 1 test passed successfully!" << endl;

    vector<string> rawRowsPt2 = solver.readInput("../tests/input/input2.txt");
    vector<vector<string>> rowsPt2 = solver.parse(rawRowsPt2);
    int result2 = solver.solvePt2(rowsPt2);

    cout << "\nParsed data (" << rawRowsPt2.size() << " rows):" << endl;
    for (const auto &row : rowsPt2) {
        for (const auto &token : row) {
            cout << token << " ";
        }
        cout << endl;
    }
    bool test2Passed = result2 == 48;
    cout << "Result: " << result2 << endl;
    assert(test2Passed);
    cout << "\nPart 2 test passed successfully!" << endl;
    cout << "\nAll tests passed successfully!" << endl;
}

int main() {
    testSolver();
    return 0;
}
