/*
    Code to find the roots of a polynomial using the bisection method.
*/

#include <iostream>
#include <cmath>

// Define the polynomial function f(x) = x^3 - 2x - 5
// Change this function to the desired polynomial
double f(double x) {
    return (x * x * x) - (2 * x) - 5;
}

// Function to find the root of the polynomial using the bisection method
double bisectionMethod(double a, double b, double tol) {
    // Absolute Error = | (current approximation - previous approximation) / current approximation | * 100

    // Check if the initial values are correct
    if (f(a) * f(b) >= 0) {
        std::cout << "Incorrect initial values" << std::endl;
        return 0;
    }

    // Initialize the midpoint
    double c = 0;

    // Loop until the absolute error is less than the tolerance
    // Absolute Error = | (current approximation - previous approximation) / current approximation | * 100
    // Stopping Criteria: Absolute Error < Tolerance
    std::cout << "Absolute Error: " << fabs((b - a) / b) * 100 << std::endl;


    for (int i = 1; fabs((b - a) / b) * 100 > tol; i++) {
        // Calculate the midpoint
        c = (a + b) / 2;

        // Check if the midpoint is the root
        if (f(c) == 0) break;

        // Check if the root lies in the left half
        // If f(c) and f(a) have opposite signs, the root lies in the left half
        // Update the right boundary (b) to the midpoint
        if (f(c) * f(a) < 0) b = c;
        // Else the root lies in the right half
        // Update the left boundary (a) to the midpoint
        else a = c;

        // Print iteration number, current approximation and the absolute error
        std::cout << "Iteration: " << i << ", Current Approximation: " << c << ", Absolute Error: " << fabs((b - a) / b) * 100 << std::endl;

    }

    // return the root after the stopping criteria is met
    return c;
}

int main() {
    // Define the initial values and tolerance
    double a = 2, b = 3, tol = 0.01;

    // Call the bisection method function to find the root
    double root = bisectionMethod(a, b, tol);

    // Print the root
    std::cout << "Root of the polynomial: " << root << std::endl;

    return 0;
}