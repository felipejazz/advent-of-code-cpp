#include "Day2Solver.cpp"
#include <cassert>
#include <iostream>

using namespace std;



void testSolver() {
    cout << "Starting tests for Solver..." << endl;
    
    Day2Solver<int> solver;
    vector<string> rawRows = solver.readInput("../tests/input/input.txt");
    vector<vector<int>> rows = solver.parse(rawRows);
    cout << "\n Parsed data (" << rows.size() << " rows):" << endl;
    for(const auto& row : rows) {
        for(int num : row) cout << num << " ";
        cout << endl;
    }

    int result1 = solver.solvePt1(rows);
    cout << "Result: " << result1 << endl;
    
    bool test1Passed = result1 == 2;
    assert(test1Passed);
    cout << "\nPart 1 test passed successfully!" << endl;

    int result2 = solver.solvePt2(rows);
    bool test2Passed = result2 == 4;
    cout << "Result: " << result2 << endl;
    assert(test2Passed);
    cout << "\nPart 2 test passed successfully!" << endl;
    cout << "\nAll tests passed successfully!" << endl;
    
}

int main() {

    testSolver();
    return 0;
}
