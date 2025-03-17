#include "Solver.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void testSolver() {
    cout << "Starting tests for Solver..." << endl;
    
    Solver solver;
    vector<string> rows = solver.readInput("../tests/input/input.txt");
    pair<vector<int>, vector<int>> colsPairs = solver.parse(rows);
    int result1 = solver.solvePt1(colsPairs);
    cout << "Result: " << result1 << endl;
    
    bool test1Passed = result1 == 11;
    assert(test1Passed);
    cout << "\nPart 1 test passed successfully!" << endl;

    int result2 = solver.solvePt2(colsPairs);
    bool test2Passed = result2 == 31;
    cout << "Result: " << result2 << endl;
    assert(test2Passed);
    cout << "\nPart 2 test passed successfully!" << endl;
    cout << "\nAll tests passed successfully!" << endl;
    
}

int main() {

    testSolver();
    return 0;
}
