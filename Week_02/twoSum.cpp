#include <stdio.h>
#include <assert.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hs;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto itr = hs.find(target-nums[i]);
            if (itr != hs.end()) {
                return {itr->second, i};
            }
            hs[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    return 0;
}

