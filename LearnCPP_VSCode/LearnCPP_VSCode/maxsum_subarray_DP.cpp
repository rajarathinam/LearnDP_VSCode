#include <iostream>
#include <vector>
#include <algorithm> // For std::max

void maxSubArraySum(const std::vector<int>& nums) {
    // Step 2: Initialize variables
    int current_sum = 0;
    int max_sum = nums[0]; // Start with the first element (in case all are negative)
    int start = 0, end = 0; // To store the indices of the maximum subarray
    int temp_start = 0; // Temporary start index for the current subarray

    // Step 3: Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i]; // Add current element to current_sum

        // Check if we need to reset current_sum
        if (current_sum < 0) {
            current_sum = 0; // Reset current_sum to 0
            temp_start = i + 1; // Move the temporary start to the next index
        }

        // Update max_sum and the indices if we found a new maximum
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start; // Update the starting index
            end = i; // Update the ending index
        }
    }

    // Print the maximum sum
    std::cout << "Maximum Subarray Sum = " << max_sum << std::endl;

    // Print the subarray
    std::cout << "Subarray: [";
    for (int i = start; i <= end; i++) {
        std::cout << nums[i];
        if (i < end) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int vhivdsnkds () {
    std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; // Example input
    maxSubArraySum(nums);
    return 0;
}
