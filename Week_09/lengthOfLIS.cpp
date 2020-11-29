#include <stdio.h>
#include <assert.h>
#include <string>

using namespace std;

class Solution {
public:
    class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        int max = 1;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max = max(dp[i],max);
                }
            }
        }
        return max;
    }
};



int main() {
	return 0;
}