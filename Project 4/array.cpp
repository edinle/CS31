// Edin Le
// Project 4: array.cpp

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;

int locateMaximum(const string array[], int n);
int countFloatingPointValues(const string array[], int n);
bool hasNoCapitals(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholder);

int main()
{
    string multipleMaxArray[] = {"apple", "banana", "banana", "apple", "banana"};
    cout << locateMaximum(multipleMaxArray, 5) << endl;
    // Expected result: 1 (smallest index with the maximum value "banana")
    
    return 0;
}

int locateMaximum(const string array[], int n) {
    /*
     Return the index of the largest item found in the passed array or -1 if n <= 0. For
     example, for the array data[ 5 ] shown above, locateMaximum( data,
     5 ) should return the value 4, corresponding to the index of "tyrion". If there
     are multiple duplicate maximum values, return the smallest index that has this
     maximum value. The maximum value should be determined by its dictionary-sorted
     order which is what < and > use in C++ to determine true and false.
     */
    
    
    if (n <= 0) {   // return -1 if n <= 0
        return -1;
    }
    
    int maxItem = 0;
    
    for (int i = 0; i < n; i++) {            // loop through the array 'n' times
        if (array[i] > array[maxItem]) {     // if the size of the element in the index is greater than the largest item found so far
            maxItem = i;                     // maxItem will equal the index
        }
    }
    return maxItem;
}

int countFloatingPointValues(const string array[], int n) {
    
    /*
     Return the number of numerical floating point values found in the passed array or - 1 if n <= 0.
     For this operation, floating point values are numerical values that optionally include a single decimal point.
     They should not start with a leading + or - or include commas - only digits and an optional decimal point.
     For example, for the array data[ 5 ] shown above, countFloatingPointValues( data, 5 ) should return 1.
     For the array folks[ 8 ] shown above, countFloatingPointValues( folks, 1 ) should return 0 because
     the first element is not a floating point value.
     */
    
    if (n <= 0) {
        return -1;
    }
    
    int floatingPointCount = 0;
    
    for (int i = 0; i < n; i++) {                      // loop the array 'n' times
        bool isFloat = true;                           // assume string is a "float" without a decimal point and test it
        bool hasDecimalPoint = false;
        bool hasDigit = false;
        
        for (int j = 0; j < array[i].size(); j++) {    // loop through the string elements in each index of the array
            char charInString = array[i][j];           // check each char in the string
            
            if (!isdigit(charInString) && charInString != '.') {    // if the char is not a digit & not a decimal point
                isFloat = false;                                    // return isFloat as false
            } else if (charInString == '.' && !hasDecimalPoint) {   // if the char is a point and string does not already have decimal point
                hasDecimalPoint = true;                             // hasDecimalPoint will be true
            } else if (charInString == '.' && hasDecimalPoint) {    // if finds another decimal in addition to the one already in string
                isFloat = false;                                    // isFloat will be false because cannot have 2 decimal points
            } else if (isdigit(charInString)) {                     // check to make sure there are digits in the string
                hasDigit = true;
            }
        }
        if (isFloat && hasDigit) {      // if each string element is a "float" (has digits w/ or w/out decimal), the count will increment
            floatingPointCount++;
        }
    }
    return floatingPointCount;
}

bool hasNoCapitals(const string array[], int n) {
    
    /*
     If all the elements in the passed array include not a single CAPITAL letter (that is,
     the letters A-Z), return true otherwise false. If n <= 0, return true since
     indeed there are no elements with a single CAPITAL letter. For example, for the
     array data[ 5 ] shown above, hasNoCapitals( data, 5 ) should
     return false because of the value "mamaBbcc!". For example, for the
     array folks[ 8 ] shown above, hasNoCapitals( folks, 8 ) should
     return true.
     */
    
    if (n <= 0) {
        return true;
    }
    
    for (int i = 0; i < n; i++) {                       // loop through array
        for (int j = 0; j < array[i].size(); j++) {     // loop through each string element in each index of the array
            char charInString = array[i][j];            // check each char in the string
            if (isupper(charInString) == true) {        // if it finds an uppercase char in the string, return false
                return false;
            }
        }
    }
    return true;
}

int shiftLeft(string array[], int n, int amount, string placeholder) {
    
    /*
     For the passed array, shift all of its elements left by amount, filling in the right-most
     values with the placeholder value and return the number of times
     the placeholder value was used or return -1 if n <= 0 or amount < 0. For
     example, for the array data[ 5 ] shown above, shiftLeft( data, 5, 2,
     "foo" ) should return 2 and adjust the array data to { "12,", "98.76",
     "tyrion", "foo", "foo" }. For example, for the array data[ 5 ] shown
     above, shiftLeft( data, 5, 10, "bar" ) should return 5 and adjust the
     array data to { "bar", "bar", "bar", "bar",
     "bar" }. shiftLeft( data, -5, 10, "foobar" ) should return -1 and not
     change any of the array data. Similarly, shiftLeft( data, 5, -5,
     "foobar" ) should return -1 and not change any of the array data.
     */
    
    if (n <= 0 || amount < 0) {     // return -1 if n <= 0 or amount < 0
        return -1;
    }
    
    int placeholderCount = 0;
    
    for (int i = 0; i < n; i++) {               // looping through the array 'n' times
        if (i + amount < n) {                   // if shifting the array by amount is less than the n
            array[i] = array[i + amount];       // the array's contents will be shifted left by the amount
        } else {                                // if the shift is greater than the bounds of array
            array[i] = placeholder;             // the array will place the placeholder into the indicies
            placeholderCount++;                 // increment the placeholderCount to return it
        }
    }
    return placeholderCount;
}
