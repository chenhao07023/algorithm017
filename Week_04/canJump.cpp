#include <string>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	

    bool canJump(vector<int>& nums) {
        int farest = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            if (i <= farest)
            {
                farest = max(farest, i+nums[i]);
                if (farest >= size-1) return true;
            }
        }

        return false;
    }
};

int main() {
	return 0;
}