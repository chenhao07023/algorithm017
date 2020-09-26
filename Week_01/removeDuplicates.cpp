#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.empty()) return 0;
    	int p = 0;
    	int len = nums.size();
    	for (int q = p+1; q < len; q++)	{
    		if (nums[p] != nums[q]) {
    			p++;
    			nums[p] = nums[q];
    		}
    	}
    	return p+1;
    }
};

int main(int argc, char const *argv[]) {
	vector<int> nums = {1,1,2};
	Solution s;
	int len = s.removeDuplicates(nums);
	assert(len==2);
	assert(nums[1]==2);
	return 0;
}