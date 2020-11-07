#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.empty()) return 0;
    	if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

    	int pre = nums[1];
        int curr1 = max(nums[1], nums[2]);
    	for (int i = 3; i < nums.size(); ++i)
    	{
    		int tmp = pre;
    		pre = curr1;
    		curr1 = max(curr1, nums[i] + tmp);
    	}

        pre = nums[0];
        int curr2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size()-1; ++i)
        {
            int tmp = pre;
            pre = curr2;
            curr2 = max(curr2, nums[i] + tmp);
        }


    	return max(curr1,curr2);
    }
};

int main()
{
    vector<int> nums0 = {0,0};
    assert(0 == Solution().rob(nums0));

	vector<int> nums1 = {2,3,2};
	assert(3 == Solution().rob(nums1));

	vector<int> nums2 = {1,2,3,1};
	assert(4 == Solution().rob(nums2));

	printf("ok!\n");

    return 0;
}