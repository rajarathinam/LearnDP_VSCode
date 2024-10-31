#include <iostream>
#include <vector>
#include <limits.h>

int minJumps(const std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0; // Already at the end
    if (arr[0] == 0) return -1; // Can't make any move
    int jumps = 0;
    int current_end = 0; // The end of the range that we can reach with current jumps
    int farthest = 0;    // The farthest we can reach with the next jump

    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest point we can reach from the current index
        farthest = std::max(farthest, i + arr[i]);
        // If we have reached the end of the range for the current jump
        if (i == current_end) {
            jumps++;
            current_end = farthest; // Extend the range
            // If the end of the array is within reach, break
            if (current_end >= n - 1) break;
        }
    }
    return current_end >= n - 1 ? jumps : -1; // If end is unreachable, return -1
}

int jsdsjle() {
    std::vector<int> arr = { 1, 2, 3 };
    int result = minJumps(arr);
    if (result != -1)
        std::cout << "Minimum jumps needed: " << result << std::endl;
    else
        std::cout << "End is unreachable." << std::endl;
    return 0;
}
