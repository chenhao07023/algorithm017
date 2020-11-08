#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> dp(size, 0);

        int maxVal = 0;
        for(int i = 1; i < size; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0) {
                        dp[i] = dp[i] + dp[i - 2];
                    }
                } else if (dp[i - 1] > 0) {
                	int pre = i - dp[i - 1] - 1;
                    if (pre >= 0 && s[pre] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if ((pre-1) >= 0) {
                            dp[i] = dp[i] + dp[pre-1];
                        }
                    }
                }
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};


int main() {
	return 0;
}
