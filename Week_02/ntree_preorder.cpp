#include <stdio.h>
#include <assert.h>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL) return {};
        vector<int> res;
        stack<Node*> ss;
        ss.push(root);
        Node* p = root;

        while (!ss.empty()) {
            p = ss.top();ss.pop();
            res.emplace_back(p->val);
            if (!p->children.empty()) {
                int size = p->children.size();
                for (int i=size-1; i>=0; i--) { 
                    Node *n = p->children[i];
                    ss.push(n);
                }
            }
        }
        return res;
    }
};

int main()
{
    

    Node n1(1);
    Node n2(3);
    Node n3(2);
    Node n4(4);
    n1.children.push_back(&n2);
    n1.children.push_back(&n3);
    n1.children.push_back(&n4);
    Node n5(5);
    Node n6(6);
    n2.children.push_back(&n5);
    n2.children.push_back(&n6);
    Solution s;
    vector<int> res = s.preorder(&n1);

    for(int i : res)
    {
        printf("%d ",i);
    }

    printf("\n");

    return 0;
}