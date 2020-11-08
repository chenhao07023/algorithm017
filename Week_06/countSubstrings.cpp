#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        
        int dp[s.size()][s.size()];
        memset(dp, 0, sizeof(dp));
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && ((j-i<2) || dp[i+1][j-1])) {
                    dp[i][j] = 1;
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
	return 0;
}
