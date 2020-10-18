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
    bool isBSTUtil(struct TreeNode* node, long long min, long long max)  
    {  
      if (node==NULL)  
         return true; 

      if (node->val <= min || node->val >= max)  
         return false;  

      return isBSTUtil(node->left, min, node->val) && isBSTUtil(node->right, node->val, max); 
    }  

    bool isValidBST(struct TreeNode* root){
        return isBSTUtil(root, LONG_MIN, LONG_MAX);
    }

};

int main() {

    TreeNode* root = new TreeNode(10);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(15);

    root->left = n1;
    root->right = n2;

    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(20);

    n2->left = n3;
    n2->right = n3;

    Solution s;
    bool is = s.isValidBST(root);

    printf("is:%d\n", is);

}