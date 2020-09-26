#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        while (n > 0) {
            if (m == 0 || nums2[n-1] > nums1[m-1]) {
                nums1[last--] = nums2[--n];
            } else {
                nums1[last--] = nums1[--m];
            }
        }
    }
};


int main(int argc, char const *argv[]) {
	vector<int> nums1 = {1,2,3,0,0,0};
	vector<int> nums2 = {2,5,6};
	Solution s;
	s.merge(nums1,3,nums2,3);
	vector<int> exp =  {1,2,2,3,5,6};
	assert(nums1 == exp);
	return 0;
}