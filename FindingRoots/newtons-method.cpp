/*
    Code to find the roots of a polynomial using Newton's method.
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

// Function to check the sufficent condition for the convergence of Newton's method
// | f(x). f''(x) | <= | f'(x) |^2
bool checkSufficientCondition(double x0) {
    // Calculate the value of f(x0), f'(x0) and f''(x0)
    double f_x0 = f(x0),
        f_prime_x0 = f_prime(x0),
        f_double_prime_x0 = f_double_prime(x0);

    // Calculate the value of | f(x). f''(x) | and | f'(x) |^2
    double lhs = fabs(f_x0 * f_double_prime_x0), rhs = f_prime_x0 * f_prime_x0;

    // Check if the sufficient condition is met
    if (lhs > rhs) {
        std::cout << "Sufficient condition not met" << std::endl;
        return false;
    }

    return true;
}



// Function to find the root of the polynomial using Newton's method
double newtonsMethod(double x0, double tol) {
    // Absolute Error = | (current approximation - previous approximation) / current approximation | * 100

    // Check if the sufficient condition is met
    if (!checkSufficientCondition(x0)) {
        return 0;
    }

    // Initialize the current approximation
    double current_approx = x0;
    // Initialize the Previous Approximation
    double prev_approx = x0;
    // Initialise the absolute error
    double abs_error = 100;

    // Loop until the absolute error is less than the tolerance
    // Absolute Error = | (curren_approx - prev_approx) / current_approx | * 100
    // Stopping Criteria: Absolute Error < Tolerance
    for (int i = 1; abs_error > tol; i++) {
        // Calculate the current approximation using Newton's method

        // Calculate the derivative of the function at the current approximation
        double f_prime_x = f_prime(current_approx);

        // Check if the derivative is zero
        if (f_prime_x == 0) {
            std::cout << "Division by zero error" << std::endl;
            return 0;
        }

        // Calculate the current approximation
        current_approx = current_approx - (f(current_approx) / f_prime_x);

        // Calculate the absolute error
        abs_error = fabs((current_approx - prev_approx) / current_approx) * 100;

        // Update the previous approximation
        prev_approx = current_approx;

        // Print iteration number, current approximation and the absolute error
        std::cout << "Iteration: " << i << ", Current Approximation: " << current_approx << ", Absolute Error: " << abs_error << std::endl;
    }

    // return the root after the stopping criteria is met
    return current_approx;
}

// Main function
int main() {
    // Define the initial value and tolerance
    double x0 = 2, tol = 0.01;

    // Call the Newton's method function to find the root
    double root = newtonsMethod(x0, tol);

    // Print the root of the polynomial
    std::cout << "Root of the polynomial: " << root << std::endl;

    return 0;
}
