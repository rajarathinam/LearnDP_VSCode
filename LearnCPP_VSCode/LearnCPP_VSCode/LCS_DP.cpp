#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to find the Longest Common Subsequence
std::string longestCommonSubsequence(const std::string& s1, const std::string& s2) {
    int n = static_cast<int>(s1.size());
    int m = static_cast<int>(s2.size());

    // Create a DP table to store lengths of LCS for different subproblems
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    // Build the DP table in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);  // No match, take the max
            }
        }
    }

    // The length of the LCS is in dp[n][m]
    int lengthOfLCS = dp[n][m];

    // Trace back to find the actual LCS string
    std::string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);  // Character is part of LCS
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    // Reverse the string because we traced back
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

int vfdsds() {
    // Example Input
    std::string s1 = "ABCBDAB";
    std::string s2 = "BDCAB";

    // Find LCS
    std::string lcs = longestCommonSubsequence(s1, s2);

    // Output the result
    std::cout << "Longest Common Subsequence: " << lcs << "\n";
    std::cout << "Length of LCS: " << lcs.length() << "\n";

    return 0;
}
