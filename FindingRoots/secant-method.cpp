/*
    Code to find the roots of a polynomial using the secant method.
*/

#include <iostream>
#include <cmath>

// Define the polynomial function f(x) = x^3 - 2x - 5
// Change this function to the desired polynomial
double f(double x) {
    return (x * x * x) - (2 * x) - 5;
}

// Define the derivative of the polynomial function f'(x) = 3x^2 - 2
// Change this function to the derivative of the desired polynomial
double f_prime(double x) {
    return (3 * x * x) - 2;
}

// Define the second derivative of the polynomial function f''(x) = 6x
// Change this function to the second derivative of the desired polynomial
double f_double_prime(double x) {
    return 6 * x;
}

// Function to Check the Sufficent condition for the convergence of the secant method
bool checkSufficientCondition(double x0, double x1) {
    // Check if the function values at the initial approximations have the same sign
    if (f(x0) * f(x1) > 0) {
        std::cout << "Sufficient condition not met" << std::endl;
        return false;
    }

    // Check if the function values at the initial approximations have the same sign
    if (f_double_prime(x0) * f_double_prime(x1) < 0) {
        std::cout << "Sufficient condition not met" << std::endl;
        return false;
    }

    return true;
}


// Function to find the root of the polynomial using the secant method
double secantMethod(double x0, double x1, double tol) {
    // Absolute Error = | (current approximation - previous approximation) / current approximation | * 100

    // Check if the sufficient condition is met
    if (!checkSufficientCondition(x0, x1)) {
        return 0;
    }

    // Initialize the current approximation
    double current_approx = x1;
    // Initialize the Previous Approximation
    double prev_approx = x0;
    // Initialise the absolute error
    double abs_error = 100;

    // Loop until the absolute error is less than the tolerance
    // Absolute Error = | (curren_approx - prev_approx) / current_approx | * 100
    // Stopping Criteria: Absolute Error < Tolerance
    for (int i = 1; abs_error > tol; i++) {
        // Calculate the current approximation using the secant method

        // Calculate the function values at the previous approximations
        double f_prev = f(prev_approx), f_current = f(current_approx);

        // Calculate the current approximation
        // Xn+2 = Xn+1 - f(Xn+1) * (Xn+1 - Xn) / (f(Xn+1) - f(Xn))

        // Calculate the denominator of the formula
        double denominator = f_current - f_prev;

        // Check if the denominator is zero
        if (denominator == 0) {
            std::cout << "Division by zero error" << std::endl;
            return 0;
        }

        // Calculate the current approximation
        double new_approx = current_approx - (f_current * (current_approx - prev_approx) / denominator);

        // Update the previous approximation to the current approximation
        prev_approx = current_approx;
        // Update the current approximation to the new approximation
        current_approx = new_approx;

        // Calculate the absolute error
        abs_error = fabs((current_approx - prev_approx) / current_approx) * 100;

        // Print iteration number, current approximation and the absolute error
        std::cout << "Iteration: " << i << ", Current Approximation: " << current_approx << ", Absolute Error: " << abs_error << std::endl;
    }

    // return the root after the stopping criteria is met
    return current_approx;
}

int main() {
    // Define the initial values and tolerance
    double x0 = 2, x1 = 3, tol = 0.01;

    // Call the secant method function with the initial values and tolerance
    double root = secantMethod(x0, x1, tol);

    // Print the root of the polynomial
    std::cout << "Root of the polynomial: " << root << std::endl;

    return 0;
}