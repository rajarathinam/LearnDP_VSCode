#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::pair<int, std::string> longestCommonSubstring(const std::string& s1, const std::string& s2) {
    int n = s1.size();
    int m = s2.size();

    // DP table to store the lengths of longest common suffixes
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    int maxLength = 0;  // To store the maximum length of common substring
    int endIndex = 0;   // To store the ending index of the longest common substring in s1

    // Build the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // Check if this is the longest common substring so far
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;  // Update the end index of the longest substring
                }
            }
            else {
                dp[i][j] = 0;  // No match, reset to 0
            }
        }
    }

    // Extract the longest common substring
    std::string longestSubstring = s1.substr(endIndex - maxLength, maxLength);

    return { maxLength, longestSubstring };
}

int main() {
    // Example strings
    std::string s1 = "abcdxyz";
    std::string s2 = "xyzabcd";

    // Find the length and the actual longest common substring
    auto result = longestCommonSubstring(s1, s2);

    // Output the result
    std::cout << "Length of Longest Common Substring: " << result.first << std::endl;
    std::cout << "Longest Common Substring: " << result.second << std::endl;

    return 0;
}
