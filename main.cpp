/**
 *     Title: Recursive vs Iterative - main.cpp
 *     Purpose: Program to determine the performance of two power functions implementations empirically
 *     Class: CSC 3430 Algorithm Design and Analysis- Winter 2023
 *     Author: Kaddijatou Baldeh
 */

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

double iterativePower(double base, int exponent);
double recursivePower(double base, int exponent);

int main() {
    // For timing functions
    chrono::time_point<chrono::steady_clock> start;
    chrono::time_point<chrono::steady_clock> end;

    //to compute the power
    double powerI,  powerR;

    ofstream out;
    out.open("result.csv");
    // Check if file open fails, then print error message and return -1
    if (!out.is_open()) {
        cerr << "Error: the file could not be opened.";
        return -1;
    }
    // Write the fields header
    out << "n, iterative-time, recursive-time" << endl;
    // Set the base to 3.14159265359
    double base = 3.14159265359;

    // iterate n = 5000 times
    int n = 10000;

    for (int i = 0; i < n; i++) {
        //start timer iterative
        start = chrono::steady_clock::now();
        // call the iterative function
        powerI = iterativePower(base,i);
        //end timer and compute the difference
        end = chrono::steady_clock::now();
        auto iterativeTime = end - start;

        //start timer for recursive
        start = chrono::steady_clock::now();
        // call the iterative function
        powerR = iterativePower(base,i);
        //end timer and compute the difference
        end = chrono::steady_clock::now();

        auto recursiveTime = end - start;

        out << i << "," << iterativeTime.count() <<","<< recursiveTime.count() << endl;

    }

    cout << "Final  power: " << powerI << " " << powerR << endl;
    return 0;

}
// Iterative implementation
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
// Recursive implementation
double recursivePower(double base, int exponent){
    if (exponent < 0){
        return 1.0 / recursivePower(base, -exponent);
    }else if (exponent == 0){
        return 1.0;
    }else {
        return base * recursivePower(base, exponent - 1);
    }
}