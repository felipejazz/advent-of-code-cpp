#include "Solver.hpp"
#include <stack>
#include <vector>
#include <cstdlib>
#include <string>
#include <cctype>
#include <utility>

using namespace std;

// Check if character is 'm', 'u', or 'l'
bool isMultiplierLetter(const string &letter) {
    if (letter.size() != 1) return false;
    return (letter == "m" || letter == "u" || letter == "l");
}

// Check if character is '(' or ')'
bool isOpeningOrCloseOperator(const string &letter) {
    if (letter.size() != 1) return false;
    return (letter == "(" || letter == ")");
}

// Check if character is ','
bool isOperationSeparator(const string &letter) {
    if (letter.size() != 1) return false;
    return (letter == ",");
}

// Check if character is a digit
bool isDigitToken(const string &letter) {
    if (letter.size() != 1) return false;
    return std::isdigit(letter[0]) != 0;
}

// Parse up to 3 digits (no more, no less).
// Returns -1 if invalid or more than 3 digits found.
int parse3Digits(const vector<string> &row, int &i) {
    int startPos = i;
    string numberStr;
    // We allow up to 3 digits
    while (i < (int)row.size() && isDigitToken(row[i]) && (int)numberStr.size() < 3) {
        numberStr += row[i];
        i++;
    }
    // No digits at all => fail
    if (numberStr.empty()) {
        i = startPos;
        return -1;
    }
    // If the next token is also a digit => more than 3 digits => fail
    if (i < (int)row.size() && isDigitToken(row[i])) {
        i = startPos;
        return -1;
    }
    // Convert to int
    return stoi(numberStr);
}

// Tokenize a line into single-character strings
vector<string> tokenizeLine(const string &line) {
    vector<string> tokens;
    for (char c : line) {
        tokens.push_back(std::string(1, c));
    }
    return tokens;
}

// Parse mul(...) at the current position. 
// If it parses successfully, returns the product of the two numbers. 
// If it fails, returns 0 and resets i to the original position.
int parseMultiply(const vector<string> &row, int &i) {
    int startPos = i;

    if (i + 6 >= (int)row.size()) return 0; // Quick boundary check

    // Must match 'm' 'u' 'l' '(' ...
    if (!isMultiplierLetter(row[i]) || row[i] != "m") return 0;
    i++;
    if (!isMultiplierLetter(row[i]) || row[i] != "u") { i = startPos; return 0; }
    i++;
    if (!isMultiplierLetter(row[i]) || row[i] != "l") { i = startPos; return 0; }
    i++;

    // Expect '('
    if (!isOpeningOrCloseOperator(row[i]) || row[i] != "(") {
        i = startPos;
        return 0;
    }
    i++;

    // First number
    int firstNum = parse3Digits(row, i);
    if (firstNum < 0) {
        i = startPos;
        return 0;
    }

    // Expect comma
    if (i >= (int)row.size() || !isOperationSeparator(row[i]) || row[i] != ",") {
        i = startPos;
        return 0;
    }
    i++;

    // Second number
    int secondNum = parse3Digits(row, i);
    if (secondNum < 0) {
        i = startPos;
        return 0;
    }

    // Expect ')'
    if (i >= (int)row.size() || !isOpeningOrCloseOperator(row[i]) || row[i] != ")") {
        i = startPos;
        return 0;
    }
    i++;

    // Successfully parsed mul(...) => return the product
    return firstNum * secondNum;
}

/**
 * Try to parse `do()` or `don't()` at position i in the token list.
 *   - Returns +1 if "do()" is found
 *   - Returns -1 if "don't()" is found (accepting ' or ’)
 *   - Returns 0 otherwise
 */
int parseConditional(const vector<string> &row, int &i) {
    int startPos = i;

    // 1) Check for do():
    //    Must match exactly: d, o, (, )
    if (i + 3 < (int)row.size()) {
        if (row[i] == "d" && row[i+1] == "o" && 
            row[i+2] == "(" && row[i+3] == ")")
        {
            i += 4; // advance index to consume "d","o","(",")"
            return +1; // do()
        }
    }

    // Reset index if we partially matched but it wasn't correct
    i = startPos;

    // 2) Check for don't():
    //    Must match exactly: d, o, n, [apostrophe or curly-quote], t, (, )
    //    We'll accept either a straight ASCII apostrophe "'" or a curly quote "’"
    if (i + 6 < (int)row.size()) {
        bool isApostrophe = (row[i+3] == "'" || row[i+3] == "’");
        if (row[i] == "d" && row[i+1] == "o" &&
            row[i+2] == "n" && isApostrophe &&
            row[i+4] == "t" && row[i+5] == "(" && row[i+6] == ")")
        {
            i += 7; // advance index to consume "d","o","n","'|’","t","(",")"
            return -1; // don't()
        }
    }

    // If neither do() nor don't() found
    i = startPos;
    return 0;
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
        int totalSum = 0;

        for (auto &row : data) {
            if (row.empty()) continue;

            string combinedLine;
            for (const auto &piece : row) {
                combinedLine += piece;
            }
            vector<string> tokens = tokenizeLine(combinedLine);

            bool isMulEnabled = true;

            for (int i = 0; i < (int)tokens.size();) {
                int cond = parseConditional(tokens, i);
                if (cond == +1) {
                    isMulEnabled = true;
                    continue;
                }
                else if (cond == -1) {
                    isMulEnabled = false;
                    continue; 
                }

                int result = parseMultiply(tokens, i);
                if (result == 0) {
                    i++;
                } else {
                    if (isMulEnabled) {
                        totalSum += result;
                    }
                }
            }
        }

        return totalSum;
    }
};
