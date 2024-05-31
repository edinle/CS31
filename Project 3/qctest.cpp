// Edin Le
// Project 3: qctest.cpp

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidQC(string results);
int passQC(string results);
int defectQC(string results);
int totalQC(string results);
int batches(string results);

int main()
{
    string s;
    for(;;) {
        cout << "Enter a possible test string: ";
        getline(cin, s); if (s == "quit") break;
        cout << "isValidQC returns ";
            cout << isValidQC(s) << endl;
        cout << "pass test result(s) returns ";
            cout << passQC(s) << endl;
        cout << "defectQC(s) returns ";
            cout << defectQC(s) << endl;
        cout << "totalQC(s) returns ";
            cout << totalQC(s) << endl;
        cout << "batches(s) returns ";
            cout << batches(s) << endl;
    }
    cout << "All cases succeesed" << endl;
    return 0;
}

bool isValidQC(string results) {
    
    // if QC test string is empty OR string does not start with 'Q' OR digit after first Q starts with '0', return false
    if(results.empty() || results.at(0) != 'Q' || results.at(1) == '0') {
        return false;   // must not be empty, must start with Q, digit after Q must not be 0
    }
    
    size_t length = results.length();
    int i = 0;
    
    bool presentQ = false;
    bool presentP = false;
    bool presentD = false;
    int Qval = 0;
    int Pval = 0;
    int Dval = 0;
    bool nonZero = false;
    
    char character;
    
    // iterate through the QC test string
    for (i = 0; i < length; i++) {
        character = results.at(i);  // gets the current character
        switch (character) {        // processes each character in string, make sure its either 'Q', 'p', 'd', or a digit
            case 'Q':
                presentQ = true;
                presentP = false;
                presentD = false;
                nonZero = false;
                
                // Pval + Dval = Qval, if not then return false
                if (Qval != Pval + Dval) {
                    return false;
                }
                
                // if char after 'Q' is not a number, return false
                if (i < length - 1 && !isdigit(results.at(i + 1))) {
                    return false;
                }
                
                // if 'Q' is the last character in the string, return false
                if (i == length - 1) {
                    return false;
                }
                
                Qval = 0;   // reset Qval to zero for next batch of results
                break;
            case 'p':
                presentQ = false;
                presentP = true;
                presentD = false;
                nonZero = false;
                
                // if char after 'p' is not a number, return false
                if (i < length - 1 && !isdigit(results.at(i + 1))) {
                    return false;
                }
                
                // if 'p' is the last character in the string, return false
                if (i == length - 1) {
                    return false;
                }
                
                Pval = 0;   // reset Pval to zero for the next batch of results
                break;
            case 'd':
                presentQ = false;
                presentP = false;
                presentD = true;
                nonZero = false;
                
                // if char after 'd' is not a number, return false
                if (i < length - 1 && !isdigit(results.at(i + 1))) {
                    return false;
                }
                
                // if 'd' is the last character in the string, return false
                if (i == length - 1) {
                    return false;
                }
                
                Dval = 0;   // reset Dval to zero for the next batch of results
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': {
                nonZero = true;     // processes that the number is not a zero
                int number = character - '0';
                if (presentQ) {
                    if (i > 0) {    // checks if not first charaacter in string/
                        // check if previous character is digit, multiply Qval by 10 and add existing number for multi-digit numbers
                        if (isdigit(results.at(i - 1))) {
                            Qval = Qval * 10 + number;
                        } else {
                            Qval = number;  // Qval, Pval, and Dval would just be the number if it's not multiple digits
                        }
                    }
                }
                if(presentP) {
                    if (i > 0) {    // checks if not first charaacter in string
                        // check if previous character is digit, multiply Pval by 10 and add existing number for multi-digit numbers
                        if (isdigit(results.at(i - 1))) {
                            Pval = Pval * 10 + number;
                        } else {
                            Pval = number;
                        }
                    }
                }
                if(presentD) {
                    if (i > 0) {    // checks if not first charaacter in string
                        // check if previous character is digit, multiply Dval by 10 and add existing number for multi-digit numbers
                        if (isdigit(results.at(i - 1))) {
                            Dval = Dval * 10 + number;
                        } else {
                            Dval = number;
                        }
                    }
                }
                break;
            }
            case '0':
                //if nonZero is false, check not the end of string, and if there is a digit after, it would be a leading zero
                if (nonZero == false) {
                    if (i < length - 1) {   // check it's not the end of the string
                        if (isdigit(results.at(i + 1))) {   // if the next char is a number then return false
                            return false;
                        }
                    }
                } else {    //
                    int number = character - '0';
                    if (presentQ) {
                        if (i > 0) {    // check the last character and see if it's a number
                            if (isdigit(results.at(i - 1))) {   // check to make sure that it's not the start of the string
                                Qval = Qval * 10 + number;
                            } else {
                                Qval = number;
                            }
                        }
                    }
                    if (presentP) {
                        if (i > 0) {    // check the last character and see if it's a number
                            if (isdigit(results.at(i - 1))) {   // check to make sure that it's not the start of the string
                                Pval = Pval * 10 + number;
                            } else {
                                Pval = number;
                            }
                        }
                    }
                    if (presentD) {
                        if (i > 0) {    // check the last character and see if it's a number
                            if (isdigit(results.at(i - 1))) {   // check to make sure that it's not the start of the string
                                Dval = Dval * 10 + number;
                            } else {
                                Dval = number;
                            }
                        }
                    }
                }
                break;
            default:
                return false;
                break;
        }
    }
    
    // Qval must equal Pval and Dval
    if (Qval != Pval + Dval) {
        return false;
    }
    return true;
}
// returns the amount of passed tests in the string
int passQC(string results) {
    int passTotal = 0;
    int tempTotal = 0;
    bool didPass = false;
    
    if (isValidQC(results) == true) {   // check if QC string is valid
        for (int i = 0; i < results.length(); i++) {
            char character = results.at(i);
            if (character == 'p') {     // iterate through the string to find 'p' indicating passing
                didPass = true;
            } else if (character == 'Q' || character == 'd'){
                didPass = false;
                passTotal += tempTotal; // add the total of previous tests from the tempTotal to passTotal
                tempTotal = 0;          // reset for the next test
            // if didPass is true,
            } else if (didPass){
                int num = character - '0';
                tempTotal = (tempTotal * 10) + num;     // add together the test scores while handing multi-digits
            }
        }
        passTotal += tempTotal;         // add the final total to passTotal
    } else {
        return -1;                      // return -1 if not valid
    }
    return passTotal;
}
// returns the amount of defect tests in the string
int defectQC(string results) {
    int defectTotal = 0;
    int tempTotal = 0;
    bool didPass = false;
    
    if (isValidQC(results) == true) {   // check if QC string is valid
        for (int i = 0; i < results.length(); i++) {
            char character = results.at(i);
            if (character == 'd') {     // iterate through the string to find 'd' indicating defect
                didPass = true;
            } else if (character == 'Q' || character == 'p'){
                didPass = false;
                defectTotal += tempTotal;   // add the total of previous tests from the tempTotal to defectTotal
                tempTotal = 0;
            } else if (didPass){
                int num = character - '0';
                tempTotal = (tempTotal * 10) + num;     // account for multi-digits
            }
        }
        defectTotal += tempTotal;           // add the final total to defectTotal
    } else {
        return -1;
    }
    return defectTotal;
}
// returns the amount of total tests in the string
int totalQC(string results) {
    int testTotal = 0;
    int tempTotal = 0;
    bool didPass = false;
    
    if (isValidQC(results) == true) {
        for (int i = 0; i < results.length(); i++) {
            char character = results.at(i);
            if (character == 'Q') {     // check if test is 'Q'
                didPass = true;
            } else if (character == 'p' || character == 'd'){
                didPass = false;
                testTotal += tempTotal;     // add the total of previous tests from the tempTotal to testTotal
                tempTotal = 0;
            } else if (didPass){
                int num = character - '0';
                tempTotal = (tempTotal * 10) + num;
            }
        }
        testTotal += tempTotal;     // add the final total to testTotal
    } else {
        return -1;
    }
    return testTotal;
}
// returns the amount of batches ('Q's) in the string
int batches(string results) {
    int batchTotal = 0;
    if (isValidQC(results) == true) {
        for (int i = 0; i < results.length(); i++) {    // iterate through the string to find the number of 'Q's
            char character = results.at(i);
            if (character == 'Q') {
                batchTotal++;                           // will increment each time it finds a 'Q'
            }
        }
    } else {
        return -1;
    }
    return batchTotal;
 }
