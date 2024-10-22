#include <iostream>
#include <vector>

// Dynamic Programming (Bottom-Up) Approach with O(n) space
int climbStairs(int n) {
    if (n <= 1) {
        return 1; // If there are 0 or 1 steps, there's only one way to climb.
    }

    // Create a DP table to store the number of ways to reach each step.
    std::vector<int> dp(n + 1);

    // Base cases
    dp[0] = 1; // 1 way to "stay" at the ground (step 0)
    dp[1] = 1; // 1 way to reach the first step

    // Fill the DP table using the recurrence relation f(n) = f(n-1) + f(n-2)
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // The number of ways to reach the nth step is stored in dp[n].
    return dp[n];
}

// Optimized Space Approach with O(1) space
int climbStairsOptimized(int n) {
    if (n <= 1) {
        return 1; // If there are 0 or 1 steps, there's only one way to climb.
    }

    // Keep track of the two previous results
    int prev1 = 1, prev2 = 1;

    // Iterate through steps starting from 2 up to n
    for (int i = 2; i <= n; ++i) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    // The final result is stored in prev1
    return prev1;
}

int shjdnkds() {
    int n;

    // Input the number of steps
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    // Call both functions and print their results
    std::cout << "Number of ways to climb " << n << " stairs (DP approach): " << climbStairs(n) << std::endl;
    std::cout << "Number of ways to climb " << n << " stairs (Optimized approach): " << climbStairsOptimized(n) << std::endl;

    return 0;
}
