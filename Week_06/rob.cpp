#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.empty()) return 0;
    	if (nums.size() == 1) return nums[0];

    	int pre = nums[0];
        int curr = max(nums[0], nums[1]);
    	for (int i = 2; i < nums.size(); ++i)
    	{
    		int tmp = pre;
    		pre = curr;
    		curr = max(curr, nums[i] + tmp);
    	}

    	return curr;
    }
};

int main()
{
	vector<int> nums1 = {1,2,3,1};
	assert(4 == Solution().rob(nums1));

	vector<int> nums2 = {2,7,9,3,1};
	assert(12 == Solution().rob(nums2));

	printf("ok!\n");

    return 0;
}