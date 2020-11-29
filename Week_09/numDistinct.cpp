#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty()) return 0;
        if(t.empty()) return s.size();

        int n = s.size() + 1;
        int m = t.size() + 1;
        vector<vector<unsigned long>> dp(m, vector<unsigned long>(n,0));
        for(int i = 0; i < n ; i++) 
            dp[0][i] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = i; j < n; j++) {
                if(t[i-1] == s[j-1])
                    dp[i][j] = dp[i][j - 1] +  dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};



int main() {

	return 0;
}
