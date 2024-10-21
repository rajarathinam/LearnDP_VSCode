#include <iostream>
#include <vector>
#include <algorithm> // for std::max

// Function to solve the 0/1 Knapsack Problem
int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values, int numberOfItems) {
    // Create a DP table where dp[i][w] represents the maximum value with i items and capacity w
    std::vector<std::vector<int>> dp(numberOfItems + 1, std::vector<int>(capacity + 1, 0));

    // Build the DP table iteratively
    for (int i = 1; i <= numberOfItems; ++i) {
        for (int currentCapacity = 0; currentCapacity <= capacity; ++currentCapacity) {
            if (weights[i - 1] <= currentCapacity) {
                // Include the item: value = item_value + best value for remaining capacity
                dp[i][currentCapacity] = std::max(dp[i - 1][currentCapacity],
                    values[i - 1] + dp[i - 1][currentCapacity - weights[i - 1]]);
            }
            else {
                // Exclude the item
                dp[i][currentCapacity] = dp[i - 1][currentCapacity];
            }
        }
    }

    // Return the maximum value for all items and the given capacity
    return dp[numberOfItems][capacity];
}

int fff() 
{
    // Define the knapsack capacity
    int capacity = 7;

    // Define the weights and values of the items
    std::vector<int> weights = { 1,3,4, 5}; // Weights of items
    std::vector<int> values = { 1, 4, 5, 7};  // Values of items

    // Number of items
    int numberOfItems = weights.size();

    // Solve the knapsack problem and get the maximum value
    int maxKnapsackValue = knapsack(capacity, weights, values, numberOfItems);

    // Print the result
    std::cout << "The maximum value that can be obtained is: " << maxKnapsackValue << std::endl;

    return 0;
}
