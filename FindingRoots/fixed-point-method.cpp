/*
    Code to find the roots of a polynomial using the fixed point method.
*/

#include <iostream>
#include <cmath>

// Define the polynomial function f(x) = x^3 - 2x - 5
// Change this function to the desired polynomial
double f(double x) {
    return (x * x * x) - (2 * x) - 5;
}

/*
    Transform the polynomial function f(x) = x^3 - 2x - 5 into the form x = g(x)
    Make sure that the function g(x) satisfies the conditions for the fixed point method to converge

        f(x) = x^3 - 2x - 5

    =>  x^3 - 2x - 5 = 0
    =>  x^3          = 2x + 5
    =>  x            = cbrt(2x + 5)
*/

// Define the fixed point function g(x) = cbrt(2x + 5)
// Change this function to the desired fixed point function
double g(double x) {
    return std::cbrt(2 * x + 5);  // Cube root of (2x + 5)
}

// Define the derivative of the fixed point function g'(x) = 1 / (3 * sqrt(2x + 5))
// Change this function to the derivative of the desired fixed point function
double g_prime(double x) {
    return 1 / (3 * std::sqrt(2 * x + 5));  // 1 / (3 * square root of (2x + 5))
}

// Suffucient condition for the convergence of the fixed point method
// | g'(x) | < 1
bool checkSufficientCondition(double x0) {
    // Calculate the value of g'(x0)
    double g_prime_x0 = g_prime(x0);

    // Check if the sufficient condition is met
    if (fabs(g_prime_x0) >= 1) {
        std::cout << "Sufficient condition not met" << std::endl;
        return false;
    }

    return true;
}



// Function to find the root of the polynomial using the fixed point method
double fixedPointMethod(double x0, double tol) {
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
    // Absolute Error = | (current approximation - previous approximation) / current approximation | * 100
    // Stopping Criteria: Absolute Error < Tolerance
    for (int i = 1; abs_error > tol; i++) {
        // Calculate the current approximation using the fixed point formula
        current_approx = g(prev_approx);

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

int main() {
    // Define the initial value and tolerance
    double x0 = 2, tol = 0.01;


    // Call the fixed point method function to find the root
    double root = fixedPointMethod(x0, tol);


    // Print the root of the polynomial
    std::cout << "Root of the polynomial: " << root << std::endl;

    return 0;
}