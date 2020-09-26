#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end() - k % nums.size());
	    reverse(nums.end() - k % nums.size(), nums.end());
	    reverse(nums.begin(), nums.end());
	}
};


int main(int argc, char const *argv[]) {
	vector<int> nums = {1,2,3,4,5,6,7};
	Solution s;
	s.rotate(nums,3);
	vector<int> exp =  {5,6,7,1,2,3,4};
	assert(nums == exp);
	return 0;
}