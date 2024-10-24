#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(const std::vector<int>& set, int targetSum) {
    int n = set.size();
    // Create a DP table, dp[i][j] will be true if there is a subset of set[0..i-1] with sum j
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    // If sum is 0, then answer is true (we can always form sum 0 with an empty subset)
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            // If we do not take the current element
            dp[i][j] = dp[i - 1][j];

            // If we take the current element
            if (j >= set[i - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j - set[i - 1]];
        }
    }

    // The answer will be in dp[n][targetSum]
    return dp[n][targetSum];
}

int main() {
    std::vector<int> set = { 1, 2, 3 };
    int targetSum = 5;
    if (isSubsetSum(set, targetSum))
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}

/* Explanation:
   - We loop through each element in the set.
   - Then we loop through each possible sum from 1 to targetSum.
   - If we do not take the current element set[i-1], dp[i][j] = dp[i-1][j].
   - If we take the current element, we need to check if dp[i-1][j-set[i-1]] is true.
   - dp[i][j] is set to true if either excluding or including the current element forms the target sum.
*/
