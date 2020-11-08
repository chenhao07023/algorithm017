#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0];
    	int low = 0;
    	int high = nums.size()-1;

        if (nums[high] > nums[0]) return nums[0];

    	while (low <= high) {
            int mid = (low+high) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];

    		if (nums[mid] > nums[0]) {
    			low = mid+1;
    		} else {
    			high = mid-1;
    		}
    	}
    	return -1;
    }
};

int main() {

    vector<int> nums1 = {3,4,5,1,2};
    assert(1 == Solution().findMin(nums1));

    vector<int> nums2 = {4,5,6,7,0,1,2};
    assert(0 == Solution().findMin(nums2));

    vector<int> nums3 = {4};
    assert(4 == Solution().findMin(nums3));

}