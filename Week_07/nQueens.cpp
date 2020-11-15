#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    void dfs(int row, int n, vector<vector<string>>& res, vector<string>& c, vector<int>& col, \
             vector<int>& dg, vector<int>& adg) 
    {
        if (row == n) {
            res.push_back(c);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!col[i] && !dg[row-i+n] && !adg[row+i])
            {
                col[i] = 1;
                dg[row-i+n] = 1;
                adg[row+i] = 1;
                c[row][i] = 'Q';

                dfs(row+1, n,  res, c, col, dg, adg);

                col[i] = 0;
                dg[row-i+n] = 0;
                adg[row+i] = 0;
                c[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> c(n, string(n, '.')); //临时结果
        vector<int> col(n,0);
        vector<int> dg(2*n,0);
        vector<int> adg(2*n,0);
        dfs(0, n,  res, c, col, dg, adg);
        return res;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}