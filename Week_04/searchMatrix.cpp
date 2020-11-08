#include <string>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty()) return false;
        int r = matrix.size();
        int c = matrix[0].size();

        int left = 0;
        int right = r*c-1;

        while (left <= right)
        {
            int mid = (left+right) / 2;
            int curr = matrix[mid/c][mid%c];
            if (curr == target)
                return true;
            else if (curr < target) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main() {
	return 0;
}