#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

    	int len = s.size();
    	if (len < 2) return s;

    	int maxLen = 1;
        int begin = 0;

    	vector<vector<int>> dp(len, vector<int>(len, 0));

    	for (int i = 0; i < len; ++i) dp[i][i] = 1;

    	for (int j = 1; j < len; ++j) {
    		for (int i = 0; i < j; ++i) {
    			if (s[i] != s[j]) {
    				dp[i][j] = 0;
    			} else {
    				if (j - i < 3) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
    			}

    			if (dp[i][j] && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
    		}
    	}
    	return s.substr(begin,maxLen);
    }
};

int main() {
	Solution().longestPalindrome("babad");
	return 0;
}