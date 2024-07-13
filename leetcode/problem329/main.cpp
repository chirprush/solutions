#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

typedef long long ll;

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>> &matrix) {
        std::vector<std::pair<int, int>> indices;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                indices.push_back(std::make_pair(i, j));
            }
        }
        
        std::sort(indices.begin(), indices.end(), [&matrix](const std::pair<int, int> &left, const std::pair<int, int> &right) { return matrix[right.first][right.second] < matrix[left.first][left.second]; });
        
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        
        for (int i = 0; i < indices.size(); i++) {
            int r = indices[i].first;
            int c = indices[i].second;

            int value = 0;
            
            if (r > 0 && matrix[r-1][c] > matrix[r][c]) {
                value = std::max(value, dp[r-1][c]);
            }

            if (c > 0 && matrix[r][c-1] > matrix[r][c]) {
                value = std::max(value, dp[r][c-1]);
            }

            if (r < m - 1 && matrix[r+1][c] > matrix[r][c]) {
                value = std::max(value, dp[r+1][c]);
            }

            if (c < n - 1 && matrix[r][c+1] > matrix[r][c]) {
                value = std::max(value, dp[r][c+1]);
            }
            
            dp[r][c] += 1 + value;
        }
        
        int longest = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longest = std::max(longest, dp[i][j]);
            }
        }

        return longest;
    }
};

int main() {
    Solution s;

    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matrix;

    for (int i = 0; i < m; i++) {
        std::vector<int> line;

        for (int j = 0; j < n; j++) {
            int a;
            std::cin >> a;

            line.push_back(a);
        }

        matrix.push_back(line);
    }

    std::cout << s.longestIncreasingPath(matrix) << std::endl;

    return 0;
}
