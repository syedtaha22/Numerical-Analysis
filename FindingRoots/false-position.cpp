/*
    Code to find the roots of a polynomial using the false position method.
*/

#include <iostream>
#include <cmath>

// Define the polynomial function f(x) = x^3 - 2x - 5
// Change this function to the desired polynomial
double f(double x) {
    return (x * x * x) - (2 * x) - 5;
}

// Function to find the root of the polynomial using the false position method
double falsePositionMethod(double a, double b, double tol) {
    // Absolute Error = | (current approximation - previous approximation) / current approximation | * 100

    // Check if the initial values are correct
    if (f(a) * f(b) >= 0) {
        std::cout << "Incorrect initial values" << std::endl;
        return 0;
    }

    // Initialize the current approximation
    double current_approx = a;
    // Initialize the Previous Approximation
    double prev_approx = a;
    // Initialise the absolute error
    double abs_error = 100;

    // Loop until the absolute error is less than the tolerance
    // Absolute Error = | (curren_approx - prev_approx) / current_approx | * 100
    // Stopping Criteria: Absolute Error < Tolerance
    for (int i = 1; abs_error > tol; i++) {
        // Calculate the current approximation using the false position formula

        // Calculate f(a) and f(b)
        double fa = f(a), fb = f(b);
        // Calculate the denominator of the formula
        double denominator = fb - fa;

        // Check if the denominator is zero
        if (denominator == 0) {
            std::cout << "Division by zero error" << std::endl;
            return 0;
        }

        // Calculate the current approximation
        current_approx = a - (fa * (b - a) / denominator);

        // Check if the current approximation is the root
        if (f(current_approx) == 0) break;

        // Check if the root lies in the left half
        // If f(c) and f(a) have opposite signs, the root lies in the left half
        // Update the right boundary (b) to the current approximation
        if (f(current_approx) * f(a) < 0) b = current_approx;
        // Else the root lies in the right half
        // Update the left boundary (a) to the current approximation
        else a = current_approx;

        // Calculate the absolute error
        abs_error = fabs((current_approx - prev_approx) / current_approx) * 100;

        // Print iteration number, current approximation and the absolute error
        std::cout << "Iteration: " << i << ", Current Approximation: " << current_approx << ", Absolute Error: " << fabs((current_approx - prev_approx) / current_approx) * 100 << std::endl;

        // Update the previous approximation
        prev_approx = current_approx;
    }

    // return the current approximation after the stopping criteria is met
    return current_approx;
}

// Main function to test the false position method
int main() {
    // Define the initial values and tolerance
    double a = 0, b = 3, tol = 0.01;

    // Call the false position method to find the root
    double root = falsePositionMethod(a, b, tol);

    // Print the final root
    std::cout << "Root: " << root << std::endl;

    return 0;
}