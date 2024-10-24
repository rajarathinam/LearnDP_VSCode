#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::pair<int, std::set<std::string>> longestCommonSubstrings(const std::string& s1, const std::string& s2) {
    int n = s1.size();
    int m = s2.size();

    // DP table to store the lengths of longest common suffixes
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    int maxLength = 0;  // To store the maximum length of common substring
    std::set<std::string> substrings;  // To store all longest common substrings

    // Build the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // Check if this is the longest common substring so far
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    substrings.clear();  // Clear previous substrings
                    substrings.insert(s1.substr(i - maxLength, maxLength));  // Add new longest substring
                }
                else if (dp[i][j] == maxLength) {
                    substrings.insert(s1.substr(i - maxLength, maxLength));  // Add other substrings of the same length
                }
            }
            else {
                dp[i][j] = 0;  // No match, reset to 0
            }
        }
    }

    return { maxLength, substrings };
}

int smlsmls() {
    // Example strings
    std::string s1 = "abcdxyz";
    std::string s2 = "xyzabcd";

    // Find the length and all longest common substrings
    auto result = longestCommonSubstrings(s1, s2);

    // Output the result
    std::cout << "Length of Longest Common Substring: " << result.first << std::endl;
    std::cout << "All Longest Common Substrings: " << std::endl;

    for (const auto& substr : result.second) {
        std::cout << substr << std::endl;
    }

    return 0;
}
