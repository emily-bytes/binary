// Name: Emily Lee
// Filename: hw1.cpp
// Date: 1/6/2022
// v 1.0
// Purpose: This program converts a decimal to a binary notation using the division/remainder method.

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Function:    padBits
// Purpose:     Adds zeros to binary notation
// Parameters:  iteration, number of zeros needed, binary vector
void padBits(int i, int numZeros, vector<int> &binary, int decimal);

// Function:    printBinary
// Purpose:     displays binary notation
// Parameters:  user input, binary vector
void printBinary(int decimal, vector<int> &binary);

// Displays goodbye message
void goodbyeMessage();

// Displays welcome message
void welcomeMessage();

int main() {
    // Declare variables
    long unsigned int decimal;    // user input to hold decimal number
    long unsigned int num;    // to hold decimal number
    int r;  // remainder, 1 or 0
    int numZeros = 0; // number of zeros needed 
    int i = 0;  // initialize iteration to zero
    const int MIN = 0;  // min input
    const int MAX = 2000000000; // max input

    welcomeMessage();

    // Prompt user for a positive decimal number, assuming user will only enter a whole integer below 2 billion
    do {
        cout << "Enter a positive decimal number: ";
        cin >> decimal;
    } while (decimal < MIN || decimal > MAX);  // validate number is positive and below 2 billion

    // Create vector to store binary notation
    vector<int> binary;

    // Initiate num to user input
    num = decimal;

    // Divide num by two until num equals 0
    // if num divided by 2 results in no remainder, store 0 in binary vector
    // else, store 1 in binary vector
    do {
        if (num % 2 == 0)
            r = 0;
        else
            r = 1;
        binary.push_back(r);    // store remainder in binary vector
        cout << "r = " << r << "; ";

        num = num/2;
        cout << "num = " << num << endl;
        i++;    // increase iteration every time a number is divided by two
    } while (num != 0);
//    cout << "iteration " << i << endl;

    // Pad the bits to the left with zeroes
    padBits(i, numZeros, binary, decimal);

    // Display binary notation
    printBinary(decimal, binary);

    // Display goodbye message
    goodbyeMessage();
}

void padBits(int i, int numZeros, vector<int> &binary, int decimal) {
    // define variables
    int bits = 0;   // initialize bits to zero
    int max = 8; // 8 groups of four bits

    for (int j = 0; j < max - 1; j++) {
        int base = pow(16, j);
        if (decimal < base && bits == 0) {
            bits = 4 * j;
        }
    }
    numZeros = bits - i;  // number of zeros needed to complete binary notation

    if (numZeros != 0)
    for (int j = 0; j < numZeros; j++) {
        binary.push_back(0);
    }
}

void printBinary(int decimal, vector<int> &binary) {
    // organize the remainder bits into the binary integer
    reverse(binary.begin(), binary.end());

    cout << "\n" << decimal << " = "; 
    for (long unsigned int j = 0; j < binary.size(); j++) {
      cout << binary[j];
      if (j % 4 == 3) // print space after every four bits for readability
        cout << " "; 
    }
    cout << "in binary"; 
}

void welcomeMessage() {
    cout << "\nWelcome! This program converts a positive number from decimal to binary notation.\n\n";
}

void goodbyeMessage() {
    cout << "\n\nThanks for using the decimal to binary conversion program. \nGoodbye!\n";
}


