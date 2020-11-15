#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};

        for (int i = 0; i < 9; i++) {
            for (size_t j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int n = board[i][j]-'0';
                int index = j/3 + (i/3)*3;
                if(row[i][n]) return false; 
                if(col[j][n]) return false;
                if(box[index][n]) return false;

                row[i][n] = 1;
                col[j][n] = 1;
                box[index][n] = 1;
            }   
        }
        return true;       
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}