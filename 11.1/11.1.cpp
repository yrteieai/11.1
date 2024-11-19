#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool FindThirdDotInLine(const string& line, int& dotPosition) {
    int dotCount = 0;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == '.') {
            dotCount++;
            if (dotCount == 3) {
                dotPosition = static_cast<int>(i); 
                return true; 
            }
        }
    }
    return false; 
}

void ReplaceEveryFourthChar(string& line) {
    for (size_t i = 3; i < line.size(); i += 4) {
        line[i] = '.';
    }
}

bool ProcessFileForThirdDot(const string& inputFileName, int& thirdDotLine, int& thirdDotPosition) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << inputFileName << endl;
        return false;
    }

    string line;
    int lineNumber = 0;
    while (getline(inputFile, line)) {
        lineNumber++;
        int position;
        if (FindThirdDotInLine(line, position)) {
            thirdDotLine = lineNumber;
            thirdDotPosition = position;
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    return false; 
}

bool ModifyFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << inputFileName << endl;
        return false;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not create the output file " << outputFileName << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line)) {
        ReplaceEveryFourthChar(line);
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();
    return true;
}

int main() {
    string inputFileName = "C:\\Users\\USER\\OneDrive\\Рабочий стол\\Pizza.txt";
    string outputFileName = "modified_Pizza.txt";

    int thirdDotLine = -1;
    int thirdDotPosition = -1;

    if (ProcessFileForThirdDot(inputFileName, thirdDotLine, thirdDotPosition)) {
        cout << "Third dot found in line " << thirdDotLine
            << ", position " << thirdDotPosition << endl;
    }
    else {
        cout << "Third dot not found in the file." << endl;
    }

    if (ModifyFile(inputFileName, outputFileName)) {
        cout << "Modified file saved as: " << outputFileName << endl;
    }
    else {
        cerr << "Failed to modify the file." << endl;
    }

    return 0;
}
