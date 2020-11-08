#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;


class Solution {
public:
	int min3(int n1, int n2, int n3) {
		return min(min(n1, n2), n3);
	}
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        if (matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));

        int maxSide = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1;
                    maxSide = max(dp[i][j], maxSide);
                }
            }
        }
        return maxSide * maxSide;
    }
};

int main() {
	return 0;
}

