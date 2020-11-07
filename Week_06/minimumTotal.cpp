#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

    	for (int i = triangle.size()-2; i >= 0; i--)
    	{
    		for (int j = 0; j < triangle[i].size(); j++)
    		{
    			triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
    		}
    	}

        return triangle[0][0];
    }
};

/*
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
 */
int main()
{
	vector<int> v1 = {2};
	vector<int> v2 = {3,4};
	vector<int> v3 = {6,5,7};
	vector<int> v4 = {4,1,8,3};
	vector<vector<int>> triangle;
	triangle.push_back(v1);
	triangle.push_back(v2);
	triangle.push_back(v3);
	triangle.push_back(v4);

	assert(11 == Solution().minimumTotal(triangle));
	return 0;
}