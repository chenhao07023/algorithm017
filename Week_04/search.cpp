#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int low = 0;
    	int high = nums.size()-1;
    	while (low <= high) {
    		int mid = (low+high) / 2;
    		if (nums[mid] == target){
    			return mid;
    		}
    		if (nums[low] <= nums[mid]) {
    			if (nums[low] <= target && target < nums[mid]){
    				high = mid-1;
    			} else {
    				low = mid+1;
    			}
    		}
    		else{
    			if (nums[mid] < target && target <= nums[high]) {
    				low = mid+1;
    			} else {
    				high = mid-1;
    			}
    		}
    	}
    	return -1;
    }
};

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};

    assert(0 == Solution().search(nums, 4));
    assert(1 == Solution().search(nums, 5));
    assert(2 == Solution().search(nums, 6));
    assert(3 == Solution().search(nums, 7));
	assert(4 == Solution().search(nums, 0));
	assert(5 == Solution().search(nums, 1));
	assert(6 == Solution().search(nums, 2));

}