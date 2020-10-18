#include <stdio.h>
#include <assert.h>
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
    int minDepth(TreeNode* root) {

    	if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
    	int r = minDepth(root->right);
    	int l = minDepth(root->left);
        if (root->left == NULL || root->right == NULL) return l+r+1;
        return r<l?(1+r):(1+l);
    }
};

int main() {

    TreeNode* root = new TreeNode(2);
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(6);

    root->right = n1;
    n1->right = n2;
    n2->right = n3;
    n3->right = n4;

    Solution s;
    assert(5==s.minDepth(root)) ;

}