/**
 *     Title: Recursive vs Iterative - main.cpp
 *     Purpose: Program to determine the performance of two power functions implementations empirically
 *     Class: CSC 3430 Algorithm Design and Analysis- Winter 2023
 *     Author: Kaddijatou Baldeh
 */

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using std::ofstream;
using std::cerr;
using std::endl;
using std::cout;

// Declaration of the power functions
double iterativePower(double base, int exponent);
double recursivePower(double base, int exponent);

// Main function mimics a call stack
int main() {
    //to compute the power
    double powerI,  powerR;

    //open file
    ofstream out;
    out.open("result.csv");
    // Check if file open fails, then print error message and return -1
    if (!out.is_open()) {
        cerr << "Error: the file could not be opened.";
        return -1;
    }
    // Write the fields header
    out << "n, iterative-time, recursive-time" << endl;
    // Set the base to pi = 3.14159265359
    double pi = 3.14159265359;

    // Iterate n = 60000 times
    int n = 60000;

    for (int i = 1; i <= n; i++) {
        // Start timer iterative
        time_point<high_resolution_clock> startI = high_resolution_clock::now();

        // Call the iterative function
        powerI = iterativePower(pi,i);

        // End timer and compute the difference
        time_point<high_resolution_clock> endI = high_resolution_clock::now();
        auto iterativeTime = duration_cast<nanoseconds>(endI - startI).count();

        // Start timer for recursive
        time_point<high_resolution_clock> startR = high_resolution_clock::now();

        // call the iterative function
        powerR = iterativePower(pi,i);

        //end timer and compute the difference
        time_point<high_resolution_clock> endR = high_resolution_clock::now();
        auto recursiveTime =  duration_cast<nanoseconds>(endR - startR).count();

        // Output info on file
        out << i << "," << iterativeTime <<","<< recursiveTime << endl;

    }
    cout << "CSV file successfully created." << endl << endl;
    out.close();
    cout << "Final power: " << powerI << " " << powerR << endl;
    return 0;

}
// Iterative power implementation
double iterativePower(double base, int exponent){
    double retVal = 1.0;
    if (exponent < 0){
        return 1.0 / iterativePower(base, -exponent);
    }else{
        for (int i=0; i<exponent; i++)
            retVal *= base;
    }
    return retVal;
}
// Recursive power implementation
double recursivePower(double base, int exponent){
    if (exponent < 0){
        return 1.0 / recursivePower(base, -exponent);
    }else if (exponent == 0){
        return 1.0;
    }else {
        return base * recursivePower(base, exponent - 1);
    }
}