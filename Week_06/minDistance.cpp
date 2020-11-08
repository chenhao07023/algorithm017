#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;

class Solution {
public:
	int min3(int n1,int n2, int n3) {
		return min(min(n1,n2), n3);
	}
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> dp(m*n, 0);

        for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] + 1;
        for (int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] + 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min3(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
            }
        }
        return dp[m][n];
    }
};


int main() {
	return 0;
}
