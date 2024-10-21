#include <iostream>
#include <vector>
using namespace std;

// Function to compute the nth Fibonacci number using the bottom-up approach with tabulation
int fib(int n)
{
    // Create a vector to store Fibonacci numbers from F(0) to F(n)
    vector<int> fibTable(n + 1);

    // Initialize base cases
    fibTable[0] = 0;  // F(0) = 0
    fibTable[1] = 1;  // F(1) = 1

    // Iteratively fill the table for F(2) to F(n)
    for (int i = 2; i <= n; ++i) {
        fibTable[i] = fibTable[i - 1] + fibTable[i - 2];  // F(i) = F(i-1) + F(i-2)
    }

    // Return the nth Fibonacci number
    return fibTable[n];
}

int ww() {
    int n = 5;


    // Compute and print the nth Fibonacci number
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;

    return 0;
}
