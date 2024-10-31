#include <iostream>
#include <vector>
#include <climits>

int matrixChainOrder(const std::vector<int>& p) {
    int n = p.size() - 1;  // Number of matrices
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));

    // Filling the table in a bottom-up manner
    for (int length = 2; length <= n; ++length) {  // length is the chain length
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                // Calculate cost of splitting the chain at k
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;  // Update minimum cost for multiplying matrices from A_i to A_j
                }
            }
        }
    }

    return m[0][n - 1];  // Minimum cost to multiply matrices from A1 to An
}

int dnkdjd() {
    std::vector<int> p = { 3, 2, 4};  // Dimensions for matrices A1 (10x30), A2 (30x5), A3 (5x60)
    int minCost = matrixChainOrder(p);
    std::cout << "Minimum number of multiplications is " << minCost << std::endl;
    return 0;
}
