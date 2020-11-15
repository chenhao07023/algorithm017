#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n+1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string p : dp[j]) {
                    for (string q : dp[i - j - 1]) {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }
		return dp[n];
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}
