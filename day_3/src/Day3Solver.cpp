#include "Solver.hpp"
#include <stack>
#include <vector>
#include <cstdlib>
#include <string>
#include <cctype>
#include <utility>

using namespace std;

bool isMultiplierLetter(const string &letter) {
    if (letter.size() != 1) return false;
    return (letter == "m" || letter == "u" || letter == "l");
}
bool isOpeningOrCloseOperator(const string &letter) {
    if (letter.size() != 1) return false;
    return (letter == "(" || letter == ")");
}
bool isOperationSeparator(const string &letter) {
    if (letter.size() != 1) return false;
    return (letter == ",");
}
bool isDigitToken(const string &letter) {
    if (letter.size() != 1) return false;
    return std::isdigit(letter[0]) != 0;
}

int parse3Digits(const vector<string> &row, int &i) {
    int startPos = i;
    string numberStr;
    while (i < (int)row.size() && isDigitToken(row[i]) && (int)numberStr.size() < 3) {
        numberStr += row[i];
        i++;
    }
    if (numberStr.empty()) {
        i = startPos; 
        return -1;
    }
    if (i < (int)row.size() && isDigitToken(row[i])) {
        i = startPos;
        return -1;
    }
    return stoi(numberStr);
}

vector<string> tokenizeLine(const string &line) {
    vector<string> tokens;
    for (char c : line) {
        tokens.push_back(std::string(1, c));
    }
    return tokens;
}


int parseMultiply(const vector<string> &row, int &i) {
    int startPos = i;

    if (i >= (int)row.size()) return 0;
    if (!isMultiplierLetter(row[i]) || row[i] != "m") return 0;
    i++;
    if (i >= (int)row.size()) { i = startPos; return 0; }
    if (!isMultiplierLetter(row[i]) || row[i] != "u") {
        i = startPos;
        return 0;
    }
    i++;
    if (i >= (int)row.size()) { i = startPos; return 0; }
    if (!isMultiplierLetter(row[i]) || row[i] != "l") {
        i = startPos;
        return 0;
    }
    i++;
    if (i >= (int)row.size()) { i = startPos; return 0; }
    if (!isOpeningOrCloseOperator(row[i]) || row[i] != "(") {
        i = startPos;
        return 0;
    }
    i++;
    int firstNum = parse3Digits(row, i);
    if (firstNum < 0) {
        i = startPos;
        return 0;
    }
    if (i >= (int)row.size()) { i = startPos; return 0; }
    if (!isOperationSeparator(row[i]) || row[i] != ",") {
        i = startPos;
        return 0;
    }
    i++;
    int secondNum = parse3Digits(row, i);
    if (secondNum < 0) {
        i = startPos;
        return 0;
    }
    if (i >= (int)row.size()) { i = startPos; return 0; }
    if (!isOpeningOrCloseOperator(row[i]) || row[i] != ")") {
        i = startPos;
        return 0;
    }
    i++;
    return firstNum * secondNum;
}

template <typename T>
class Day3Solver : public Solver<T> {
public:
int solvePt1(const vector<vector<string>> &data) override {
    int totalSum = 0;

    for (auto &row : data) {
        if (row.empty()) continue;
        string combinedLine;
        for (const auto &piece : row) {
            combinedLine += piece;
        }
        vector<string> tokens = tokenizeLine(combinedLine);
        for (int i = 0; i < (int)tokens.size();) {
            int result = parseMultiply(tokens, i);
            if (result == 0) {
                i++;
            } else {
                totalSum += result;
            }
        }
    }

    return totalSum;
}



    int solvePt2(const vector<vector<T>> &data) override {
        return 0;
    }
};
