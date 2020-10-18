#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {

    	if (root == NULL) return 0;
    	int r = maxDepth(root->right);
    	int l = maxDepth(root->left);
        return r>l?(1+r):(1+l);
    }
};

int main()
{

}
