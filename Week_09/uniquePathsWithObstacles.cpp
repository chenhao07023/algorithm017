#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    	if (obstacleGrid.size() == 0) return 0;
    	if (obstacleGrid[0].size() == 0) return 0;

    	int n = obstacleGrid.size();
    	int m = obstacleGrid[0].size();

    	vector<vector<int>> dp(n, vector<int>(m, 0));

    	for (int i = 0; i < n; i++) {
    		if (obstacleGrid[i][0] == 1) {
    			break;
    		}
    		dp[i][0] = 1;
    	}
    		
        for (int i = 0; i < m; i++) {
        	if (obstacleGrid[0][i] == 1) {
    			break;
    		}
    		dp[0][i] = 1;
        }

    	for (int i = 1; i < n; i++) {
    		for (int j = 1; j < m; j++) {
    			if (obstacleGrid[i][j]== 1)
    			    dp[i][j] = 0;
    			else
    			    dp[i][j] = dp[i-1][j] + dp[i][j-1];
    			printf("i=%d j=%d dp=%d\n",i,j,dp[i][j]);
    		}
    	}


    	return dp[n-1][m-1];

    }
};



int main() {
	vector<int> n1 = {0,0,0};
	//vector<int> n2 = {0,1,0};
	//vector<int> n3 = {0,0,0};
	vector<vector<int>> m;
	m.push_back(n1);
	//m.push_back(n2);
	//m.push_back(n3);
	int s = Solution().uniquePathsWithObstacles(m);
	printf("ok! s=%d\n",s);
	return 0;
}
